

#include <DmxMaster.h>

int delayIncr = 20;
int maxChan = 4;

int channel;

void setup() {
  Serial.begin(9600);
  DmxMaster.usePin(3);
  DmxMaster.maxChannel(4);
  channel = 1; //no zero channel
  for (int i = 0; i<9;i++){

    DmxMaster.write(i, 0);
    
    }
  
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
  
    for (int i = 0; i<9;i++){

    DmxMaster.write(i, 0);
    
    }

  if (channel == maxChan) {
    channel = 1; //no zero channel
    }

}


