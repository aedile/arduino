/*
  Address.cpp - Template library to start new classes
  Created by Jesse R. Castro 2013-02-08
*/
#include "Address.h"
/** 
 * Default class constructor for initializing with no values.
 * @author Jesse R. Castro
 */
Address::Address(){
	setButtonPin(0);
	setRedPin(0);
	setGreenPin(0);
	setBluePin(0);
}
/** 
 * Copy class constructor for initializing with another instance of this class.
 * @author Jesse R. Castro
 * @param pAddress An instance of the same type as this object.
 */
Address::Address(const Address& pAddress){
	*this = pAddress;
}
/** 
 * Class constructor for initializing with individual parameters.
 * @author Jesse R. Castro
 * @param pButtonPin An int value representing the address of the pin controlling the button (or MUX address).
 * @param pRedPin An int value representing the address of the pin controlling the red led channel (or MUX address).
 * @param pGreenPin An int value representing the address of the pin controlling the green led channel (or MUX address).
 * @param pBluePin An int value representing the address of the pin controlling the blue led channel (or MUX address).
 */
Address::Address(int pButtonPin, int pRedPin, int pGreenPin, int pBluePin){
	setButtonPin(pButtonPin);
	setRedPin(pRedPin);
	setGreenPin(pGreenPin);
	setBluePin(pBluePin);
}
/** 
 * Class destructor for destroying the class when it falls out of scope.
 * @author Jesse R. Castro
 */
 Address::~Address(){

}
/** 
 * Setter method for internal variable buttonPin.
 * @author Jesse R. Castro
 * @param pButtonPin An int value representing the address of the pin controlling the button (or MUX address).
 */
void Address::setButtonPin(int pButtonPin){
	buttonPin = pButtonPin;
}
/** 
 * Setter method for internal variable redPin.
 * @author Jesse R. Castro
 * @param pButtonPin An int value representing the address of the pin controlling the red led channel (or MUX address).
 */
void Address::setRedPin(int pRedPin){
	redPin = pRedPin;
}
/** 
 * Setter method for internal variable greenPin.
 * @author Jesse R. Castro
 * @param pButtonPin An int value representing the address of the pin controlling the green led channel (or MUX address).
 */
void Address::setGreenPin(int pGreenPin){
	greenPin = pGreenPin;
}
/** 
 * Setter method for internal variable bluePin.
 * @author Jesse R. Castro
 * @param pButtonPin An int value representing the address of the pin controlling the blue led channel (or MUX address).
 */
void Address::setBluePin(int pBluePin){
	bluePin = pBluePin;
}
/** 
 * Getter method for internal variable buttonPin.
 * @author Jesse R. Castro
 * @return The value (int) of internal private variable buttonPin, the address of the pin controlling the button (or MUX address).
 */
int Address::getButtonPin(){
	return buttonPin;
}
/** 
 * Getter method for internal variable redPin.
 * @author Jesse R. Castro
 * @return The value (int) of internal private variable redPin, the address of the pin controlling the red led channel (or MUX address).
 */
int Address::getRedPin(){
	return redPin;
}
/** 
 * Getter method for internal variable greenPin.
 * @author Jesse R. Castro
 * @return The value (int) of internal private variable greenPin, the address of the pin controlling the green led channel (or MUX address).
 */
int Address::getGreenPin(){
	return greenPin;
}
/** 
 * Getter method for internal variable bluePin.
 * @author Jesse R. Castro
 * @return The value (int) of internal private variable bluePin, the address of the pin controlling the blue led channel (or MUX address).
 */
int Address::getBluePin(){
	return bluePin;
}
/** 
 * Assignment operator overload.
 * @author Jesse R. Castro
 * @param pAddress An instance of the same type as this object.
 * @return This object (after it has been duplicated to the pAddress parameter).
 */
Address& Address::operator=(const Address &pAddress){
	if(this != &pAddress){
		buttonPin = pAddress.buttonPin;
		redPin = pAddress.redPin;
		greenPin = pAddress.greenPin;
		bluePin = pAddress.bluePin;
	}
	return *this;
}
/** 
 * Comparison == operator overload.
 * @author Jesse R. Castro
 * @param pAddress An instance of the same type as this object.
 * @return A boolean value describing whether the objects are equivalent or not.
 */
bool Address::operator==(const Address &pAddress) const {
	if(
		(buttonPin == pAddress.buttonPin)&&
		(redPin == pAddress.redPin)&&
		(greenPin == pAddress.greenPin)&&
		(bluePin == pAddress.bluePin)
	){
		return true;
	}else{
		return false;
	}
}
/** 
 * Comparison != operator overload.
 * @author Jesse R. Castro
 * @param pAddress An instance of the same type as this object.
 * @return A boolean value describing the inverse of whether the objects are equivalent or not.
 */
bool Address::operator!=(const Address &pAddress) const {
	return !(*this == pAddress);
}