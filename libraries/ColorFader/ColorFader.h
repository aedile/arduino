/*
  ColorFader.h - Library for controlling RGB arcade buttons
  Created by Jesse R. Castro 2013-02-03
*/

#ifndef ColorFader_h
#define ColorFader_h

#include "Arduino.h"
#include <Common.h>
#include "../Color/Color.h"

class ColorFader
{
  public:
	//public vars
	
	//constructor
    ColorFader(int pFadeLength, int pLoopMode);
	ColorFader(const ColorFader& pColorFader);
	ColorFader();
	//destructor
	
	//setters
	void setLength(int pLength);
	void setLoopMode(int pLoopMode);
	void setIndex(int pIndex);
	//getters
	int getLength();
	int getLoopMode();
	int getIndex();
	//action methods
	const Color fade(const Color &pFromColor, const Color &pToColor);
	const Color fadeToPercent(const Color &pFromColor, const Color &pToColor, float pPercent);
	float calcFade(float toValue, float fromValue, int pLoopMode);  
	void startFade();
	void startFade(const Color &pFromColor, const Color &pToColor, const Color &pCurrentColor);	
	//utility methods
	
   private:
	//private vars
	int index; 
	int length; // In milliseconds!!!
	int loopMode; //for rotary looping only
	bool fading;
	//setters
	
	//getters
	
	//action methods
	float calcUpDeltaValue(float toValue, float fromValue);
	float calcDownDeltaValue(float toValue, float fromValue);
	float calcUpFade(float fromValue, float deltaValue, float lengthPercent);
	float calcDownFade(float fromValue, float deltaValue, float lengthPercent);
	int reverse(float curPercent, float toValue, float fromValue, int tempLoopMode);
	//utility methods
	
	//operator overloads
	ColorFader& operator=(const ColorFader &pColorFader);
	
};

#endif













