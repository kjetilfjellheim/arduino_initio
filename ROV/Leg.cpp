/*
 * Leg.cpp
 *
 *  Created on: 7 Oct 2015
 *      Author: Kjetil
 */

#include "Leg.h"
#include <SoftwareSerial.h>
#include "Arduino.h"

Leg::Leg(String engine1, String engine2, String engine3, SoftwareSerial* softSerial, POSITION position, SIDE side, int cal1, int cal2, int cal3) {
	this->engine1 = engine1;
	this->engine2 = engine2;
	this->engine3 = engine3;
	this->softSerial = softSerial;
	this->side = side;
	this->position = position;
	this->cal1 = cal1;
	this->cal2 = cal2;
	this->cal3 = cal3;
}

void Leg::standStill() {
	move(engine1, 1500 + cal1, "1000");
	delay(1000);
	move(engine3, 1500 + cal3, "1000");
	delay(1000);
	move(engine2, 1500 + cal2, "1000");
	delay(2000);
}

void Leg::move(String engine, int p, String t) {
	String pStr = String(p);
	String str = "#" + engine + "P" + pStr + "T" + t + "\r";
	(*softSerial).print(str);
}

