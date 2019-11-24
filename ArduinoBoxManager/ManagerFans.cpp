#include "ManagerFans.h"
#include <Arduino.h>
#define FANPIN 9 
#define INPUTTEMPERATUEPIN 2 

int switchStateControlTemp = 0;
int oldSwitchStateControlTemp = 0;

void fanSetup(){
  pinMode(FANPIN,OUTPUT);
  pinMode(INPUTTEMPERATUEPIN,INPUT);
}

void fanLower(){
  int value = 70;
  analogWrite(FANPIN,value);
}

void fanHigher(){
  int value = 255;
  analogWrite(FANPIN,value);  
}

void ManageTemperature()
{
  switchStateControlTemp = digitalRead(INPUTTEMPERATUEPIN);
  if(switchStateControlTemp != oldSwitchStateControlTemp){
    //Beep();
  }
  if(switchStateControlTemp == LOW){
    fanLower();
  }
  else{
    fanHigher();
  }
  oldSwitchStateControlTemp = switchStateControlTemp;
}

void ManageFans(String cmd){
  
}
