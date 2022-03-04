
#include <IRLibSendBase.h>
#include <IRLib_HashRaw.h>
IRsendRaw mySender;
int pot = A0;
int sensorValue = 0;
int fanrelay = 11

 
void setup() {
  Serial.begin(9600);
  delay(2000);
  pinMode(fanrelay, OUTPUT);
  pinMode(acrelay, OUTPUT);
  digitalWrite(fanrelay, HIGH);
  digitalWrite(acrelay, LOW);
    
}


#define RAW_DATA_LEN 212
uint16_t rawData[RAW_DATA_LEN]={
8964, 4516, 524, 1696, 504, 1716, 528, 572, 524, 572, 528, 568, 528, 572, 524, 1696, 528, 1692, 504, 1716, 528, 1696, 500, 1720, 500, 596, 528, 572, 500, 1720, 512, 584, 528, 1692, 504, 596, 500, 596, 528, 568, 528, 572, 504, 592, 504, 1716, 528, 1696, 500, 1720, 528, 568, 504, 596, 524, 572, 504, 592, 528, 572, 500, 596, 504, 592, 528, 572, 500, 596, 504, 592, 504, 596, 504, 592, 528, 572, 500, 1720, 524, 572, 504, 592, 528, 572, 504, 592, 528, 572, 524, 572, 528, 568, 528, 568, 528, 572, 504, 592, 504, 596, 524, 572, 504, 596, 500, 596, 524, 572, 504, 1716, 528, 572, 500, 596, 524, 572, 504, 596, 500, 596, 504, 592, 528, 572, 500, 596, 524, 572, 528, 572, 524, 572, 500, 596, 528, 572, 552, 544, 504, 592, 528, 572, 524, 572, 500, 600, 500, 596, 500, 596, 528, 572, 524, 572, 500, 596, 504, 596, 500, 596, 524, 572, 528, 572, 500, 596, 500, 596, 528, 572, 500, 596, 504, 592, 528, 572, 524, 572, 524, 1700, 524, 572, 524, 1696, 528, 568, 528, 572, 524, 576, 500, 592, 528, 572, 524, 1696, 524, 1696, 504, 1716, 504, 1720, 524, 572, 504, 592, 504, 596, 552, 1668, 528, 1000};


void loop() {
  sensorValue = analogRead(sensorPin);
  //For testing purpose
  if (sensorvalue == 0 ) {
    // ir data to turn off the AC
    mySender.send(rawData,RAW_DATA_LEN,36);//Pass the buffer,length, optionally frequency
    delay(1000)
  }
  
  // For 2 houre delay
  elseif (0<sensorvalue>256){
    for(int i=0;i<=7200;i++){ // 2 hours dealy
    delay(1000);}
    // turn off the AC with ir controller
    mySender.send(rawData,RAW_DATA_LEN,36);//Pass the buffer,length, optionally frequency
    delay(1000)
    digitalWrite(fanrelay, LOW);// turn on the fan
        }
        
  // For 4 houre delay
  elseif (256<sensorvalue>512){
    for(int i=0;i<=14400;i++){ // 4 hours dealy
    delay(1000);}
    // turn off the AC with ir controller
    mySender.send(rawData,RAW_DATA_LEN,36);//Pass the buffer,length, optionally frequency
    delay(1000)
    digitalWrite(fanrelay, LOW);// turn on the fan
}
    
  // For 6 houre delay
  elseif (sensorvalue<512){
    for(int i=0;i<=21600;i++){ // 6 hours dealy
    delay(1000);}
        // turn off the AC with ir controller
    mySender.send(rawData,RAW_DATA_LEN,36);//Pass the buffer,length, optionally frequency
    delay(1000)
    digitalWrite(fanrelay, LOW);// turn on the fan

    }
}
