/*
  ColorFader.cpp - Library for controlling RGB arcade buttons
  Created by Jesse R. Castro 2013-02-03
*/

#include "ColorFader.h"

//Constructor
ColorFader::ColorFader(int pLength, int pLoopMode){
	setLength(pLength);
	setLoopMode(pLoopMode);
	index = 0;
	fading = false;
}
ColorFader::ColorFader(const ColorFader& pColorFader):
	length(pColorFader.length),
	loopMode(pColorFader.loopMode)	
{
	setLoopMode(LTYPE_NONE);
	index = 0;
	fading = false;
}
ColorFader::ColorFader(){
	setLength(0);
	setLoopMode(LTYPE_NONE);
	index = 0;
	fading = false;
}
//Setters
void ColorFader::setLength(int pLength){
	length = pLength;
}
void ColorFader::setIndex(int pIndex){
	index = pIndex;
}
void ColorFader::setLoopMode(int pLoopMode){
	loopMode = pLoopMode;
}
//Getters
int ColorFader::getIndex(){
	return index;
}
int ColorFader::getLength(){
	return length;
}
int ColorFader::getLoopMode(){
	return loopMode;
}
//Action Methods
//start a fade from scratch
void ColorFader::startFade(){
	index = 1;
}
//start a fade from your current 
void ColorFader::startFade(const Color &pFromColor, const Color &pToColor, const Color &pCurrentColor){
	if(pFromColor == pToColor){
		index = 0;
	}else{
		if(pFromColor.getSaturation() != pToColor.getSaturation()){
			index = reverse(pCurrentColor.getSaturation(),pToColor.getSaturation(),pFromColor.getSaturation(), LTYPE_NONE);
			if(index == 0){
				index = 1;
			}
		}else if(pFromColor.getValue() != pToColor.getValue()){
			index = reverse(pCurrentColor.getValue(),pToColor.getValue(),pFromColor.getValue(), LTYPE_NONE);
			if(index == 0){
				index = 1;
			}
		
		}else{
			index = reverse(pCurrentColor.getHue(),pToColor.getHue(),pFromColor.getHue(), loopMode);
			if(index == 0){
				index = 1;
			}
		
		}
	}	
}
const Color ColorFader::fade(const Color &pFromColor, const Color &pToColor){
	//if index == 0, we aren't fading because when fading we set
	// the index to 1.  If the time == length, then we are done fading
	// otherwise, we do the fade as normal  
	float time = (index-1) * GLOBAL_DELAY;
	if(index == 0){
		return pToColor;
	}else{
		float newHue = calcFade(pToColor.getHue(), pFromColor.getHue(), loopMode);
		float newSaturation = calcFade(pToColor.getSaturation(), pFromColor.getSaturation(), LTYPE_NONE);
		float newValue = calcFade(pToColor.getValue(), pFromColor.getValue(), LTYPE_NONE);
		Color result(newHue, newSaturation, newValue);

		if(time == length){
			index = 0;
		}else{
			index++;
		}
		return result;
	}	
}	
const Color ColorFader::fadeToPercent(const Color &pFromColor, const Color &pToColor, float pPercent){
	//we need to save our index, in case we are in the middle of a fade
	int holdIndex = index;
	//now we need to calculate a new index based on our percent
	int newIndex = round((length/GLOBAL_DELAY) * pPercent);
	index = newIndex;
	Color result;
	result = fade(pFromColor, pToColor);
	index = holdIndex;
	return result;
}	
float ColorFader::calcFade(float basePercent, float pressedPercent, int tempLoopMode){
	//time percentage:  note, I have kicked the index up by one
	//to indicate we are fading, so i have to subtract one so we get
	//the first fade.  testing this out, might need to revert
	float time = (index-1) * GLOBAL_DELAY;
	float lengthPercent = time/length;
	float upFade, downFade, upDeltaValue, downDeltaValue;
	
	//calculate the up and down deltaValue
	upDeltaValue = calcUpDeltaValue(basePercent, pressedPercent);
	downDeltaValue = calcDownDeltaValue(basePercent, pressedPercent);
	//calculate the up and down fades
	upFade = calcUpFade(pressedPercent, upDeltaValue, lengthPercent);
	downFade = calcDownFade(pressedPercent, downDeltaValue, lengthPercent);
	float preUp = upFade;
	float preDown = downFade;
	
	//correct for overfade
	if((tempLoopMode==LTYPE_UP)||(tempLoopMode==LTYPE_DOWN)||(tempLoopMode==LTYPE_MAX)||(tempLoopMode==LTYPE_MIN)){
		//deal with overfade on rotary fade
		if(upFade > 1){
			upFade = upFade - 1;
		}	
		if(downFade < 0){
			downFade = downFade + 1;
		}
	}else{
		//deal with any accidental overfade
		//for non roto-fade
		if(upFade > 1){
			upFade = 1;
		}	
		if(downFade < 0){
			downFade = 0;
		}
	}
	
	//switch on type
	if(tempLoopMode == LTYPE_UP){
	//up always
		return upFade;
	}else if(tempLoopMode == LTYPE_DOWN){
	//down always
		return downFade;
	}else if(tempLoopMode == LTYPE_MIN){
	//shortest fade
		if(upDeltaValue < downDeltaValue){
			return upFade;
		}else{
			return downFade;
		}
	}else if(tempLoopMode == LTYPE_MAX){
	//longest fade
		if(upDeltaValue > downDeltaValue){
			return upFade;
		}else{
			return downFade;
		}

	}else{
	//loopMode == LTYPE_NONE or undefined, no rotary
		if(pressedPercent > basePercent){
			return downFade;
		}else{
			return upFade;
		}
	}
}
float ColorFader::calcUpDeltaValue(float toValue, float fromValue){
	float computedToValue = toValue;
	if(toValue < fromValue){
		computedToValue = toValue + 1;
	}
	float deltaValue = computedToValue - fromValue;
	return deltaValue;
}
float ColorFader::calcDownDeltaValue(float toValue, float fromValue){
	float computedToValue = toValue;
	if(toValue > fromValue){
		computedToValue = fromValue - 1;
	}
	float deltaValue = fromValue - computedToValue;
	return deltaValue;
}
float ColorFader::calcUpFade(float pressedPercent, float deltaValue, float lengthPercent){
	return ((deltaValue * lengthPercent) + pressedPercent);
}
float ColorFader::calcDownFade(float pressedPercent, float deltaValue, float lengthPercent){
	return (pressedPercent - (deltaValue * lengthPercent));
}
int ColorFader::reverse(float curPercent, float toValue, float fromValue, int tempLoopMode){
	int result = 0;
	float upDelta = calcUpDeltaValue(fromValue, toValue);
	float downDelta = calcDownDeltaValue(fromValue, toValue);
	float useDelta = 0;
	if(tempLoopMode == LTYPE_UP){
	//up always
		useDelta = upDelta;
	}else if(tempLoopMode == LTYPE_DOWN){
	//down always
		useDelta = downDelta;
	}else if(tempLoopMode == LTYPE_MIN){
	//shortest fade
		if(upDelta < downDelta){
			useDelta = upDelta;
		}else{
			useDelta = downDelta;
		}
	}else if(tempLoopMode == LTYPE_MAX){
	//longest fade
		if(upDelta > downDelta){
			useDelta = upDelta;
		}else{
			useDelta = downDelta;
		}

	}else{
	//tempLoopMode == LTYPE_NONE or undefined, no rotary
		if(fromValue > toValue){
			useDelta = downDelta;
		}else{
			useDelta = upDelta;
		}
	}
	result = (((curPercent-fromValue)/useDelta)*length);
	if(result < 1){
		result = result * -1;
	}
	return(result);
}

/** 
 * Assignment operator overload.
 * @author Jesse R. Castro
 * @param pFullFader An instance of the same type as this object.
 * @return This object (after it has been duplicated to the pFullFader parameter).
 */
ColorFader& ColorFader::operator=(const ColorFader &pColorFader){
	if(this != &pColorFader){
		index = pColorFader.index; 
		length = pColorFader.length; // In milliseconds!!!
		loopMode = pColorFader.loopMode; //for rotary looping only
		fading = pColorFader.fading;
	}
	return *this;
}

