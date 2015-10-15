/*
 * Head.h
 *
 *  Created on: 12 Oct 2015
 *      Author: Kjetil
 */

#ifndef HEAD_H_
#define HEAD_H_

#include <SoftwareSerial.h>
#include "Arduino.h"

class Head {
	String rollEngine;
	String heightEngine;
	String sidewaysEngine;
	String leftClawEngine;
	String rightClawEngine;
	int rollCal;
	int heightCal;
	int sidewaysCal;
	int leftClawCal;
	int rightClawCal;
	const static int CLAW_RT = 600;
public:
	Head(String rollEngine, String heightEngine, String sidewaysEngine, String leftClawEngine, String rightClawEngine, int rollCal, int heightCal, int sidewaysCal, int leftClwaCal, int rightClawCal);
	String straight();
	String openClaw();
	String closeClaw();
	String bite();
	String rotate(int value);
	String height(int value);
private:
	String move(String engine, int p);
};

#endif /* HEAD_H_ */
