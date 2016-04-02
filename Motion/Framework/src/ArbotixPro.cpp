#include <stdio.h>
#include "FSR.h"
#include "ArbotixPro.h"
#include "MotionStatus.h"
#include <stdlib.h>

#include <cstdlib>
#include <deque>
#include <iostream>
 #include <string>
#include "boost/bind.hpp"
#include "boost/asio.hpp"
#include "boost/thread/thread.hpp"
 #include <fstream>

using namespace Robot;

using boost::asio::ip::tcp;


#define PORT_NO             "8302"

#define ID                  (2)
#define LENGTH              (3)
#define INSTRUCTION         (4)
#define ERRBIT              (4)
#define PARAMETER           (5)
#define DEFAULT_BAUDNUMBER  (1)

#define INST_PING           (1)
#define INST_READ           (2)
#define INST_WRITE          (3)
#define INST_REG_WRITE      (4)
#define INST_ACTION         (5)
#define INST_RESET          (6)
#define INST_SYNC_WRITE     (131)   // 0x83
#define INST_BULK_READ      (146)   // 0x92



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

    played = 0;
    
    // BOOST START
    
    int devam = 1;
    int a = 0;
    
    try{
        while (devam) {
            tcp::iostream s("127.0.0.1", PORT_NO);
            if (!s){ std::cout << "Unable to connect: " << s.error().message() << std::endl;}
            
            else if( a == 0){
                
                // GELEN
                std::string line;
                std::getline(s, line);
                
                if (line == "OK ") {
                    // std::cout << "OK" << std::endl;
                    break;
                }else{
                    // std::cout << line << std::endl;
                }
                
                a = 1;
            }
            
            else{
                // GIDEN
                s << "STARTING";
                a = 0;
            }
        }
    }catch (std::exception& e){ std::cout << "Exception: " << e.what() << std::endl; }

    // BOOST END
    
    
}

ArbotixPro::~ArbotixPro(){
    
    // BOOST START
    try{
        tcp::iostream s("127.0.0.1", PORT_NO);
        if (!s){ std::cout << "Unable to connect: " << s.error().message() << std::endl; }
        s << "END";
    }catch (std::exception& e){
        std::cout << "Exception: " << e.what() << std::endl;
    }
    // BOOST END

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

            // BOOST START
            int devam = 1;
            int a = 1;
            try{
                while (devam) {
                    tcp::iostream s("127.0.0.1", PORT_NO);
                    if (!s){ std::cout << "Unable to connect: " << s.error().message() << std::endl; }
                    
                    else if(a == 0){
                        
                        // GELEN
                        std::string line;
                        std::getline(s, line);
                        
                        // std::cout << line << std::endl;
                        
                        char parse[1024];
                        strcpy(parse, line.c_str());
                        
                        if (parse[0] == 'C' && parse[1] == 'P' && parse[2] == 'R' && parse[3] == 'E' &&
                            parse[4] == 'P' && parse[5] == 'O' && parse[6] == 'S') {
                            
                            //std::cout << "Cevap Pos: "<< parse[14] << parse[15] << parse[16] << std::endl;
                            
                            // Donustur
                            std::ostringstream oss2;
                            oss2 << parse[14] << parse[15] << parse[16];
                            std::string temp2 = oss2.str();
                            char id_temp[4];
                            strcpy(id_temp, temp2.c_str());
                            int id = atoi(id_temp);
                            
                            rxpacket[PARAMETER] = GetLowByte(id);
                            rxpacket[PARAMETER + 1] = GetHighByte(id);
                            
                            break;
                        }
                        
                        devam = 0;
                        a = 1;
                        
                    }else{
                        
                        // GIDEN
                        if(txpacket[ID] < 10) s << "S" << "PREPOS0" << (int)txpacket[ID] << "0000" << "0000";
                        else{ s << "S" << "PREPOS" << (int)txpacket[ID] << "0000" << "0000"; }
                        a = 0;
                    }
                }
            }
            catch (std::exception& e){std::cout << "Exception: " << e.what() << std::endl;}
            // BOOST END
            
        }

        else if (txpacket[PARAMETER] == AXDXL::P_TORQUE_LIMIT_L) {
            // WRITE - WORD
        }
        
        else if (txpacket[PARAMETER] == AXDXL::P_GOAL_POSITION_L) {

            if (txpacket[INSTRUCTION] == INST_WRITE) {
                // WRITE - WORD

                // BOOST START
                int devam = 1;
                int a = 1;
                try{
                    while (devam) {
                        tcp::iostream s("127.0.0.1", PORT_NO);
                        if (!s){ std::cout << "Unable to connect: " << s.error().message() << std::endl; }
                        
                        else if(a == 0){
                            
                            // GELEN
                            std::string line;
                            std::getline(s, line);
                            
                            // std::cout << line << std::endl;
                            
                            char parse[1024];
                            strcpy(parse, line.c_str());
                            
                            if (parse[0] == 'C' && parse[1] == 'G' && parse[2] == 'O' && parse[3] == 'A' &&
                                parse[4] == 'L' && parse[5] == 'P' && parse[6] == 'W') {
                                
                                break;
                            }
                            
                            devam = 0;
                            a = 1;
                            
                        }else{
                            
                            // GIDEN

                            // Basamak icin ayar cek
                            int goal_pos = MakeWord(txpacket[PARAMETER + 1], txpacket[PARAMETER + 2]), sart = 0;
                            if(goal_pos < 10){ sart = 1; }
                            else if(goal_pos < 100){ sart = 2; }
                            else { sart = 3; }


                            if(txpacket[ID] < 10){
                                if(sart == 1){
                                    s << "S" << "GOALPW0" << (int)txpacket[ID] << "000" << goal_pos << "0000";
                                }else if(sart == 2){
                                    s << "S" << "GOALPW0" << (int)txpacket[ID] << "00" << goal_pos << "0000";
                                }else if(sart == 3){
                                    s << "S" << "GOALPW0" << (int)txpacket[ID] << "0" << goal_pos << "0000";
                                }
                            }
                            else{
                                if(sart == 1){
                                    s << "S" << "GOALPW" << (int)txpacket[ID] << "000" << goal_pos << "0000";
                                }else if(sart == 2){
                                    s << "S" << "GOALPW" << (int)txpacket[ID] << "00" << goal_pos << "0000";
                                }else if(sart == 3){
                                    s << "S" << "GOALPW" << (int)txpacket[ID] << "0" << goal_pos << "0000";
                                }
                            }
                            a = 0;
                        }
                    }
                }catch (std::exception& e){ std::cout << "Exception: " << e.what() << std::endl; }
                // BOOST END


            }else{
                // READ - WORD

                // BOOST START
                int devam = 1;
                int a = 1;
                try{
                    while (devam) {
                        tcp::iostream s("127.0.0.1", PORT_NO);
                        if (!s){ std::cout << "Unable to connect: " << s.error().message() << std::endl; }
                        
                        else if(a == 0){
                            
                            // GELEN
                            std::string line;
                            std::getline(s, line);
                            
                            // std::cout << line << std::endl;
                            
                            char parse[1024];
                            strcpy(parse, line.c_str());
                            
                            if (parse[0] == 'C' && parse[1] == 'G' && parse[2] == 'O' && parse[3] == 'A' &&
                                parse[4] == 'L' && parse[5] == 'P' && parse[6] == 'S') {
                                
                                // std::cout << "Cevap Pos: "<< parse[14] << parse[15] << parse[16] << std::endl;
                                
                                // Donustur
                                std::ostringstream oss2;
                                oss2 << parse[14] << parse[15] << parse[16];
                                std::string temp2 = oss2.str();
                                char id_temp[4];
                                strcpy(id_temp, temp2.c_str());
                                int id = atoi(id_temp);
                                
                                rxpacket[PARAMETER] = GetLowByte(id);
                                rxpacket[PARAMETER + 1] = GetHighByte(id);
                                
                                break;
                            }
                            
                            devam = 0;
                            a = 1;
                            
                        }else{
                            
                            // GIDEN
                            if(txpacket[ID] < 10) s << "S" << "GOALPS0" << (int)txpacket[ID] << "0000" << "0000";
                            else{ s << "S" << "GOALPS" << (int)txpacket[ID] << "0000" << "0000"; }
                            a = 0;
                        }
                    }
                }catch (std::exception& e){ std::cout << "Exception: " << e.what() << std::endl; }
                // BOOST END
            }
        }
        

        else if (txpacket[PARAMETER] == AXDXL::P_TORQUE_ENABLE) {

            if (txpacket[INSTRUCTION] == INST_WRITE) {
                // WRITE - BYTE

                // BOOST START
                int devam = 1;
                int a = 1;
                try{
                    while (devam) {
                        tcp::iostream s("127.0.0.1", PORT_NO);
                        if (!s){ std::cout << "Unable to connect: " << s.error().message() << std::endl; }
                        
                        else if(a == 0){
                            
                            // GELEN
                            std::string line;
                            std::getline(s, line);
                            
                            char parse[1024];
                            strcpy(parse, line.c_str());
                            
                            if (parse[0] == 'C' && parse[1] == 'T' && parse[2] == 'O' && parse[3] == 'R' &&
                                parse[4] == 'Q' && parse[5] == 'E' && parse[6] == 'W') {
                                
                                break;
                            }
                            
                            devam = 0;
                            a = 1;
                            
                        }else{

                            // std::cout << "ArbotixPRO Write Torque - Motor ID: " << (int)txpacket[ID] << " -> " <<(int)txpacket[PARAMETER+1] << std::endl;
                            
                            // GIDEN
                            if(txpacket[ID] < 10) s << "S" << "TORQEW0" << (int)txpacket[ID] << "000" << (int)txpacket[PARAMETER+1] << "0000";
                            else{ s << "S" << "TORQEW" << (int)txpacket[ID] << "000" << (int)txpacket[PARAMETER+1] << "0000"; }
                            a = 0;

                        }
                    }
                }
                catch (std::exception& e){
                    std::cout << "Exception: " << e.what() << std::endl;
                }
                // BOOST END

            }else{
                // READ - BYTE
                
                // BOOST START
                
                int devam = 1;
                int a = 1;
                
                try{
                    while (devam) {
                        tcp::iostream s("127.0.0.1", PORT_NO);
                        if (!s){
                            std::cout << "Unable to connect: " << s.error().message() << std::endl;
                        }
                        
                        else if( a == 0){
                            std::string line;
                            std::getline(s, line);
                            
                            if (line == "HATA ") {
                                // std::cout << "HATA" << std::endl;
                                break;
                                
                            }else{
                                // std::cout << line << std::endl;
                                
                                char parse[100];
                                strcpy(parse, line.c_str());
                                
                                if (parse[0] == 'C' && parse[1] == 'T' && parse[2] == 'O' && parse[3] == 'R' &&
                                    parse[4] == 'Q' && parse[5] == 'E' && parse[6] == 'R') {
                                    
                                    // std::cout << "Cevap Torq: " << parse[16] << std::endl;
                                    
                                    if(parse[16] == '0'){
                                        // std::cout << "NO TORQUE" << std::endl;
                                        rxpacket[PARAMETER] = 0x0;
                                    }
                                    else if(parse[16] == '1'){
                                        // std::cout << "OK TORQUE" << std::endl;
                                        rxpacket[PARAMETER] = 0x1;
                                    }
                                    
                                    break;
                                    
                                }
                                
                                devam = 0;
                            }
                            
                            a = 1;
                        }
                        
                        else{
                            std::ostringstream oss;
                            if(txpacket[ID] < 10){
                                oss << "S" << "TORQER0" << (int)txpacket[ID] << "000" << played << "0000";
                            }else{
                                oss << "S" << "TORQER" << (int)txpacket[ID] << "000" << played << "0000";
                            }

                            played = 0;
                            
                            std::string gelen = oss.str();
                            s << gelen;
                            
                            a = 0;
                        }
                    }
                }catch (std::exception& e){
                    std::cout << "Exception: " << e.what() << std::endl;
                }
                
                // BOOST END
                
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
                    
                    
                // printf("ID: %d \n", id);
                // printf("CW: %d \n", cw);
                // printf("CCW: %d \n", ccw);
                printf("POS: %d \n \n", pos);

                if(id != 0){
                    played = 1;
                    std::ofstream myfile;
                    myfile.open ("/home/kaaninan/Motor_Test.txt", std::ios_base::app);
                    myfile << "ID:" << id << ":POS:" << pos << ":\n";
                    myfile.close();
                }
            




                // BOOST START
                // int devam = 1;
                // int a = 1;
                // try{
                //     while (devam) {
                //         tcp::iostream s("127.0.0.1", PORT_NO);
                //         if (!s){ std::cout << "Unable to connect: " << s.error().message() << std::endl; }
                        
                //         else if(a == 0){
                            
                //             // GELEN
                //             std::string line;
                //             std::getline(s, line);
                            
                //             // std::cout << line << std::endl;
                            
                //             char parse[1024];
                //             strcpy(parse, line.c_str());
                            
                //             if (parse[0] == 'C' && parse[1] == 'G' && parse[2] == 'O' && parse[3] == 'A' &&
                //                 parse[4] == 'L' && parse[5] == 'P' && parse[6] == 'W') {
                                
                //                 break;
                //             }
                            
                //             devam = 0;
                //             a = 1;
                            
                //         }else{
                            
                //             // GIDEN

                //             // Basamak icin ayar cek
                //             int goal_pos = pos, sart = 0;
                //             if(goal_pos < 10){ sart = 1; }
                //             else if(goal_pos < 100){ sart = 2; }
                //             else { sart = 3; }


                //             if(id < 10){
                //                 if(sart == 1){
                //                     s << "S" << "GOALPW0" << id << "000" << goal_pos << "0000";
                //                 }else if(sart == 2){
                //                     s << "S" << "GOALPW0" << id << "00" << goal_pos << "0000";
                //                 }else if(sart == 3){
                //                     s << "S" << "GOALPW0" << id << "0" << goal_pos << "0000";
                //                 }
                //             }
                //             else{
                //                 if(sart == 1){
                //                     s << "S" << "GOALPW" << id << "000" << goal_pos << "0000";
                //                 }else if(sart == 2){
                //                     s << "S" << "GOALPW" << id << "00" << goal_pos << "0000";
                //                 }else if(sart == 3){
                //                     s << "S" << "GOALPW" << id << "0" << goal_pos << "0000";
                //                 }
                //             }
                //             break;
                //             a = 0;
                //         }
                //     }
                // }catch (std::exception& e){ std::cout << "Exception: " << e.what() << std::endl; }
                // BOOST END
                    
                
            }
            
            
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
    
    
    
//  if (DEBUG_PRINT == true)
//      {
//          fprintf(stderr, "Time:%.2fms  ", m_Platform->GetPacketTime());
//          fprintf(stderr, "RETURN: ");
//          switch (res)
//              {
//              case SUCCESS:
//                  fprintf(stderr, "SUCCESS\n");
//                  break;
//
//              case TX_CORRUPT:
//                  fprintf(stderr, "TX_CORRUPT\n");
//                  break;
//
//              case TX_FAIL:
//                  fprintf(stderr, "TX_FAIL\n");
//                  break;
//
//              case RX_FAIL:
//                  fprintf(stderr, "RX_FAIL\n");
//                  break;
//
//              case RX_TIMEOUT:
//                  fprintf(stderr, "RX_TIMEOUT\n");
//                  break;
//
//              case RX_CORRUPT:
//                  fprintf(stderr, "RX_CORRUPT\n");
//                  break;
//
//              default:
//                  fprintf(stderr, "UNKNOWN\n");
//                  break;
//              }
//      }

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
    txpacket[PARAMETER]         = (unsigned char)start_addr;
    txpacket[PARAMETER + 1]     = (unsigned char)(each_length - 1);
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
