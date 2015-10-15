// Do not remove the include below
#include "ROV.h"
#include <SoftwareSerial.h>
#include "Leg.h"
#include "Tail.h"
#include "Head.h"

#define MOTOR_CONTROL_BAUD 115200
#define MOTORCTRL_TX 14
#define MOTORCTRL_RX 15

SoftwareSerial motorControl(MOTORCTRL_RX, MOTORCTRL_TX);
Leg legFrontLeft("5", "6", "7", FRONT, LEFT, 0, 25, -125);
Leg legMiddleLeft("8", "9", "10", MIDDLE, LEFT, -300, 425, -100);
Leg legBackLeft("11", "12", "13", BACK, LEFT, 800, 500, -300);
Leg legFrontRight("17", "18", "19", FRONT, RIGHT, 0, -300, 100);
Leg legMiddleRight("20", "21", "22", MIDDLE, RIGHT, -150, 0, 0);
Leg legBackRight("23", "24", "25", BACK, RIGHT, -800, 0, 0);

Tail tail("30", "31", 600, -250, &motorControl);

Head head("4", "2", "3", "1", "0", 0, -450, 400, 250, 250);

//The setup function is called once at startup of the sketch
void setup() {
	Serial.begin(9600);
	delay(1000);
	motorControl.begin(MOTOR_CONTROL_BAUD);
	delay(2000);
	headStraight();
	delay(2000);
	openClaw();
	delay(2000);
	closeClaw();
	delay(2000);
	stand();
	delay(2000);
	lieDown();
}

// The loop function is called in an endless loop
void loop() {

}

void lieDown() {
	String cmd = legFrontLeft.lieDown();
	cmd.concat(legFrontRight.lieDown());
	cmd.concat(legMiddleLeft.lieDown());
	cmd.concat(legMiddleRight.lieDown());
	cmd.concat(legBackLeft.lieDown());
	cmd.concat(legBackRight.lieDown());
	cmd.concat("T3000\r");
	motorControl.print(cmd);
	delay(3000);
}


void stand() {
	String cmd = legFrontLeft.standStill();
	cmd.concat(legFrontRight.standStill());
	cmd.concat(legMiddleLeft.standStill());
	cmd.concat(legMiddleRight.standStill());
	cmd.concat(legBackLeft.standStill());
	cmd.concat(legBackRight.standStill());
	cmd.concat("T3000\r");
	motorControl.print(cmd);
	delay(3000);
}

void headStraight() {
	String cmd = head.straight();
	cmd.concat("T3000\r");
	motorControl.print(cmd);
	delay(3000);
}

void openClaw() {
	String cmd = head.openClaw();
	cmd.concat("T1000\r");
	motorControl.print(cmd);
	delay(2000);
}

void closeClaw() {
	String cmd = head.closeClaw();
	cmd.concat("T1000\r");
	motorControl.print(cmd);
	delay(2000);
}


