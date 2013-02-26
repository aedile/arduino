/*
  Color.h - Library for controlling RGB arcade buttons
  Created by Jesse R. Castro 2013-02-03
*/
#ifndef Color_h
#define Color_h

#include "Arduino.h"
#include <Common.h>

class Color
{
  public:
	//public vars
	
    //constructor
	Color(float pHue, float pSaturation, float pValue);
	Color(const Color& pColor);
    Color();
    //destructor
	
	//setters
	void setHue(float pHue);
	void setSaturation(float pSaturation);
	void setValue(float pValue);
	void setHSV(float pHue, float pSaturation, float pValue);
	//getters
	float getHue() const;
	float getSaturation() const;
	float getValue() const;
	int getRed();
	int getBlue();
	int getGreen();
	//action methods
	void turnOff();	
	//operator overloads
	Color& operator=(const Color &pColor);
	bool operator==(const Color &pColor) const;
	bool operator!=(const Color &pColor) const;
private:
    //private vars
	int red;
	int green;
	int blue;
	float hue;
	float saturation;
	float value;
	//setters
	void setRed(int pRed);
    void setGreen(int pGreen);
	void setBlue(int pBlue);
	void setRGB(int pRed, int pBlue, int pGreen);
	//getters
	
	//action methods
	
	//utilities
	void rgb2hsv();
	void hsv2rgb();
	float getMin();
	float getMax();
	int floor(float target);
};

#endif