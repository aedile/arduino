/*
  FullFader.cpp - Template library to start new classes
  Created by Jesse R. Castro 2013-02-08
*/
#include "FullFader.h"
/** 
 * Default class constructor for initializing with no values.
 * @author Jesse R. Castro
 */
FullFader::FullFader(){
	setInLength(0);
	setOutLength(0);
	setLoopMode(LTYPE_NONE);
	setBounces(0);
	setBouncePercent(0);
	init();
}
/** 
 * Copy class constructor for initializing with another instance of this class.
 * @author Jesse R. Castro
 * @param pFullFader An instance of the same type as this object.
 */
FullFader::FullFader(const FullFader& pFullFader){
	*this = pFullFader;
}
/** 
 * Class constructor for initializing with individual parameters.
 * @author Jesse R. Castro
 * @param pInLength An integer representing the number of milliseconds to fade in.  Should be divisible by global delay.
 * @param pOutLength An integer representing the number of milliseconds to fade out.  Should be divisible by global delay.
 * @param pLoopMode The way to handle fading for hue that rolls over 1.  
 * @param pBounces The number of times to bounce after the initial fade is complete.
 */
FullFader::FullFader(int pInLength,int pOutLength,int pLoopMode,int pBounces, float pBouncePercent){
	setInLength(pInLength);
	setOutLength(pOutLength);
	setLoopMode(pLoopMode);
	setBounces(pBounces);
	setBouncePercent(pBouncePercent);
	init();
}
/** 
 * Class destructor for destroying the class when it falls out of scope.
 * @author Jesse R. Castro
 */
FullFader::~FullFader(){

}
/** 
 * Setter method for internal variable inLength.
 * @author Jesse R. Castro
 * @param pInLength An integer value representing the number of milliseconds to fade in.
 */
void FullFader::setInLength(int pInLength){
	inLength = pInLength;
}
/** 
 * Setter method for internal variable inLength.
 * @author Jesse R. Castro
 * @param pInLength An integer value representing the number of milliseconds to fade out.
 */
void FullFader::setOutLength(int pOutLength){
	outLength = pOutLength;
}
/** 
 * Setter method for internal variable loopMode.
 * @author Jesse R. Castro
 * @param pInLength An integer value representing the way to handle rotary fades
 */
void FullFader::setLoopMode(int pLoopMode){
	loopMode = pLoopMode;
}
/** 
 * Setter method for internal variable inLength.
 * @author Jesse R. Castro
 * @param pInLength An integer value representing the number of times to bounce after the initial fade is done
 */
void FullFader::setBounces(int pBounces){
	bounces = pBounces;
}
/** 
 * Setter method for internal variable inLength.
 * @author Jesse R. Castro
 * @param pInLength An integer value representing the number of times to bounce after the initial fade is done
 */
void FullFader::setBouncePercent(float pBouncePercent){
	if(pBouncePercent <= 1){
		if(pBouncePercent >= 0){
			bouncePercent = pBouncePercent;
		}else{
			bouncePercent = 0;
		}
	}else{
		bouncePercent = 1;
	}
	
	
}
/** 
 * Getter method for internal variable inLength.
 * @author Jesse R. Castro
 * @return The value of internal private variable inLength, an integer representing the number of milliseconds to fade in.
 */
int FullFader::getInLength(){
	return inLength;
}
/** 
 * Getter method for internal variable outLength.
 * @author Jesse R. Castro
 * @return The value of internal private variable outLength, an integer representing the number of milliseconds to fade out.
 */
int FullFader::getOutLength(){
	return outLength;
}
/** 
 * Getter method for internal variable loopMode.
 * @author Jesse R. Castro
 * @return The value of internal private variable loopMode, an integer value that determines how rotary fades are handled.
 */
int FullFader::getLoopMode(){
	return loopMode;
}
/** 
 * Getter method for internal variable bounces.
 * @author Jesse R. Castro
 * @return The value of internal private variable bounces, an integer representing the number of times to bounce after primary fade.
 */
int FullFader::getBounces(){
	return bounces;
}
/** 
 * Getter method for internal variable bounces.
 * @author Jesse R. Castro
 * @return The value of internal private variable bouncePercent, an float representing how high to bounce
 */
float FullFader::getBouncePercent(){
	return bouncePercent;
}
/** 
 * Action method to initialize the fader before a fade begins.
 * @author Jesse R. Castro
 */
void FullFader::init(){
	//fader initialization
	toPressedFader.setLength(inLength);
	toPressedFader.setLoopMode(loopMode);
	toRestFader.setLength(outLength);
	toRestFader.setLoopMode(loopMode);
	bouncingUp = false;
	fading = false;
	curbounces = 0;
	toPressedFader.setLength(inLength);
	toRestFader.setLength(outLength);
}
/** 
 * Action method to begin fading up.  Called on button press.
 * @author Jesse R. Castro
 */
void FullFader::startUpFade(){
	//fader initialization
	toPressedFader.startFade();
	init();
	fading = true;
}
/** 
 * Action method to begin fading up.  Called on button press.  Overload for mid-fade start
 * @author Jesse R. Castro
 */
void FullFader::startUpFade(const Color &pRest, const Color &pPressed, const Color &pCurrent){
	//fader initialization
	toPressedFader.startFade(pRest, pPressed, pCurrent);
	init();
	fading = true;
}
/** 
 * Action method to begin fading down.  Called on button release.
 * @author Jesse R. Castro
 */
void FullFader::startDownFade(){
	//fader initialization
	toRestFader.startFade();
}
/** 
 * Action method to begin fading down.  Called on button press.  Overload for mid-fade start
 * @author Jesse R. Castro
 */
void FullFader::startDownFade(const Color &pRest, const Color &pPressed, const Color &pCurrent){
	//fader initialization
	toRestFader.startFade(pPressed, pRest, pCurrent);
}
/** 
 * Action method to return the current color on the fade curve.  Called each pass.  
 * @author Jesse R. Castro
 */
const Color FullFader::fade(const Color &pRest, const Color &pPressed, bool pButtonState){
	Color current;
	if(!fading){
		return pRest;
	}else if (pButtonState) {
		//button is down, move from rest to pressed	
		current = toPressedFader.fade(pRest, pPressed);
		bounce = current;
		if(current == pPressed){
			//we are at our peak
			
		}
	} else {
		//button is up, move from rest to pressed
		if(bouncingUp){
			current = toPressedFader.fade(pRest, bounce);
		}else{
			current = toRestFader.fade(bounce, pRest);
		}
		if(current == bounce){
			//at the bounce peak
			bouncingUp = false;
			//Serial.println("Setting Bouncing Up to FALSE");
		}else if(current == pRest){
			//at our from color
			//here we perform our bounce
			calcBouncePercent = ((float)(bounces - curbounces)/bounces);
			if(calcBouncePercent == 0){
				bouncingUp = false;
				fading = false;
			}else{
				float fadeToPercent = bouncePercent * calcBouncePercent;
				bounce = toPressedFader.fadeToPercent(pRest, bounce, fadeToPercent);
				curbounces++;
				bouncingUp = true;
				toPressedFader.setIndex(2);
				toRestFader.setIndex(2);
				
				int newInLength = round((float)inLength * fadeToPercent);
				newInLength = newInLength - (newInLength % GLOBAL_DELAY);
				int newOutLength = round((float)outLength * fadeToPercent);
				newOutLength = newOutLength - (newOutLength % GLOBAL_DELAY);
				toPressedFader.setLength(newInLength);
				toRestFader.setLength(newOutLength);
			}	
		}else{
			//somewhere in between
		}
	}
	return current;
}
/** 
 * Assignment operator overload.
 * @author Jesse R. Castro
 * @param pFullFader An instance of the same type as this object.
 * @return This object (after it has been duplicated to the pFullFader parameter).
 */
FullFader& FullFader::operator=(const FullFader &pFullFader){
	if(this != &pFullFader){
		inLength = pFullFader.inLength;
		outLength = pFullFader.outLength;
		loopMode = pFullFader.loopMode;
		bounces = pFullFader.bounces;
		bouncePercent = pFullFader.bouncePercent;
	}
	init();
	return *this;
}
/** 
 * Comparison == operator overload.
 * @author Jesse R. Castro
 * @param pFullFader An instance of the same type as this object.
 * @return A boolean value describing whether the objects are equivalent or not.
 */
bool FullFader::operator==(const FullFader &pFullFader) const {
	if(
		(inLength  == pFullFader.inLength)&&
		(outLength == pFullFader.outLength)&&
		(loopMode  == pFullFader.loopMode)&&
		(bounces   == pFullFader.bounces)&&
		(bouncePercent   == pFullFader.bouncePercent)
	){
		return true;
	}else{
		return false;
	}
}
/** 
 * Comparison != operator overload.
 * @author Jesse R. Castro
 * @param pFullFader An instance of the same type as this object.
 * @return A boolean value describing the inverse of whether the objects are equivalent or not.
 */
bool FullFader::operator!=(const FullFader &pFullFader) const {
	return !(*this == pFullFader);
}