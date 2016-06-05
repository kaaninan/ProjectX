// ################################         ILETISIM         ################################ //

// SEND NRF MESSAGE
void send_nrf(String msg) {
  transmitter.txPL(msg);
  transmitter.send(SLOW);
}



