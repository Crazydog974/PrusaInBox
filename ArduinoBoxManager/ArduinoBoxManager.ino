#include "StarWarsSong.h"
#include "ManagerLeds.h"
#include "ManagerFans.h"


bool isStart = true;
String inputString = "";   
boolean stringComplete = false;  


/**************************************************************************
   Init Setup
 **************************************************************************/
void setup() {
  
  //Init Serial
  Serial.begin(115200); // 115200
  
  //Manager Fans
  fanSetup();

  //Manage Leds
  ledsSetup();

  //Buzze
  buzzerSetup();



  //buzzerPlayStarWarsSong();
}

/**************************************************************************
   Loop
 **************************************************************************/
void loop() {
  
  ManageTemperature();

  if (stringComplete) {
    // ManageLeds();
    if (inputString.startsWith("leds:")) {
      ManageLeds(inputString);
    }
    if (inputString.startsWith("fans:")) {
      ManageFans(inputString);
    }
    stringComplete = false;
    inputString = "";
  }
}
/**************************************************************************
   Loop
 **************************************************************************/
void serialEvent() {
  while (Serial.available()) {   
    char inChar = (char)Serial.read();
    if (inChar == '\n') {
      stringComplete = true;
    }
    else {
      inputString += inChar;
    }
  }
}
