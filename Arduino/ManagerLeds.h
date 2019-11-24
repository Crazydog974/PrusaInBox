#include <Arduino.h>
void ledsSetup();
void LedsOn();
void LedsOff();
void colorWipe(int tabLeds[8],uint32_t color,int wait);
void ManageAllLeds(uint32_t color);
void ManageLineLeds(int tabLeds[8],uint32_t color, bool withShow);
void ManageLeds(String cmd);
void flashOn();
void flashOff();
