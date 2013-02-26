/*
  FullFader.h - Library for controlling RGB arcade buttons
  Created by Jesse R. Castro 2013-02-03
*/
#ifndef FullFader_h
#define FullFader_h

#include "Arduino.h"
#include <Common.h>
#include "../Color/Color.h"
#include "../ColorFader/ColorFader.h"
/** 
 * A complex up and down fader with bouncing.  
 * @author Jesse R. Castro
 * @version %I%, %G%
 * @see Fader, Color
 */
class FullFader
{
  public:
	//public vars
	
	//constructor
	FullFader();
    FullFader(const FullFader& pFullFader);
    FullFader(int pInLength,int pOutLength,int pLoopMode,int pBounces,float pBouncePercent);
	//destructor
	~FullFader();
	//setters
	void setInLength(int pInLength);
	void setOutLength(int pOutLength);
	void setLoopMode(int pLoopMode);
	void setBounces(int pBounces);
	void setBouncePercent(float pBouncePercent);
	//getters
	int getInLength();
	int getOutLength();
	int getLoopMode();
	int getBounces();
	float getBouncePercent();
	//action methods
	void init();
	void startUpFade();
	void startUpFade(const Color &pRest, const Color &pPressed, const Color &pCurrent);
	void startDownFade();
	void startDownFade(const Color &pRest, const Color &pPressed, const Color &pCurrent);
	const Color fade(const Color &pRest, const Color &pPressed, bool pButtonState);
	//operator overloads
	FullFader& operator=(const FullFader &pFullFader);
	bool operator==(const FullFader &pFullFader) const;
	bool operator!=(const FullFader &pFullFader) const;
	
  private:
    //private vars
	int inLength;
	int outLength;
	int loopMode;
	int bounces;
	int curbounces;
	
	float calcBouncePercent;
	float bouncePercent;
	
	bool bouncingUp;
	bool fading;
	ColorFader toPressedFader;
	ColorFader toRestFader;
	
	Color bounce;
	//setters

	//getters
	
	//action methods
	
	//utilities

};

#endif