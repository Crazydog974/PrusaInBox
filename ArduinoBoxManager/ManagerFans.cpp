#include "ManagerFans.h"
#include <Arduino.h>
#define FANPIN 9 
#define INPUTTEMPERATUEPIN 2 

int switchStateControlTemp = 0;
int oldSwitchStateControlTemp = 0;
bool fanIsActive=false;

void fanSetup(){
  pinMode(FANPIN,OUTPUT);
  pinMode(INPUTTEMPERATUEPIN,INPUT);
}

void fanOn(){
  int value = 255;
  analogWrite(FANPIN,value);
}

void fanOff(){
  int value = 0;
  analogWrite(FANPIN,value);  
}

void ManageTemperature()
{
  switchStateControlTemp = digitalRead(INPUTTEMPERATUEPIN);
  if(switchStateControlTemp != oldSwitchStateControlTemp){
    //Beep();
  }
  if(switchStateControlTemp == HIGH){
    fanOn();
  }
  else{
    if(!fanIsActive)
    {
      fanOff();
    }    
  }
 
  oldSwitchStateControlTemp = switchStateControlTemp;
}

void ManageFans(String cmd){
   Serial.println("Go ManageLeds:" + cmd);  
   //*****************************
   //Leds on and off 
   //*****************************
   if(cmd.equalsIgnoreCase("fans:on")){
      Serial.println("Go stardLeds"); 
      fanIsActive = true;
      fanOn();
   }
   if(cmd.equalsIgnoreCase("fans:off")){
      Serial.println("Go stardLeds"); 
      fanIsActive = false;
      fanOff();
   }
}
