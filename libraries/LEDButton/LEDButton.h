/*
  LEDButton.h - Defines the LEDButton class.
  Created by Jesse R. Castro 2013-02-15 21:31:22
  This file was created by the Generator Tool!
*/
#ifndef LEDButton_h
#define LEDButton_h

#include "Arduino.h"
#include <Address.h>
#include <Color.h>
#include <FullFader.h>
#include <Common.h>
#include <Bounce.h>
#include "Tlc5940.h"

/** 
 * Represents a full RGB LED Button.  
 * @author Jesse R. Castro
 * @version %I%, %G% 
 * @see Address
 * @see Color
 * @see FullFader
 * @see Common
*/

class LEDButton
{
  public:
	/*
     *	Public Variables
     */
	
	/*
     *	Constructors
     */
	LEDButton();
    LEDButton(const LEDButton& pLEDButton);
    LEDButton(int pFadeInLength, int pFadeOutLength, int pNumBounces, float pBouncePercent, bool pHoldMode, Address pAddress, Color pRest, Color pPressed);
	
	/*
     *	Destructor
     */
	~LEDButton();
	
	/*
     *	Public Setters
     */
	void setFadeInLength(int pFadeInLength);
	void setFadeOutLength(int pFadeOutLength);
	void setNumBounces(int pNumBounces);
	void setBouncePercent(float pBouncePercent);
	void setHoldMode(bool pHoldMode);
	void setButtonState(bool pButtonState);
	
	void setAddress(Address pAddress);
	void setRest(Color pRest);
	void setPressed(Color pPressed);
	void setCurrent(Color pCurrent);
	void setFader(FullFader pFader);
		
	/*
     *	Public Getters
     */
	int getFadeInLength();
	int getFadeOutLength();
	int getNumBounces();
	float getBouncePercent();
	bool getHoldMode();
	bool getButtonState();
		
	Address getAddress();
	Color getRest();
	Color getPressed();
	Color getCurrent();
	FullFader getFader();
		
	int getRedPin();
	int getGreenPin();
	int getBluePin();
	int getRedValue();
	int getGreenValue();
	int getBlueValue();
	
	
	/*
     *	Public Action Methods
     */
	void setupFunc();
	void init();
	void mainPass();
	
	/*
     *	Operator Overloads
     */
	LEDButton& operator=(const LEDButton &pLEDButton);
	bool operator==(const LEDButton &pLEDButton) const;
	bool operator!=(const LEDButton &pLEDButton) const;
	
  private:
    /*
     *	Private Variables
     */
	//fadeInLength - the amount of time for a fade in;
	int fadeInLength;
	//fadeOutLength - the amount of time for a fade out;
	int fadeOutLength;
	//numBounces - the number of bounces after fading;
	int numBounces;
	//bouncePercent - the percent to bounce of the original press;
	float bouncePercent;
	//holdMode - whether or not to hold at peak press color;
	bool holdMode;
	//buttonState - whether or not the button is being pressed;
	bool buttonState;
	
	//address - the pin addresses of the LED and button;
	Address address;
	//rest - the resting color of the LED;
	Color rest;
	//pressed - the color of the LED at full press;
	Color pressed;
	//current - the current color of the LED;
	Color current;
	//fader - the fader for the LED;
	FullFader fader;
	
	/*
     *	Private Setter Methods
     */
	
	/*
     *	Private Getter Methods
     */
	
	
	/*
     *	Private Action Methods
     */
	
	
	/*
     *	Private Utility Methods
     */
	

};

#endif