

#include <DmxMaster.h>

int delayIncr = 50;
int maxChan = 119;
int initChan = 110;

int channel;

void setup() {
  Serial.begin(9600);
  DmxMaster.usePin(3);
  DmxMaster.maxChannel(512);
  channel = initChan; //no zero channel
  
}

void loop() {
  int brightness;
  for (brightness = 0; brightness <= 255; brightness++) {
    
    /* Update DMX channel 1 to new brightness */
    DmxMaster.write(channel, brightness);
    //DmxMaster.write(channel+4, brightness); // só para maquinas iguais
    delay(random(delayIncr));
    DmxMaster.write(channel, 0);
    //DmxMaster.write(channel+4, 0);
    Serial.print(channel);
    Serial.print(" - ");
    Serial.println(brightness);
    delay(random(delayIncr));

  }
  channel++;
  


  if (channel == maxChan) {
    channel = initChan; //no zero channel
    }

}


