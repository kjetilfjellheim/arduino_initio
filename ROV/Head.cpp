/*
 * Head.cpp
 *
 *  Created on: 12 Oct 2015
 *      Author: Kjetil
 */

#include "Head.h"
#include <SoftwareSerial.h>
#include "Arduino.h"

Head::Head(String rollEngine, String heightEngine, String sidewaysEngine, String leftClawEngine, String rightClawEngine, int rollCal, int heightCal, int sidewaysCal, int leftClwaCal, int rightClawCal) {
	this->rollEngine=rollEngine;
	this->heightEngine=heightEngine;
	this->sidewaysEngine=sidewaysEngine;
	this->leftClawEngine=leftClawEngine;
	this->rightClawEngine=rightClawEngine;
	this->rollCal=rollCal;
	this->heightCal=heightCal;
	this->sidewaysCal=sidewaysCal;
	this->leftClawCal=leftClwaCal;
	this->rightClawCal=rightClawCal;
}

String Head::straight() {
	String cmd = move(rollEngine, 1500 - rollCal);
	cmd.concat(move(heightEngine, 1500 - heightCal));
	cmd.concat(move(sidewaysEngine, 1500 - sidewaysCal));
	cmd.concat(closeClaw());
	return cmd;
}

String Head::openClaw() {
	String cmd = move(leftClawEngine, 1500 - leftClawCal + CLAW_RT);
	cmd.concat(move(rightClawEngine, 1500 - rightClawCal - CLAW_RT));
	return cmd;
}

String Head::closeClaw() {
	String cmd = move(leftClawEngine, 1500 - leftClawCal);
	cmd.concat(move(rightClawEngine, 1500 - rightClawCal));
	return cmd;
}

String Head::bite() {
	String cmd = move(leftClawEngine, 1500 - leftClawCal - CLAW_RT);
	cmd.concat(move(rightClawEngine, 1500 - rightClawCal + CLAW_RT));
	return cmd;
}

String Head::rotate(int value) {
	return move(rollEngine, 1500 - rollCal - value);
}

String Head::height(int value) {
	return move(heightEngine, 1500 - heightCal - value);
}


String Head::move(String engine, int p) {
	String pStr = String(p);
	return "#" + engine + "P" + pStr;
}
