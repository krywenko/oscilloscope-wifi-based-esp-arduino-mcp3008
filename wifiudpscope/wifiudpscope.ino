#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <MCP3008.h>
#define CS_PIN 15   //esp 15  ar 10
#define CLOCK_PIN 14  //esp14 ar 13 
#define MOSI_PIN 13  // esp 13 ar 11
#define MISO_PIN 12  // esp 12 ar 12

// put pins inside MCP3008 constructor
MCP3008 adc(CLOCK_PIN, MOSI_PIN, MISO_PIN, CS_PIN);

int sensorValue = 0;        // value read from the pot
byte lb;
byte hb;
const char* ssid = "wii30";
const char* password = "1234567890a";

WiFiUDP Udp;
WiFiUDP Udp2;
WiFiUDP Udp3;
WiFiUDP Udp4;
unsigned int localUdpPort = 4210;  // local port to listen on
char incomingPacket[255];  // buffer for incoming packets
char  replyPacekt[] = "Hi there! Got the message :-)";  // a reply string to send back


void setup()
{
  Serial.begin(115200);
  Serial.println();

  Serial.printf("Connecting to %s ", ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println(" connected");

  Udp.begin(localUdpPort);
  Serial.printf("Now listening at IP %s, UDP port %d\n", WiFi.localIP().toString().c_str(), localUdpPort);
}

IPAddress broadcastIp(192, 168, 168, 3);
unsigned int us = 8;  // micro delay to compensate for packet send
unsigned int udpPort = 1234;
unsigned int udpPort2 = 1235;
unsigned int udpPort3 = 1236;
unsigned int udpPort4 = 1237;
uint8_t i;
void loop()
{

//IPAddress broadcastIp(255, 255, 255, 255);
Udp.beginPacket(broadcastIp,udpPort);
Udp2.beginPacket(broadcastIp,udpPort2);
Udp3.beginPacket(broadcastIp,udpPort3);
Udp4.beginPacket(broadcastIp,udpPort4);
for(i = 0; i < 128; i++){
  sensorValue = adc.readADC(5);            
// shift sample by 3 bits, and select higher byte  
  hb=highByte(sensorValue<<3); 
// set 3 most significant bits and send out
 //Serial.write(hb|224); 
  Udp.write(hb|224); 
  delayMicroseconds(us);
// select lower byte and clear 3 most significant bits
  lb=(lowByte(sensorValue))&31;
// set bits 5 and 6 and send out
//Serial.write(lb|96);
  Udp.write(lb|96);
  delayMicroseconds(us);
// read A1
  sensorValue = adc.readADC(6);            
// shift sample by 3 bits, and select higher byte 
  hb=highByte(sensorValue<<3); 
// set bits 5 and 6 and send out
//Serial.write(lb|96);
  Udp.write(hb|96); 
  delayMicroseconds(us);
// select lower byte and clear 3 most significant bits
  lb=(lowByte(sensorValue))&31;
// set bits 5 and 6 and send out
 //Serial.write(lb|96);
  Udp.write(lb|96);
  delayMicroseconds(us);
  sensorValue = adc.readADC(4);            
// shift sample by 3 bits, and select higher byte  
  hb=highByte(sensorValue<<3); 
// set 3 most significant bits and send out
 //Serial.write(hb|224); 
  Udp2.write(hb|224); 
  delayMicroseconds(us);
// select lower byte and clear 3 most significant bits
  lb=(lowByte(sensorValue))&31;
// set bits 5 and 6 and send out
//Serial.write(lb|96);
  Udp2.write(lb|96);
  delayMicroseconds(us);
// read A1
  sensorValue = adc.readADC(3);            
// shift sample by 3 bits, and select higher byte 
  hb=highByte(sensorValue<<3); 
// set bits 5 and 6 and send out
//Serial.write(lb|96);
  Udp2.write(hb|96); 
  delayMicroseconds(us);
// select lower byte and clear 3 most significant bits
  lb=(lowByte(sensorValue))&31;
// set bits 5 and 6 and send out
 //Serial.write(lb|96);
  Udp2.write(lb|96);
  delayMicroseconds(us);
    sensorValue = adc.readADC(2);            
// shift sample by 3 bits, and select higher byte  
  hb=highByte(sensorValue<<3); 
// set 3 most significant bits and send out
 //Serial.write(hb|224); 
  Udp3.write(hb|224); 
  delayMicroseconds(us);
// select lower byte and clear 3 most significant bits
  lb=(lowByte(sensorValue))&31;
// set bits 5 and 6 and send out
//Serial.write(lb|96);
  Udp3.write(lb|96);
  delayMicroseconds(us);
// read A1
  sensorValue = adc.readADC(1);            
// shift sample by 3 bits, and select higher byte 
  hb=highByte(sensorValue<<3); 
// set bits 5 and 6 and send out
//Serial.write(lb|96);
  Udp3.write(hb|96); 
  delayMicroseconds(us);
// select lower byte and clear 3 most significant bits
  lb=(lowByte(sensorValue))&31;
// set bits 5 and 6 and send out
 //Serial.write(lb|96);
  Udp3.write(lb|96);
  delayMicroseconds(us);
      sensorValue = adc.readADC(7);            
// shift sample by 3 bits, and select higher byte  
  hb=highByte(sensorValue<<3); 
// set 3 most significant bits and send out
 //Serial.write(hb|224); 
  Udp4.write(hb|224); 
  delayMicroseconds(us);
// select lower byte and clear 3 most significant bits
  lb=(lowByte(sensorValue))&31;
// set bits 5 and 6 and send out
//Serial.write(lb|96);
  Udp4.write(lb|96);
  delayMicroseconds(us);
// read A1
  sensorValue = adc.readADC(0);            
// shift sample by 3 bits, and select higher byte 
  hb=highByte(sensorValue<<3); 
// set bits 5 and 6 and send out
//Serial.write(lb|96);
  Udp4.write(hb|96);
delayMicroseconds(us);
// select lower byte and clear 3 most significant bits
  lb=(lowByte(sensorValue))&31;
// set bits 5 and 6 and send out
 //Serial.write(lb|96);
  Udp4.write(lb|96);
  delayMicroseconds(us);
}
Udp.endPacket();
Udp2.endPacket();
Udp3.endPacket();
Udp4.endPacket();
  }
