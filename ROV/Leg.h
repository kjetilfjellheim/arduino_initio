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
	POSITION position;
	SIDE side;
public:
	Leg(String engine1, String engine2, String engine3, POSITION position, SIDE side, int cal1, int cal2, int cal3);
	String standStill();
	String lieDown();
private:
	String move(String engine, int p);
};

#endif /* LEG_H_ */
