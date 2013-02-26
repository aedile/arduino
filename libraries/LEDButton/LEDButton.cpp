/*
  LEDButton.h - Implements the LEDButton class.
  Created by Jesse R. Castro 2013-02-15 21:27:15
  This file was created by the Generator Tool!
*/
#include "LEDButton.h"
/** 
 * Default class constructor for initializing with no values.
 * @author Jesse R. Castro
 */
LEDButton::LEDButton():
		address(), 	
		rest(), 	
		pressed(),
		current(),
		fader()
{ 		
	setFadeInLength(0);
	setFadeOutLength(0);
	setNumBounces(0);
	setBouncePercent(0.0);
	setHoldMode(false);
}
/** 
 * Copy class constructor for initializing with another instance of this class.
 * @author Jesse R. Castro
 * @param pLEDButton An instance of the same type as this object.
 */
LEDButton::LEDButton(const LEDButton& pLEDButton){
	*this = pLEDButton;
}
/** 
 * Class constructor for initializing with individual parameters.
 * @author Jesse R. Castro
 * @param pBar A float value representing Bar.
 */
LEDButton::LEDButton(int pFadeInLength, int pFadeOutLength, int pNumBounces, float pBouncePercent, bool pHoldMode, Address pAddress, Color pRest, Color pPressed):
	address(pAddress), 	
	rest(pRest), 	
	pressed(pPressed),
	current(pRest),
	fader(pFadeInLength, pFadeOutLength, LTYPE_MIN, pNumBounces, pBouncePercent)
{ 	
	setFadeInLength(pFadeInLength);
	setFadeOutLength(pFadeOutLength);
	setNumBounces(pNumBounces);
	setBouncePercent(pBouncePercent);
	setHoldMode(pHoldMode);
}
/** 
 * Class destructor for destroying the class when it falls out of scope.
 * @author Jesse R. Castro
 */
 LEDButton::~LEDButton(){

}
/** 
 * Setter method for internal variable fadeInLength.
 * @author Jesse R. Castro
 * @param pFadeInLength A int value to set internal private variable FadeInLength, which represents the amount of time for a fade in.
 */
void LEDButton::setFadeInLength(int pFadeInLength){
	fadeInLength = pFadeInLength;
}
/** 
 * Setter method for internal variable fadeOutLength.
 * @author Jesse R. Castro
 * @param pFadeOutLength A int value to set internal private variable FadeOutLength, which represents the amount of time for a fade out.
 */
void LEDButton::setFadeOutLength(int pFadeOutLength){
	fadeOutLength = pFadeOutLength;
}
/** 
 * Setter method for internal variable numBounces.
 * @author Jesse R. Castro
 * @param pNumBounces A int value to set internal private variable NumBounces, which represents the number of bounces after fading.
 */
void LEDButton::setNumBounces(int pNumBounces){
	numBounces = pNumBounces;
}
/** 
 * Setter method for internal variable bouncePercent.
 * @author Jesse R. Castro
 * @param pBouncePercent A float value to set internal private variable BouncePercent, which represents the percent to bounce of the original press.
 */
void LEDButton::setBouncePercent(float pBouncePercent){
	bouncePercent = pBouncePercent;
}
/** 
 * Setter method for internal variable holdMode.
 * @author Jesse R. Castro
 * @param pHoldMode A bool value to set internal private variable HoldMode, which represents whether or not to hold at peak press color.
 */
void LEDButton::setHoldMode(bool pHoldMode){
	holdMode = pHoldMode;
}
/** 
 * Setter method for internal variable buttonState.
 * @author Jesse R. Castro
 * @param pButtonState A bool value to set internal private variable ButtonState, which represents whether or not the button is being pressed.
 */
void LEDButton::setButtonState(bool pButtonState){
	buttonState = pButtonState;
}
/** 
 * Setter method for internal variable address.
 * @author Jesse R. Castro
 * @param pAddress A Address value to set internal private variable Address, which represents the pin addresses of the LED and button.
 */
void LEDButton::setAddress(Address pAddress){
	address = pAddress;
}
/** 
 * Setter method for internal variable rest.
 * @author Jesse R. Castro
 * @param pRest A Color value to set internal private variable Rest, which represents the resting color of the LED.
 */
void LEDButton::setRest(Color pRest){
	rest = pRest;
}
/** 
 * Setter method for internal variable pressed.
 * @author Jesse R. Castro
 * @param pPressed A Color value to set internal private variable Pressed, which represents the color of the LED at full press.
 */
void LEDButton::setPressed(Color pPressed){
	pressed = pPressed;
}
/** 
 * Setter method for internal variable current.
 * @author Jesse R. Castro
 * @param pCurrent A Color value to set internal private variable Current, which represents the current color of the LED.
 */
void LEDButton::setCurrent(Color pCurrent){
	current = pCurrent;
}
/** 
 * Setter method for internal variable fader.
 * @author Jesse R. Castro
 * @param pFader A FullFader value to set internal private variable Fader, which represents the fader for the LED.
 */
void LEDButton::setFader(FullFader pFader){
	fader = pFader;
}
/** 
 * Getter method for internal variable fadeInLength.
 * @author Jesse R. Castro
 * @return The value of internal private variable FadeInLength, which represents the amount of time for a fade in.
 */
int LEDButton::getFadeInLength(){
	return fadeInLength;
}
/** 
 * Getter method for internal variable fadeOutLength.
 * @author Jesse R. Castro
 * @return The value of internal private variable FadeOutLength, which represents the amount of time for a fade out.
 */
int LEDButton::getFadeOutLength(){
	return fadeOutLength;
}
/** 
 * Getter method for internal variable numBounces.
 * @author Jesse R. Castro
 * @return The value of internal private variable NumBounces, which represents the number of bounces after fading.
 */
int LEDButton::getNumBounces(){
	return numBounces;
}
/** 
 * Getter method for internal variable bouncePercent.
 * @author Jesse R. Castro
 * @return The value of internal private variable BouncePercent, which represents the percent to bounce of the original press.
 */
float LEDButton::getBouncePercent(){
	return bouncePercent;
}
/** 
 * Getter method for internal variable holdMode.
 * @author Jesse R. Castro
 * @return The value of internal private variable HoldMode, which represents whether or not to hold at peak press color.
 */
bool LEDButton::getHoldMode(){
	return holdMode;
}
/** 
 * Getter method for internal variable buttonState.
 * @author Jesse R. Castro
 * @return The value of internal private variable ButtonState, which represents whether or not the button is being pressed.
 */
bool LEDButton::getButtonState(){
	return buttonState;
}
/** 
 * Getter method for internal variable address.
 * @author Jesse R. Castro
 * @return The value of internal private variable Address, which represents the pin addresses of the LED and button.
 */
Address LEDButton::getAddress(){
	return address;
}
/** 
 * Getter method for internal variable rest.
 * @author Jesse R. Castro
 * @return The value of internal private variable Rest, which represents the resting color of the LED.
 */
Color LEDButton::getRest(){
	return rest;
}
/** 
 * Getter method for internal variable pressed.
 * @author Jesse R. Castro
 * @return The value of internal private variable Pressed, which represents the color of the LED at full press.
 */
Color LEDButton::getPressed(){
	return pressed;
}
/** 
 * Getter method for internal variable current.
 * @author Jesse R. Castro
 * @return The value of internal private variable Current, which represents the current color of the LED.
 */
Color LEDButton::getCurrent(){
	return current;
}
/** 
 * Getter method for internal variable fader.
 * @author Jesse R. Castro
 * @return The value of internal private variable Fader, which represents the fader for the LED.
 */
FullFader LEDButton::getFader(){
	return fader;
}
/** 
 * Getter method for result of private getter method address.getRedPin().
 * @author Jesse R. Castro
* @return The red pin address from internal private variable address.
 */
int LEDButton::getRedPin(){
	return address.getRedPin();
}
/** 
 * Getter method for result of private getter method address.getGreenPin().
 * @author Jesse R. Castro
 * @return The green pin address from internal private variable address.
 */
int LEDButton::getGreenPin(){
	return address.getGreenPin();
}
/** 
 * Getter method for result of private getter method address.getBluePin().
 * @author Jesse R. Castro
 * @return The blue pin address from internal private variable address.
 */
int LEDButton::getBluePin(){
	return address.getBluePin();
}
/** 
 * Getter method for result of private getter method current.getRed().
 * @author Jesse R. Castro
 * @return The red pin value of internal private variable current, which represents the current color of the button.
 */
int LEDButton::getRedValue(){
	return current.getRed();
}
/** 
 * Getter method for result of private getter method current.getGreen().
 * @author Jesse R. Castro
 * @return The green pin value of internal private variable current, which represents the current color of the button.
 */
int LEDButton::getGreenValue(){
	return current.getGreen();
}
/** 
 * Getter method for result of private getter method current.getBlue().
 * @author Jesse R. Castro
 * @return The blue pin value of internal private variable current, which represents the current color of the button.
 */
int LEDButton::getBlueValue(){
	return current.getBlue();
}
/**
 * Action method to initialize the LED button in the setup routine of the main program
 * @author Jesse R. Castro
 */
void LEDButton::setupFunc(){
  pinMode(address.getRedPin(), OUTPUT);
  pinMode(address.getGreenPin(), OUTPUT);
  pinMode(address.getBluePin(), OUTPUT);
  pinMode(address.getButtonPin(), INPUT_PULLUP);
}
/**
 * Action method to initialize the LED button object
 * @author Jesse R. Castro
 */
void LEDButton::init(){
	
}
/**
 * Checks for button press, performs actions and fades accordingly
 * @author Jesse R. Castro
 */
void LEDButton::mainPass(){
	//get button state
	if (digitalRead(address.getButtonPin()) == LOW) {
		//in this block, put anything you want to happen the very first time the button is pushed
		if(!buttonState){
			fader.startUpFade(rest, pressed, current);
		}
		//Serial.print("Button ");
		//Serial.print(address.getButtonPin());
		//Serial.println(" Pressed! ");
		//after this block put anything you want to happen while the button is held down
		buttonState = true;
	} else {
		//in this block, put anything you want to happen the first loop the button is let go
		if(buttonState){
			fader.startDownFade(rest, pressed, current);
		}
		//after this block, put anything you want to happen while the button is not pushed
		buttonState = false;
	}
	//fade
	current = fader.fade(rest, pressed, buttonState);
	//write to pins
	//analogWrite(address.getRedPin(), current.getRed());
	//analogWrite(address.getGreenPin(), current.getGreen());
	//analogWrite(address.getBluePin(), current.getBlue());
}

/** 
 * Assignment operator overload.
 * @author Jesse R. Castro
 * @param pLEDButton An instance of the same type as this object.
 * @return This object (after it has been duplicated to the pLEDButton parameter).
 */
LEDButton& LEDButton::operator=(const LEDButton &pLEDButton){
	if(this != &pLEDButton){
				fadeInLength = pLEDButton.fadeInLength;
				fadeOutLength = pLEDButton.fadeOutLength;
				numBounces = pLEDButton.numBounces;
				bouncePercent = pLEDButton.bouncePercent;
				holdMode = pLEDButton.holdMode;
				buttonState = pLEDButton.buttonState;
				
				address = pLEDButton.address;
				rest = pLEDButton.rest;
				pressed = pLEDButton.pressed;
				current = pLEDButton.current;
				fader = pLEDButton.fader;
				
	}
	return *this;
}
/** 
 * Comparison == operator overload.
 * @author Jesse R. Castro
 * @param pLEDButton An instance of the same type as this object.
 * @return A boolean value describing whether the objects are equivalent or not.
 */
bool LEDButton::operator==(const LEDButton &pLEDButton) const {
	if(
				(fadeInLength == pLEDButton.fadeInLength)&& 
				(fadeOutLength == pLEDButton.fadeOutLength)&& 
				(numBounces == pLEDButton.numBounces)&& 
				(bouncePercent == pLEDButton.bouncePercent)&& 
				(holdMode == pLEDButton.holdMode)&& 
				(buttonState == pLEDButton.buttonState)&& 
				
				(address == pLEDButton.address)&& 
				(rest == pLEDButton.rest)&& 
				(pressed == pLEDButton.pressed)&& 
				(current == pLEDButton.current)&& 
				(fader == pLEDButton.fader)
			
	){
		return true;
	}else{
		return false;
	}
}
/** 
 * Comparison != operator overload.
 * @author Jesse R. Castro
 * @param pLEDButton An instance of the same type as this object.
 * @return A boolean value describing the inverse of whether the objects are equivalent or not.
 */
bool LEDButton::operator!=(const LEDButton &pLEDButton) const {
	return !(*this == pLEDButton);
}