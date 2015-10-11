/*
 * Tail.h
 *
 *  Created on: 11 Oct 2015
 *      Author: Kjetil
 */

#ifndef TAIL_H_
#define TAIL_H_

#include <SoftwareSerial.h>

class Tail {
	String sidewaysEngine;
	String liftEngine;
	int calSideways;
	int calLiftEngine;
	SoftwareSerial* softSerial;
public:
	Tail(String sidewaysEngine, String liftEngine, int calSideways, int calLiftEngine, SoftwareSerial* softSerial);
	void up();
	void down();
	void straight();
	void left();
	void right();
private:
	void move(String engine, int p, String t);
};

#endif /* TAIL_H_ */
