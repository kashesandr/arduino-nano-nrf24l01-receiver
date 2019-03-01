// NRF24L01 Module Tutorial - Code for Receiver using Arduino UNO

//Include needed Libraries at beginning
#include "nRF24L01.h" // NRF24L01 library created by TMRh20 https://github.com/TMRh20/RF24
#include "RF24.h"
#include "SPI.h"

RF24 radio(9, 10); // NRF24L01 used SPI pins + Pin 9 and 10 on the UNO

const uint64_t pipe = 0xE6E6E6E6E6E6; // Needs to be the same for communicating between 2 NRF24L01

void setup(void) {
  
  Serial.begin(9600);
  
 delay(2000);
 radio.begin(); // Start the NRF24L01
 // Max power
 radio.setPALevel( RF24_PA_MAX ) ;
 // Min speed (for better range I presume)
 radio.setDataRate( RF24_250KBPS ) ;
 // 8 bits CRC
 radio.setCRCLength( RF24_CRC_8 ) ;
 // increase the delay between retries & # of retries
 radio.setRetries(15, 15);
 radio.setAutoAck(false);
 radio.openReadingPipe(1, pipe); // Get NRF24L01 ready to receive
 radio.startListening(); // Listen to see if information received
}

unsigned int data; // Used to store value received by the NRF24L01

void loop(void) {
 while (radio.available()) {
  radio.read(&data,sizeof(unsigned int));
  Serial.println(data);
  delay(10);
 }
}
