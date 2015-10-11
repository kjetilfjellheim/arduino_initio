/*
 * Leg.h
 *
 *  Created on: 7 Oct 2015
 *      Author: Kjetil
 */

#ifndef LEG_H_
#define LEG_H_

#include <SoftwareSerial.h>

enum POSITION {
	FRONT, MIDDLE, BACK
};
enum SIDE {
	LEFT, RIGHT
};

class Leg {
	String engine1;
	String engine2;
	String engine3;
	int cal1;
	int cal2;
	int cal3;
	SoftwareSerial* softSerial;
	POSITION position;
	SIDE side;
public:
	Leg(String engine1, String engine2, String engine3, SoftwareSerial* serial, POSITION position, SIDE side, int cal1, int cal2, int cal3);
	void standStill();
private:
	void move(String engine, int p, String t);
};

#endif /* LEG_H_ */
