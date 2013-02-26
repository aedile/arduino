#include <Common.h>
#include <Color.h>
//#include <ColorFader.h>
#include <FullFader.h>
#include <Address.h>
#include <LEDButton.h>
#include "Tlc5940.h"

Address address1(9, 2, 1, 0);
Address address2(10, 5, 4, 3);
Address address3(11, 8, 7, 6);
Address address4(12, 11, 10, 9);
Address address5(13, 14, 13, 12);
Color masterPressed(.5,1,.5);
Color masterRest(0.0,1,0);
int fadeInLength = 100;
int fadeOutLength = 200;
int numBounces = 3;
boolean holdMode = true;
float bouncePercent = .75;

LEDButton button1(fadeInLength, fadeOutLength, numBounces, bouncePercent, holdMode, address1, masterRest, masterPressed);
LEDButton button2(fadeInLength, fadeOutLength, numBounces, bouncePercent, holdMode, address2, masterRest, masterPressed);
LEDButton button3(fadeInLength, fadeOutLength, numBounces, bouncePercent, holdMode, address3, masterRest, masterPressed);
LEDButton button4(fadeInLength, fadeOutLength, numBounces, bouncePercent, holdMode, address4, masterRest, masterPressed);
LEDButton button5(fadeInLength, fadeOutLength, numBounces, bouncePercent, holdMode, address5, masterRest, masterPressed);

void setup()   {                
	button1.setupFunc();
	button2.setupFunc();
	button3.setupFunc();
	button4.setupFunc();
	button5.setupFunc();
	Serial.begin(9600);
        Tlc.init();
}

boolean init = true;
void loop()                     
{
  if(init){
     Serial.println("********************************");     
     Serial.println("*                              *");
     Serial.println("*             INIT             *");
     Serial.println("*                              *");
     Serial.println("********************************");
     init = false; 
  }
  
  button1.mainPass();
  button2.mainPass();
  button3.mainPass();
  button4.mainPass();
  button5.mainPass();

  Tlc.set(button1.getRedPin(), button1.getRedValue()); //Red 1
  Tlc.set(button1.getGreenPin(), button1.getGreenValue()); //Green 1
  Tlc.set(button1.getBluePin(), button1.getBlueValue()); //Blue 1
  Tlc.set(button2.getRedPin(), button2.getRedValue()); //Red 1
  Tlc.set(button2.getGreenPin(), button2.getGreenValue()); //Green 1
  Tlc.set(button2.getBluePin(), button2.getBlueValue()); //Blue 1
  Tlc.set(button3.getRedPin(), button3.getRedValue()); //Red 1
  Tlc.set(button3.getGreenPin(), button3.getGreenValue()); //Green 1
  Tlc.set(button3.getBluePin(), button3.getBlueValue()); //Blue 1
  Tlc.set(button4.getRedPin(), button4.getRedValue()); //Red 1
  Tlc.set(button4.getGreenPin(), button4.getGreenValue()); //Green 1
  Tlc.set(button4.getBluePin(), button4.getBlueValue()); //Blue 1
  Tlc.set(button5.getRedPin(), button5.getRedValue()); //Red 1
  Tlc.set(button5.getGreenPin(), button5.getGreenValue()); //Green 1
  Tlc.set(button5.getBluePin(), button5.getBlueValue()); //Blue 1
  
  Tlc.update();


  delay(GLOBAL_DELAY);
}

