/*
  Color.cpp - Library for controlling RGB arcade buttons
  Created by Jesse R. Castro 2013-02-03
*/

#include "Color.h"

Color::Color(float pHue, float pSaturation, float pValue){
	setHSV(pHue, pSaturation, pValue);
}
Color::Color(const Color& pColor){
	*this = pColor;
}
Color::Color(){
	setHSV(0,0,0);
}
//setters
void Color::setHue(float pHue){
	//Note, of these hue cycles, so we have to make sure that works
	//abs gets rid of any negatives
	//the val - floor(val) will take return only decimal portions
	hue = abs(pHue) - floor(abs(pHue));
	
}
void Color::setSaturation(float pSaturation){
	if(pSaturation < 0){
		saturation = 0;
	}else if(pSaturation > 1){
		saturation = 1;
	}else{
		saturation = pSaturation;
	}
}
void Color::setValue(float pValue){
	if(pValue < 0){
		value = 0;
	}else if(pValue > 1){
		value = 1;
	}else{
		value = pValue;
	}
}
void Color::setHSV(float pHue, float pSaturation, float pValue){
	setHue(pHue);
	setSaturation(pSaturation);
	setValue(pValue);
}
void Color::setRed(int pRed){
	if(pRed < 0){
		red = 0;
	}else if(pRed > 255){
		red = 255;
	}else{
		red = pRed;
	}
}
void Color::setBlue(int pBlue){
	if(pBlue < 0){
		blue = 0;
	}else if(pBlue > 255){
		blue = 255;
	}else{
		blue = pBlue;
	}
}
void Color::setGreen(int pGreen){
	if(pGreen < 0){
		green = 0;
	}else if(pGreen > 255){
		green = 255;
	}else{
		green = pGreen;
	}
}
void Color::setRGB(int pRed, int pGreen, int pBlue){
	setRed(pRed);
	setGreen(pGreen);
	setBlue(pBlue);
}
//getters
float Color::getHue() const{
	return hue;
}
float Color::getSaturation() const{
	return saturation;
}
float Color::getValue() const{
	return value;
}
int Color::getRed(){
	hsv2rgb();
	return red;
}
int Color::getGreen(){
	hsv2rgb();
	return green;
}
int Color::getBlue(){
	hsv2rgb();
	return blue;
}

//action methods
void Color::turnOff(){
	setValue(0);
}
void Color::rgb2hsv(){
	float r = (red + 0)/255.0;
	float g = (green + 0)/255.0; 
	float b = (blue + 0)/255.0;
			
	float max = max(max(r, g), b);
	float min = min(min(r, g), b);
	
	float h = max;
	float s = max;
	float v = max;

	float d = max - min;
	s = max == 0 ? 0 : d / max;

	if(max == min){
		h = 0; // achromatic
	}else{
		if(max == r){
			h = (g - b) / d + (g < b ? 6 : 0);
		}else if (max == g){
			h = (b - r) / d + 2; 
		}else{
			h = (r - g) / d + 4; 
		}
		h /= 6;
	}

	setHue(h);
	setSaturation(s);
	setValue(v);
}
void Color::hsv2rgb(){
	float r, g, b;

	float h = hue;
	float s = saturation;
	float v = value;
	
	int i = floor(h * 6);	
	float f = h * 6 - i;
	float p = v * (1 - s);
	float q = v * (1 - f * s);
	float t = v * (1 - (1 - f) * s);

	switch(i % 6){
		case 0: r = v, g = t, b = p; break;
		case 1: r = q, g = v, b = p; break;
		case 2: r = p, g = v, b = t; break;
		case 3: r = p, g = q, b = v; break;
		case 4: r = t, g = p, b = v; break;
		case 5: r = v, g = p, b = q; break;
	}

	setRed(round(r*255));
	setGreen(round(g*255));
	setBlue(round(b*255));
	
}
float Color::getMin(){
	float r = (red + 0)/255.0;
	float g = (green + 0)/255.0;
	float b = (blue + 0)/255.0;
	
	if(r < g){
		if(r < b){
			return r;
		}else{
			return b;
		}
	}else{
		if(g < b){
			return g;
		}else{
			return b;
		}
	}
}
float Color::getMax(){
	float r = (red + 0)/255.0;
	float g = (green + 0)/255.0;
	float b = (blue + 0)/255.0;
	
	if(r > g){
		if(r > b){
			return r;
		}else{
			return b;
		}
	}else{
		if(g > b){
			return g;
		}else{
			return b;
		}
	}
}
int Color::floor(float target){
	int returnVal = round(target);
	if(returnVal > target){
		returnVal--;
	}
	return returnVal;
}
//operator overloads
Color& Color::operator=(const Color &pColor){
	setHSV(pColor.hue, pColor.saturation, pColor.value);	
	return *this;
}

/** 
 * Comparison == operator overload.
 * @author Jesse R. Castro
 * @param pFoo An instance of the same type as this object.
 * @return A boolean value describing whether the objects are equivalent or not.
 */
bool Color::operator==(const Color &pColor) const {
	if(
		(hue == pColor.hue) &&
		(saturation == pColor.saturation) &&
		(value == pColor.value)
	){
		return true;
	}else{
		return false;
	}
}
/** 
 * Comparison != operator overload.
 * @author Jesse R. Castro
 * @param pFoo An instance of the same type as this object.
 * @return A boolean value describing the inverse of whether the objects are equivalent or not.
 */
bool Color::operator!=(const Color &pColor) const {
	return !(*this == pColor);
}
