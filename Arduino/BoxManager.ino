#include "StarWarsSong.h"
#include "ManagerLeds.h"
#include "ManagerFans.h"


bool isStart = true;
String inputString = "";   // chaine de caractères pour contenir les données
boolean stringComplete = false;  // pour savoir si la chaine est complète


/**************************************************************************
   Init Setup
 **************************************************************************/
void setup() {
  //Manager Ventilattion
  fanSetup();

  //Manage Leds
  ledsSetup();

  //Buzze
  buzzerSetup();

  //Init Serial
  Serial.begin(9600);


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
    // récupérer le prochain octet (byte ou char) et l'enlever
    char inChar = (char)Serial.read();
    // caractère de fin pour notre chaine
    if (inChar == '\n') {
      stringComplete = true;
    }
    else {
      // concaténation des octets reçus
      inputString += inChar;
    }
  }
}
