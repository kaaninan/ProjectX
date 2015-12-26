/*
 *   ArbotixPro.cpp
 *
 *   Author: ROBOTIS
 *
 */
#include <stdio.h>
#include "FSR.h"
#include "ArbotixPro.h"
#include "MotionStatus.h"
#include <stdlib.h>

#include <cstdlib>
#include <deque>
#include <iostream>
#include "boost/bind.hpp"
#include "boost/asio.hpp"
#include "boost/thread/thread.hpp"
#include "chat_message.hpp"

//// JSON
//#include "rapidjson/document.h"
//#include "rapidjson/writer.h"
//#include "rapidjson/stringbuffer.h"
//#include <iostream>


using namespace Robot;

using boost::asio::ip::tcp;

typedef std::deque<chat_message> chat_message_queue;


#define ID					(2)
#define LENGTH				(3)
#define INSTRUCTION			(4)
#define ERRBIT				(4)
#define PARAMETER			(5)
#define DEFAULT_BAUDNUMBER	(1)

#define INST_PING			(1)
#define INST_READ			(2)
#define INST_WRITE			(3)
#define INST_REG_WRITE		(4)
#define INST_ACTION			(5)
#define INST_RESET			(6)
#define INST_SYNC_WRITE		(131)   // 0x83
#define INST_BULK_READ      (146)   // 0x92

//MySocket mySocket;

class chat_client
{
public:
    chat_client(boost::asio::io_service& io_service,
                tcp::resolver::iterator endpoint_iterator)
    : io_service_(io_service),
    socket_(io_service)
    {
        boost::asio::async_connect(socket_, endpoint_iterator,
                                   boost::bind(&chat_client::handle_connect, this,
                                               boost::asio::placeholders::error));
    }
    
    void write(const chat_message& msg)
    {
        io_service_.post(boost::bind(&chat_client::do_write, this, msg));
    }
    
    void close()
    {
        io_service_.post(boost::bind(&chat_client::do_close, this));
    }
    
private:
    
    void handle_connect(const boost::system::error_code& error)
    {
        if (!error)
        {
            boost::asio::async_read(socket_,
                                    boost::asio::buffer(read_msg_.data(), chat_message::header_length),
                                    boost::bind(&chat_client::handle_read_header, this,
                                                boost::asio::placeholders::error));
        }
    }
    
    void handle_read_header(const boost::system::error_code& error)
    {
        if (!error && read_msg_.decode_header())
        {
            boost::asio::async_read(socket_,
                                    boost::asio::buffer(read_msg_.body(), read_msg_.body_length()),
                                    boost::bind(&chat_client::handle_read_body, this,
                                                boost::asio::placeholders::error));
        }
        else
        {
            do_close();
        }
    }
    
    void handle_read_body(const boost::system::error_code& error)
    {
        if (!error)
        {
            std::cout.write(read_msg_.body(), read_msg_.body_length());
            std::cout << "\n";
            boost::asio::async_read(socket_,
                                    boost::asio::buffer(read_msg_.data(), chat_message::header_length),
                                    boost::bind(&chat_client::handle_read_header, this,
                                                boost::asio::placeholders::error));
        }
        else
        {
            do_close();
        }
    }
    
    void do_write(chat_message msg)
    {
        bool write_in_progress = !write_msgs_.empty();
        write_msgs_.push_back(msg);
        if (!write_in_progress)
        {
            boost::asio::async_write(socket_,
                                     boost::asio::buffer(write_msgs_.front().data(),
                                                         write_msgs_.front().length()),
                                     boost::bind(&chat_client::handle_write, this,
                                                 boost::asio::placeholders::error));
        }
    }
    
    void handle_write(const boost::system::error_code& error)
    {
        if (!error)
        {
            write_msgs_.pop_front();
            if (!write_msgs_.empty())
            {
                boost::asio::async_write(socket_,
                                         boost::asio::buffer(write_msgs_.front().data(),
                                                             write_msgs_.front().length()),
                                         boost::bind(&chat_client::handle_write, this,
                                                     boost::asio::placeholders::error));
            }
        }
        else
        {
            do_close();
        }
    }
    
    void do_close()
    {
        socket_.close();
    }
    
private:
    boost::asio::io_service& io_service_;
    tcp::socket socket_;
    chat_message read_msg_;
    chat_message_queue write_msgs_;
};



BulkReadData::BulkReadData() :
	start_address(0),
	length(0),
	error(-1)
{
	for (int i = 0; i < AXDXL::MAXNUM_ADDRESS; i++)
		table[i] = 0;
}

int BulkReadData::ReadByte(int address)
{
	if (address >= start_address && address < (start_address + length))
		return (int)table[address];

	return 0;
}

int BulkReadData::ReadWord(int address)
{
	if (address >= start_address && address < (start_address + length))
		return ArbotixPro::MakeWord(table[address], table[address + 1]);

	return 0;
}


ArbotixPro::ArbotixPro(PlatformArbotixPro *platform)
{
	m_Platform = platform;
	DEBUG_PRINT = false;
	m_DelayedWords = 0;
	m_bIncludeTempData = false;
	m_BulkReadTxPacket[LENGTH] = 0;
    
    
    try
    {
        
        tcp::iostream s("127.0.0.1", "8225");
        if (!s)
        {
            std::cout << "Unable to connect: " << s.error().message() << std::endl;
        }
        
        std::string line;
        std::getline(s, line);
        std::cout << line << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    
    
    
}

ArbotixPro::~ArbotixPro()
{
	Disconnect();
	exit(0);
}


int ArbotixPro::TxRxPacket(unsigned char *txpacket, unsigned char *rxpacket, int priority)
{

	int res = SUCCESS;
	int length = txpacket[LENGTH] + 4;

	txpacket[0] = 0xFF;
	txpacket[1] = 0xFF;

	if (DEBUG_PRINT == true)
		{
			fprintf(stderr, "\nTX: ");
			for (int n = 0; n < length; n++)
				fprintf(stderr, "%.2X ", txpacket[n]);

			fprintf(stderr, "INST: ");
			switch (txpacket[INSTRUCTION])
				{
				case INST_PING:
					fprintf(stderr, "PING\n");
					break;

				case INST_READ:
					fprintf(stderr, "READ\n");
					break;

				case INST_WRITE:
					fprintf(stderr, "WRITE\n");
					break;

				case INST_REG_WRITE:
					fprintf(stderr, "REG_WRITE\n");
					break;

				case INST_ACTION:
					fprintf(stderr, "ACTION\n");
					break;

				case INST_RESET:
					fprintf(stderr, "RESET\n");
					break;

				case INST_SYNC_WRITE:
					fprintf(stderr, "SYNC_WRITE\n");
					break;

				case INST_BULK_READ:
					fprintf(stderr, "BULK_READ\n");
					break;

				default:
					fprintf(stderr, "UNKNOWN\n");
					break;
				}
		}

    

    
    
    if (txpacket[ID] != ID_BROADCAST){
        
        if (txpacket[PARAMETER] == AXDXL::P_PRESENT_POSITION_L) {
            // READ - WORD
            rxpacket[PARAMETER] = 0x2;
            rxpacket[PARAMETER + 1] = 0x3;
        }
        
        else if (txpacket[PARAMETER] == AXDXL::P_TORQUE_LIMIT_L) {
            // WRITE - WORD
        }
        
        else if (txpacket[PARAMETER] == AXDXL::P_GOAL_POSITION_L) {
            // READ - WORD
            rxpacket[PARAMETER] = 0x3;
            rxpacket[PARAMETER + 1] = 0x3;
        }
        
        else if (txpacket[PARAMETER] == AXDXL::P_TORQUE_ENABLE) {
            if (txpacket[INSTRUCTION] == INST_WRITE) {
                // WRITE - BYTE
            }else{
                // READ - BYTE
                rxpacket[PARAMETER] = 0x0;
            }
        }
        
        else if (txpacket[PARAMETER] == AXDXL::P_PRESENT_TEMPERATURE) {
            // READ - WORD
        }
        
        
        
        // READ - WORD
        else if (txpacket[PARAMETER] == ArbotixPro::P_ACCEL_X_L) {
            
        }
        else if (txpacket[PARAMETER] == ArbotixPro::P_ACCEL_Y_L) {
            
        }
        else if (txpacket[PARAMETER] == ArbotixPro::P_ACCEL_Z_L) {
            
        }
        else if (txpacket[PARAMETER] == ArbotixPro::P_GYRO_Y_L) {
            
        }
        else if (txpacket[PARAMETER] == ArbotixPro::P_GYRO_X_L) {
            
        }
        
        
        
        else{
            printf("UNKNOWN 1 %d\n", txpacket[PARAMETER]);
        }
        
        
        
        
        
    }
    
    else if (txpacket[INSTRUCTION] == INST_BULK_READ){
        printf("Bulk Read \n");
    }
    
    else if(txpacket[ID] == ID_BROADCAST){
        
        if(txpacket[INSTRUCTION] == INST_SYNC_WRITE){
            
            int id, pos, cw, ccw;

            std::string yaz;

                
            for(int i = 7; i < length; i++){
                id = txpacket[i++];
                cw = txpacket[i++];
                ccw = txpacket[i++];
                pos = MakeWord(txpacket[i++], txpacket[i]);
                    
                    
                //                printf("ID: %d \n", id);
                //                printf("CW: %d \n", cw);
                //                printf("CCW: %d \n", ccw);
                //                printf("POS: %d \n \n", pos);
                    

                if (id != 0) {
                    std::ostringstream oss;
                    oss << id << " - " << pos << std::endl;
                    yaz += oss.str();
                }
                    
            }
            
            outfile.open("/home/rock/test.txt", std::ios_base::app);
            outfile << yaz << std::endl;
            outfile.close();
            
        }
        
        else if(txpacket[PARAMETER] == AXDXL::P_TORQUE_LIMIT_L){
            // WRITE
        }
        else if(txpacket[PARAMETER] == AXDXL::P_MOVING_SPEED_L){
            // WRITE - WORD
            // Default: 0
        }
        else{
            printf("UNKNOWN 2 \n");
        }
    }

    else{
        printf("UNKNOWN 3 \n");
    }
    
    
    
//	if (DEBUG_PRINT == true)
//		{
//			fprintf(stderr, "Time:%.2fms  ", m_Platform->GetPacketTime());
//			fprintf(stderr, "RETURN: ");
//			switch (res)
//				{
//				case SUCCESS:
//					fprintf(stderr, "SUCCESS\n");
//					break;
//
//				case TX_CORRUPT:
//					fprintf(stderr, "TX_CORRUPT\n");
//					break;
//
//				case TX_FAIL:
//					fprintf(stderr, "TX_FAIL\n");
//					break;
//
//				case RX_FAIL:
//					fprintf(stderr, "RX_FAIL\n");
//					break;
//
//				case RX_TIMEOUT:
//					fprintf(stderr, "RX_TIMEOUT\n");
//					break;
//
//				case RX_CORRUPT:
//					fprintf(stderr, "RX_CORRUPT\n");
//					break;
//
//				default:
//					fprintf(stderr, "UNKNOWN\n");
//					break;
//				}
//		}

	return res;
}

unsigned char ArbotixPro::CalculateChecksum(unsigned char *packet)
{
	unsigned char checksum = 0x00;
	for (int i = 2; i < packet[LENGTH] + 3; i++ )
		checksum += packet[i];
	return (~checksum);
}

void ArbotixPro::MakeBulkReadPacket()
{
	int number = 0;

	m_BulkReadTxPacket[ID]              = (unsigned char)ID_BROADCAST;
	m_BulkReadTxPacket[INSTRUCTION]     = INST_BULK_READ;
	m_BulkReadTxPacket[PARAMETER]       = (unsigned char)0x0;

	//if(Ping(ArbotixPro::ID_CM, 0) == SUCCESS)
	{
		m_BulkReadTxPacket[PARAMETER + 3 * number + 1] = 30;
		m_BulkReadTxPacket[PARAMETER + 3 * number + 2] = ArbotixPro::ID_CM;
		m_BulkReadTxPacket[PARAMETER + 3 * number + 3] = ArbotixPro::P_DXL_POWER;
		number++;
	}

//    for(int id = 1; id < JointData::NUMBER_OF_JOINTS; id++)
//    {
//        if(MotionStatus::m_CurrentJoints.GetEnable(id))
//        {
//            m_BulkReadTxPacket[PARAMETER+3*number+1] = 2;   // length
//            m_BulkReadTxPacket[PARAMETER+3*number+2] = id;  // id
//            m_BulkReadTxPacket[PARAMETER+3*number+3] = AXDXL::P_PRESENT_POSITION_L; // start address
//            number++;
//        }
//    }
	if (m_bIncludeTempData == true)
		{
			for (int id = JointData::ID_MIN; id <= JointData::ID_MAX; id++)
				{
					if (MotionStatus::m_CurrentJoints.GetEnable(id))
						{
							m_BulkReadTxPacket[PARAMETER + 3 * number + 1] = 1; // length
							m_BulkReadTxPacket[PARAMETER + 3 * number + 2] = id; // id
							m_BulkReadTxPacket[PARAMETER + 3 * number + 3] = AXDXL::P_PRESENT_TEMPERATURE; // start address
							number++;
						}
				}
		}
	/*
	if(Ping(FSR::ID_L_FSR, 0) == SUCCESS)
	{
	m_BulkReadTxPacket[PARAMETER+3*number+1] = 2;               // length
	m_BulkReadTxPacket[PARAMETER+3*number+2] = FSR::ID_L_FSR;   // id
	m_BulkReadTxPacket[PARAMETER+3*number+3] = FSR::P_FSR_X;    // start address
	number++;
	}

	if(Ping(FSR::ID_R_FSR, 0) == SUCCESS)
	{
	m_BulkReadTxPacket[PARAMETER+3*number+1] = 2;               // length
	m_BulkReadTxPacket[PARAMETER+3*number+2] = FSR::ID_R_FSR;   // id
	m_BulkReadTxPacket[PARAMETER+3*number+3] = FSR::P_FSR_X;    // start address
	number++;
	}
	*/
	//fprintf(stderr, "NUMBER : %d \n", number);

	m_BulkReadTxPacket[LENGTH]          = (number * 3) + 3;
}

int ArbotixPro::BulkRead()
{
	unsigned char rxpacket[MAXNUM_RXPARAM + 10] = {0, };

	if (m_BulkReadTxPacket[LENGTH] != 0)
		return TxRxPacket(m_BulkReadTxPacket, rxpacket, 0);
	else
		{
			MakeBulkReadPacket();
			return TX_FAIL;
		}
}

int ArbotixPro::SyncWrite(int start_addr, int each_length, int number, int *pParam)
{
    
	unsigned char txpacket[MAXNUM_TXPARAM + 10] = {0, };
	unsigned char rxpacket[MAXNUM_RXPARAM + 10] = {0, };
	int n;

	txpacket[ID]                = (unsigned char)ID_BROADCAST;
	txpacket[INSTRUCTION]       = INST_SYNC_WRITE;
	txpacket[PARAMETER]			= (unsigned char)start_addr;
	txpacket[PARAMETER + 1]		= (unsigned char)(each_length - 1);
	for (n = 0; n < (number * each_length); n++)
		txpacket[PARAMETER + 2 + n]   = (unsigned char)pParam[n];
	txpacket[LENGTH]            = n + 4;

	return TxRxPacket(txpacket, rxpacket, 0);
}

bool ArbotixPro::Connect()
{


	return DXLPowerOn();
}

bool ArbotixPro::ChangeBaud(int baud)
{
	

	return DXLPowerOn();
}

bool ArbotixPro::DXLPowerOn(bool state)
{
	return true;
}

void ArbotixPro::Disconnect()
{
// do action upon disconnect
    fprintf(stderr, "DISCONNECT Arbotix Pro");
}

int ArbotixPro::WriteByte(int address, int value, int *error)
{
	return WriteByte(ID_CM, address, value, error);
}

int ArbotixPro::WriteWord(int address, int value, int *error)
{
	return WriteWord(ID_CM, address, value, error);
}

void ArbotixPro::WriteWordDelayed(int address, int value)
{
	if (m_DelayedWords > 9) return;

	m_DelayedWord[m_DelayedWords] = value;
	m_DelayedAddress[m_DelayedWords] = address;
	m_DelayedWords++;
	return;
}

int ArbotixPro::Ping(int id, int *error)
{
	unsigned char txpacket[MAXNUM_TXPARAM + 10] = {0, };
	unsigned char rxpacket[MAXNUM_RXPARAM + 10] = {0, };
	int result;

	txpacket[ID]           = (unsigned char)id;
	txpacket[INSTRUCTION]  = INST_PING;
	txpacket[LENGTH]       = 2;

	result = TxRxPacket(txpacket, rxpacket, 2);
	if (result == SUCCESS && txpacket[ID] != ID_BROADCAST)
		{
			if (error != 0)
				*error = (int)rxpacket[ERRBIT];
		}

	return result;
}

int ArbotixPro::ReadByte(int id, int address, int *pValue, int *error)
{
	unsigned char txpacket[MAXNUM_TXPARAM + 10] = {0, };
	unsigned char rxpacket[MAXNUM_RXPARAM + 10] = {0, };
	int result;

	txpacket[ID]           = (unsigned char)id;
	txpacket[INSTRUCTION]  = INST_READ;
	txpacket[PARAMETER]    = (unsigned char)address;
	txpacket[PARAMETER + 1]  = 1;
	txpacket[LENGTH]       = 4;

	result = TxRxPacket(txpacket, rxpacket, 2);
	if (result == SUCCESS)
		{
			*pValue = (int)rxpacket[PARAMETER];
			if (error != 0)
				*error = (int)rxpacket[ERRBIT];
		}

	return result;
}

int ArbotixPro::ReadWord(int id, int address, int *pValue, int *error)
{
	unsigned char txpacket[MAXNUM_TXPARAM + 10] = {0, };
	unsigned char rxpacket[MAXNUM_RXPARAM + 10] = {0, };
	int result;

	txpacket[ID]           = (unsigned char)id;
	txpacket[INSTRUCTION]  = INST_READ;
	txpacket[PARAMETER]    = (unsigned char)address;
	txpacket[PARAMETER + 1]  = 2;
	txpacket[LENGTH]       = 4;

	result = TxRxPacket(txpacket, rxpacket, 2);
	if (result == SUCCESS)
		{
			*pValue = MakeWord((int)rxpacket[PARAMETER], (int)rxpacket[PARAMETER + 1]);

			if (error != 0)
				*error = (int)rxpacket[ERRBIT];
		}

	return result;
}

int ArbotixPro::ReadTable(int id, int start_addr, int end_addr, unsigned char *table, int *error)
{
	unsigned char txpacket[MAXNUM_TXPARAM + 10] = {0, };
	unsigned char rxpacket[MAXNUM_RXPARAM + 10] = {0, };
	int result;
	int length = end_addr - start_addr + 1;

	txpacket[ID]           = (unsigned char)id;
	txpacket[INSTRUCTION]  = INST_READ;
	txpacket[PARAMETER]    = (unsigned char)start_addr;
	txpacket[PARAMETER + 1]  = (unsigned char)length;
	txpacket[LENGTH]       = 4;

	result = TxRxPacket(txpacket, rxpacket, 1);
	if (result == SUCCESS)
		{
			for (int i = 0; i < length; i++)
				table[start_addr + i] = rxpacket[PARAMETER + i];

			if (error != 0)
				*error = (int)rxpacket[ERRBIT];
		}

	return result;
}

int ArbotixPro::WriteByte(int id, int address, int value, int *error)
{
	unsigned char txpacket[MAXNUM_TXPARAM + 10] = {0, };
	unsigned char rxpacket[MAXNUM_RXPARAM + 10] = {0, };
	int result;

	txpacket[ID]           = (unsigned char)id;
	txpacket[INSTRUCTION]  = INST_WRITE;
	txpacket[PARAMETER]    = (unsigned char)address;
	txpacket[PARAMETER + 1]  = (unsigned char)value;
	txpacket[LENGTH]       = 4;

	result = TxRxPacket(txpacket, rxpacket, 2);
	if (result == SUCCESS && id != ID_BROADCAST)
		{
			if (error != 0)
				*error = (int)rxpacket[ERRBIT];
		}

	return result;
}

int ArbotixPro::WriteWord(int id, int address, int value, int *error)
{
	unsigned char txpacket[MAXNUM_TXPARAM + 10] = {0, };
	unsigned char rxpacket[MAXNUM_RXPARAM + 10] = {0, };
	int result;

	txpacket[ID]           = (unsigned char)id;
	txpacket[INSTRUCTION]  = INST_WRITE;
	txpacket[PARAMETER]    = (unsigned char)address;
	txpacket[PARAMETER + 1]  = (unsigned char)GetLowByte(value);
	txpacket[PARAMETER + 2]  = (unsigned char)GetHighByte(value);
	txpacket[LENGTH]       = 5;

	result = TxRxPacket(txpacket, rxpacket, 2);
	if (result == SUCCESS && id != ID_BROADCAST)
		{
			if (error != 0)
				*error = (int)rxpacket[ERRBIT];
		}

	return result;
}

int ArbotixPro::MakeWord(int lowbyte, int highbyte)
{
	unsigned short word;

	word = highbyte;
	word = word << 8;
	word = word + lowbyte;

	return (int)word;
}

int ArbotixPro::GetLowByte(int word)
{
	unsigned short temp;
	temp = word & 0xff;
	return (int)temp;
}

int ArbotixPro::GetHighByte(int word)
{
	unsigned short temp;
	temp = word & 0xff00;
	return (int)(temp >> 8);
}

