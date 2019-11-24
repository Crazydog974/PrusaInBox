#include "ManagerLeds.h"
#include <Arduino.h>
#include <Adafruit_NeoPixel.h>


#define PINLEDS 6 
#define NUMPIXELS 32 

Adafruit_NeoPixel pixels(NUMPIXELS, PINLEDS, NEO_BRG + NEO_KHZ800);

bool ledsIsOn = false;
uint32_t colorLeds;

int frondLeds[8] = {24,25,26,27,28,29,30,31};
int leftLeds[8] = {16,17,18,19,20,21,22,23};
int rightLeds[8] = {0,1,2,3,4,5,6,7}; //
int backLeds[8] = {8,9,10,11,12,13,14,15}; // 

void ledsSetup(){
  //Manage Leds
  pixels.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  pixels.show();            // Turn OFF all pixels ASAP
  pixels.setBrightness(255); // Set BRIGHTNESS to about 1/5 (max = 255)
  LedsOff();
}

void ManageLeds(String cmd)
{
   Serial.println("Go ManageLeds:" + cmd);  
   
   //Leds on  
   if(cmd.equalsIgnoreCase("leds:on")){
      Serial.println("Go stardLeds"); 
      LedsOn();
   }
   //Leds off 
   if(cmd.equalsIgnoreCase("leds:off")){
      Serial.println("Go stardLeds"); 
      LedsOff();
   }
   //Flash
   if(cmd.equalsIgnoreCase("leds:flashon")){
      flashOn();
   }
   if(cmd.equalsIgnoreCase("leds:flashoff")){
      flashOff();
   }
}


// Fill strip pixels one after another with a color. Strip is NOT cleared
// first; anything there will be covered pixel by pixel. Pass in color
// (as a single 'packed' 32-bit value, which you can get by calling
// strip.Color(red, green, blue) as shown in the loop() function above),
// and a delay time (in milliseconds) between pixels.
void colorWipe(int tabLeds[8],uint32_t color,int wait) {
  for(int i=0; i<8; i++) { // For each pixel in strip...
    pixels.setPixelColor(tabLeds[i], color);         //  Set pixel's color (in RAM)
    pixels.show();                          //  Update strip to match
    delay(wait);                           //  Pause for a moment
  }
}
void ManageLineLeds(int tabLeds[8],uint32_t color, bool withShow)
{ 
  for(int i=0; i < 8; i++){
    pixels.setPixelColor(tabLeds[i], color);         
  }
  if(withShow){
     pixels.show();
  }
  //  colorWipe(pixels.Color(255,   0,   0)     , 500); // Red
  //  colorWipe(pixels.Color(  0, 255,   0)     , 500); // Green
  //  colorWipe(pixels.Color(  0,   0, 255)     , 500); // Blue
  //  colorWipe(pixels.Color(  255,   255, 255)     , 500); // White
  //  colorWipe(pixels.Color(  0,   0, 0)     , 500); // Black
  //  colorWipe(pixels.Color(  255,   128, 0)     , 500); // Orange
  //  colorWipe(pixels.Color(  255,   0, 255)     , 500); // violet
  //  colorWipe(pixels.Color(  0,   255, 255)     , 500); // bleu clair
  //  colorWipe(pixels.Color(  255,   255, 0)     , 500); // jaune
}

void ManageAllLeds(uint32_t color)
{
    colorLeds = color;
    ManageLineLeds(frondLeds,color, false);    
    ManageLineLeds(leftLeds,color, false);
    ManageLineLeds(rightLeds,color, false);
    ManageLineLeds(backLeds,color, false);
    pixels.show();
}

void LedsOn(){
  ledsIsOn = true;
  ManageAllLeds(pixels.Color(255,255,255));
  delay(100);
  ManageAllLeds(pixels.Color(0,0,0));
  delay(100);
  ManageAllLeds(pixels.Color(255,255,255));
  delay(100);
  ManageAllLeds(pixels.Color(0,0,0));
  delay(100);
  
  colorWipe(rightLeds,pixels.Color(255, 0, 255),25);
  colorWipe(backLeds,pixels.Color(255, 0, 255),25);
  colorWipe(leftLeds,pixels.Color(255, 0, 255),25);
  colorWipe(frondLeds,pixels.Color(255, 0, 255),25);
}

void LedsOff(){
  ledsIsOn = false;
  ManageAllLeds(pixels.Color(255,255,255));
  delay(100);
  ManageAllLeds(pixels.Color(0,0,0));
  delay(100);
  ManageAllLeds(pixels.Color(255,255,255));
  delay(100);
  ManageAllLeds(pixels.Color(0,0,0));
}

void flashOn(){
   ManageAllLeds(pixels.Color(255,255,255));
}
void flashOff(){
   ManageAllLeds(colorLeds);
}
