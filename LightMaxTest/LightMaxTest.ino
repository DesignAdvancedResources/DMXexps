
#include <DmxMaster.h>

int r,g,b;

int chanColorInit1 = 16;
int chanColorInit2 = 28;
int chanColorInit3 = 40;
int chanColorInit4 = 52;


int chanPan1;
int chanPanFine1;
int chanTilt1;
int chanTiltFine1;
int chanPanTiltSpeed1;

int chanPan2;
int chanPanFine2;
int chanTilt2;
int chanTiltFine2;
int chanPanTiltSpeed2;

int chanPan3;
int chanPanFine3;
int chanTilt3;
int chanTiltFine3;
int chanPanTiltSpeed3;

int chanPan4; 
int chanPanFine4; 
int chanTilt4;
int chanTiltFine4;
int chanPanTiltSpeed4;




void setup() {


Serial.begin(9600);
DmxMaster.usePin(3);
DmxMaster.maxChannel(512);

DmxMaster.write(31, 1);
DmxMaster.write(32, 1);
DmxMaster.write(33, 1);
DmxMaster.write(43, 1);
DmxMaster.write(44, 1);
DmxMaster.write(45, 1);
DmxMaster.write(19, 1);
DmxMaster.write(20, 1);
DmxMaster.write(21, 1);
DmxMaster.write(55, 1);
DmxMaster.write(56, 1);
DmxMaster.write(57, 1);

// modes

DmxMaster.write(15, 240);
DmxMaster.write(27, 240);
DmxMaster.write(39, 240);
DmxMaster.write(51, 240);

chanPan1 = 10;
chanPanFine1 = chanPan1+1;
chanTilt1 = chanPan1+2;
chanTiltFine1 = chanPan1+3;
chanPanTiltSpeed1 = chanPan1+4;

chanPan2 = 22;
chanPanFine2 = chanPan2+1;
chanTilt2 = chanPan2+2;
chanTiltFine2 = chanPan2+3;
chanPanTiltSpeed2 = chanPan2+4;

chanPan3 = 34;
chanPanFine3 = chanPan3+1;
chanTilt3 = chanPan3+2;
chanTiltFine3 = chanPan3+3;
chanPanTiltSpeed3 = chanPan3+4;

chanPan4 = 46;
chanPanFine4 = chanPan4+1;
chanTilt4 = chanPan4+2;
chanTiltFine4 = chanPan4+3;
chanPanTiltSpeed4 = chanPan4+4;


}

void loop() {

  r = 255;
  g = 20;
  b = 20;

  DmxMaster.write(chanColorInit1, r);
  DmxMaster.write(chanColorInit1+1, g);
  DmxMaster.write(chanColorInit1+2, b);
   
  DmxMaster.write(chanColorInit2, r);
  DmxMaster.write(chanColorInit2+1, g);
  DmxMaster.write(chanColorInit2+2, b);
   
  DmxMaster.write(chanColorInit3, r);
  DmxMaster.write(chanColorInit3+1, g);
  DmxMaster.write(chanColorInit3+2, b);
  
  DmxMaster.write(chanColorInit4, r);
  DmxMaster.write(chanColorInit4+1, g);
  DmxMaster.write(chanColorInit4+2, b);

  DmxMaster.write(chanPan1, random(255));
  DmxMaster.write(chanPan2, random(255));
  DmxMaster.write(chanPan3, random(255));
  DmxMaster.write(chanPan4, random(255));

  DmxMaster.write(chanTilt1, random(255));
  DmxMaster.write(chanTilt2, random(255));
  DmxMaster.write(chanTilt3, random(255));
  DmxMaster.write(chanTilt4, random(255));

  DmxMaster.write(chanPanTiltSpeed1, random(255));
  DmxMaster.write(chanPanTiltSpeed2, random(255));
  DmxMaster.write(chanPanTiltSpeed3, random(255));
  DmxMaster.write(chanPanTiltSpeed4, random(255));
  
  
  for (int i = 0; i <= 255; i++) {
    
  DmxMaster.write(chanPanFine1, i);
  DmxMaster.write(chanPanFine2, i);
  DmxMaster.write(chanPanFine3, i);
  DmxMaster.write(chanPanFine4, i);

  DmxMaster.write(chanTiltFine1, i);
  DmxMaster.write(chanTiltFine2, i);
  DmxMaster.write(chanTiltFine3, i);
  DmxMaster.write(chanTiltFine4, i);

  delay(10);
    
    }

}
