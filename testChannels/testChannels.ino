

#include <DmxMaster.h>

int delayIncr = 50;
int maxChan = 8;

int channel;

void setup() {
  Serial.begin(9600);
  DmxMaster.usePin(3);
  DmxMaster.maxChannel(4);
  channel = 1; //no zero channel
  
}

void loop() {
  int brightness;
  for (brightness = 0; brightness <= 255; brightness++) {
    
    /* Update DMX channel 1 to new brightness */
    DmxMaster.write(channel, brightness);
    DmxMaster.write(channel+4, brightness); // só para maquinas iguais
    delay(random(delayIncr));
    DmxMaster.write(channel, 0);
    DmxMaster.write(channel+4, 0);
    Serial.print(channel);
    Serial.print(" - ");
    Serial.println(brightness);
    delay(random(delayIncr));

  }
  channel++;
  
  DmxMaster.write(channel-1, random(40));
  DmxMaster.write(channel-2, random(40));
  DmxMaster.write(channel-3, random(40));
  DmxMaster.write(channel+4-1, random(40)); // só para maquinas iguais comentar
  DmxMaster.write(channel+4-2, random(40));
  DmxMaster.write(channel+4-3, random(40));

  if (channel == maxChan) {
    channel = 1; //no zero channel
    }

}


