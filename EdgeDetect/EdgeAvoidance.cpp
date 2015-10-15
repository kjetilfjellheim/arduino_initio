// Do not remove the include below
#include "EdgeAvoidance.h"
#include "Servo.h"
#include <Math.h>

Servo panServo;
Servo tiltServo;

const int panFullRight = 90;
const int panFullLeft = 160;
const int panCentre = 125;
const int tiltCentre = 18;
const int tiltFullDown = 90;


const int TILT_PIN = 13;
const int PAN_PIN = 12;

const int RIGHT_ENGINE_PIN = 9;
const int RIGHT_ENGINE_PWM_PIN = 8;
const int LEFT_ENGINE_PIN = 7;
const int LEFT_ENGINE_PWM_PIN = 6;

const int LEFT_MOTOR_SENSOR_PIN = 4;
const int RIGHT_MOTOR_SENSOR_PIN = 6;

const int ULTRASONIC_SENSOR_ECHO_PIN = A5;
const int ULTRASONIC_SENSOR_TRG_PIN = A3;

const int CMVCONV = 59;

//The setup function is called once at startup of the sketch
void setup()
{
	Serial.begin(9600);
	panServo.attach(PAN_PIN);
	tiltServo.attach(TILT_PIN);
	panServo.write(panCentre);
	tiltServo.write(tiltCentre);
	delay(1000);

	pinMode(LEFT_ENGINE_PIN, OUTPUT);
	pinMode(LEFT_ENGINE_PWM_PIN, OUTPUT);
	pinMode(RIGHT_ENGINE_PIN, OUTPUT);
	pinMode(RIGHT_ENGINE_PWM_PIN, OUTPUT);

	pinMode(LEFT_MOTOR_SENSOR_PIN, INPUT);
	pinMode(RIGHT_MOTOR_SENSOR_PIN, INPUT);

	pinMode(ULTRASONIC_SENSOR_ECHO_PIN, INPUT);
	pinMode(ULTRASONIC_SENSOR_TRG_PIN, OUTPUT);

	delay(1000);
	struct Edge left = detectEdge(panFullLeft);
	struct Edge right = detectEdge(panFullRight);
	setClosest(left, right);
	startEngine();
}

// The loop function is called in an endless loop
void loop()
{
	moveToEdge();
}

void startEngine() {
	digitalWrite(LEFT_ENGINE_PIN, LOW);
	analogWrite(LEFT_ENGINE_PWM_PIN, 150);
	digitalWrite(RIGHT_ENGINE_PIN, LOW);
	analogWrite(RIGHT_ENGINE_PWM_PIN, 150);
}

void setClosest(Edge left, Edge right) {
	if (left.tilt < right.tilt) {
		panServo.write(panFullRight);
		tiltServo.write(tiltFullDown);
	} else {
		panServo.write(panFullLeft);
		tiltServo.write(tiltFullDown);
	}
}

struct Edge detectEdge(int pan) {
	struct Edge edge;
	panServo.write(pan);
	tiltServo.write(tiltFullDown);
	delay(300);
	int prevDistance = getDistance();
	for (int tilt = tiltFullDown; tilt > tiltCentre; tilt=tilt-5) {
		tiltServo.write(tilt);
		delay(100);
		int distance1 = -1;
		int distance2 = 1;
		while (distance1 != distance2) {
			distance1 = getDistance();
			delay(100);
			distance2 = getDistance();
		}
		int change = distance1 - prevDistance;
		if (change > 40) {
			edge.distance = prevDistance;
			edge.tilt = tilt;
			return edge;
		} else {
			prevDistance = distance1;
		}
	}
	edge.distance = prevDistance;
	edge.tilt = tiltCentre;
	return edge;
}

int getDistance() {
	digitalWrite(ULTRASONIC_SENSOR_TRG_PIN, LOW);
	delayMicroseconds(2);
	digitalWrite(ULTRASONIC_SENSOR_TRG_PIN, HIGH);
	delayMicroseconds(5);
	digitalWrite(ULTRASONIC_SENSOR_TRG_PIN, LOW);
	int duration = pulseIn(ULTRASONIC_SENSOR_ECHO_PIN, HIGH);
	return duration / CMVCONV;
}

void moveToEdge() {
	if (getDistance() > 40) {
		digitalWrite(LEFT_ENGINE_PIN, LOW);
		analogWrite(LEFT_ENGINE_PWM_PIN, 0);
		digitalWrite(RIGHT_ENGINE_PIN, LOW);
		analogWrite(RIGHT_ENGINE_PWM_PIN, 0);
	}
}

