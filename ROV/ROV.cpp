// Do not remove the include below
#include "ROV.h"
#include <SoftwareSerial.h>
#include "Leg.h"
#include "Tail.h"

#define MOTOR_CONTROL_BAUD 115200
#define MOTORCTRL_TX 14
#define MOTORCTRL_RX 15

SoftwareSerial motorControl(MOTORCTRL_RX, MOTORCTRL_TX);
Leg legFrontLeft("5", "6", "7", &motorControl, FRONT, LEFT, 0, 25, -125);
Leg legMiddleLeft("8", "9", "10", &motorControl, MIDDLE, LEFT, -300, 425, -100);
Leg legBackLeft("11", "12", "13", &motorControl, BACK, LEFT, 800, -325, -150);
Leg legFrontRight("17", "18", "19", &motorControl, FRONT, RIGHT, 0, -300, 100);
Leg legMiddleRight("20", "21", "22", &motorControl, MIDDLE, RIGHT, -150, -100, 0);
Leg legBackRight("23", "24", "25", &motorControl, BACK, RIGHT, -800, -50, 50);

Tail tail("30", "31", 500, -250, &motorControl);

//The setup function is called once at startup of the sketch
void setup() {
	Serial.begin(9600);
	delay(1000);
	motorControl.begin(MOTOR_CONTROL_BAUD);
	delay(2000);
	tail.up();
	stand();
}

// The loop function is called in an endless loop
void loop() {

}

void lieDown() {
	// Move all legs to center position
	// Lower all
}

void sit() {
	// Move all legs to center position
}

void stand() {
	legFrontLeft.standStill();
	legFrontRight.standStill();
	legMiddleLeft.standStill();
	legMiddleRight.standStill();
	legBackLeft.standStill();
	legBackRight.standStill();
}

