/*
 * Leg.cpp
 *
 *  Created on: 7 Oct 2015
 *      Author: Kjetil
 */

#include "Leg.h"
#include <SoftwareSerial.h>
#include "Arduino.h"

Leg::Leg(String engine1, String engine2, String engine3, POSITION position, SIDE side, int cal1, int cal2, int cal3) {
	this->engine1 = engine1;
	this->engine2 = engine2;
	this->engine3 = engine3;
	this->side = side;
	this->position = position;
	this->cal1 = cal1;
	this->cal2 = cal2;
	this->cal3 = cal3;
}

String Leg::standStill() {
	String cmd = move(engine1, 1500 + cal1);
	cmd.concat(move(engine3, 1500 + cal3));
	cmd.concat(move(engine2, 1500 + cal2));
	return cmd;
}

String Leg::lieDown() {
	String cmd = move(engine1, 1500 + cal1);
	delay(1000);
	if (side == LEFT) {
		cmd.concat(move(engine3, 500 + cal3));
		cmd.concat(move(engine2, 500 + cal2));
	} else {
		cmd.concat(move(engine3, 2500 + cal3));
		cmd.concat(move(engine2, 2500 + cal2));
	}
	return cmd;
}

String Leg::move(String engine, int p) {
	String pStr = String(p);
	return String("#" + engine + "P" + pStr);
}

