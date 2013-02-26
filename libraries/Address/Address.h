/*
  Address.h - Library for controlling RGB arcade buttons
  Created by Jesse R. Castro 2013-02-03
*/
#ifndef Address_h
#define Address_h

#include "Arduino.h"
#include <Common.h>
/** 
 * This class keeps an individual buttons address for input and RGB out.  Should be flexible enough to drop in based on
 * multiple methods of multiplexing buttons with simple integer representation.  Abstraction happens at the controller level.
 * @author Jesse R. Castro
 * @version %I%, %G%
 * @see AnotherClass
 */
class Address
{
  public:
	//public vars
	
	//constructor
	Address();
    Address(const Address& pAddress);
    Address(int pButtonPin, int pRedPin, int pGreenPin, int pBluePin);
	//destructor
	~Address();
	//setters
	void setButtonPin(int pButtonPin);
	void setRedPin(int pRedPin);
	void setGreenPin(int pGreenPin);
	void setBluePin(int pBluePin);
	//getters
	int getButtonPin();
	int getRedPin();
	int getGreenPin();
	int getBluePin();
	//action methods
	
	//operator overloads
	Address& operator=(const Address &pAddress);
	bool operator==(const Address &pAddress) const;
	bool operator!=(const Address &pAddress) const;

  private:
    //private vars
	int buttonPin;
	int redPin;
	int greenPin;
	int bluePin;
	
	//setters

	//getters
	
	//action methods
	
	//utilities

};

#endif