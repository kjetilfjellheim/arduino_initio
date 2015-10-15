/*
 * Tail.cpp
 *
 *  Created on: 11 Oct 2015
 *      Author: Kjetil
 */

#include "Tail.h"
#include "Arduino.h"

Tail::Tail(String sidewaysEngine, String liftEngine, int calSideways, int calLiftEngine, SoftwareSerial* softSerial) {
	this->calLiftEngine = calLiftEngine;
	this->calSideways = calSideways;
	this->liftEngine = liftEngine;
	this->sidewaysEngine = sidewaysEngine;
	this->softSerial = softSerial;
}

void Tail::up() {
	move(liftEngine, 2500 - calLiftEngine, "1000");
	delay(1000);
}

void Tail::down() {
	move(liftEngine, 800 - calLiftEngine, "1000");
	delay(1000);
}

void Tail::left() {
	move(sidewaysEngine, 1200 - calSideways, "1000");
	delay(1000);
}

void Tail::right() {
	move(sidewaysEngine, 2000 - calSideways, "1000");
	delay(1000);
}

void Tail::straight() {
	move(liftEngine, 1500 - calLiftEngine, "1000");
	delay(1000);
	move(sidewaysEngine, 1500 - calSideways, "1000");
	delay(1000);
}

void Tail::move(String engine, int p, String t) {
	String pStr = String(p);
	String str = "#" + engine + "P" + pStr + "T" + t + "\r";
	(*softSerial).print(str);
}
