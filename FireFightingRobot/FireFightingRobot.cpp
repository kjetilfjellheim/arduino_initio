// Do not remove the include below
#include "FireFightingRobot.h"

#define RIGHT_ENGINE_PIN 9
#define RIGHT_ENGINE_PWM_PIN 10
#define LEFT_ENGINE_PIN 6
#define LEFT_ENGINE_PWM_PIN 5
#define FLAME_SENSOR_PIN A0

#define FLAME_INITIAL_DETECTION_LIMIT 20

#define FLAME_STOP_LIMIT 200

#define START_BEHAVIOUR 0
#define LOOK_FOR_FIRE 0
#define CENTER_ON_FIRE 1
#define MOVE_TO_FIRE 2
#define WATER_TIME 3

int behaviours[4] = { LOOK_FOR_FIRE, CENTER_ON_FIRE, MOVE_TO_FIRE, WATER_TIME };

int currentBehaviour = START_BEHAVIOUR;

//The setup function is called once at startup of the sketch
void setup() {
	pinMode(FLAME_SENSOR_PIN, INPUT);
	pinMode(RIGHT_ENGINE_PIN, OUTPUT);
	pinMode(RIGHT_ENGINE_PWM_PIN, OUTPUT);
	pinMode(LEFT_ENGINE_PIN, OUTPUT);
	pinMode(LEFT_ENGINE_PWM_PIN, OUTPUT);
	Serial.begin(9600);
	delay(1000);
}

// The loop function is called in an endless loop
void loop() {
	switch (currentBehaviour) {
	case LOOK_FOR_FIRE:
		lookForFire();
		break;
	case CENTER_ON_FIRE:
		centerOnFire();
		break;
	case MOVE_TO_FIRE:
		moveToFire();
		break;
	case WATER_TIME:
		waterTime();
		break;
	}

}

void lookForFire() {
	runStraight();
	int flameSensorVal = getFlameSensorValue();
	if (flameSensorVal > FLAME_INITIAL_DETECTION_LIMIT) {
		currentBehaviour = CENTER_ON_FIRE;
	}
}


void centerOnFire() {
	rotateRight();
	int flameSensorValPrev = getFlameSensorValue();
	delay(2000);
	int flameSensorValcurrent = getFlameSensorValue();
	if (flameSensorValcurrent < flameSensorValPrev) {
		rotateLeft();
	}
	flameSensorValPrev = getFlameSensorValue();
	delay(200);
	flameSensorValcurrent = getFlameSensorValue();
	while (flameSensorValPrev < flameSensorValcurrent) {
		flameSensorValPrev = flameSensorValcurrent;
		int flameSensorValcurrent = getFlameSensorValue();
		delay(100);
	}
}

void moveToFire() {

}

void waterTime() {

}

void runStraight() {
	digitalWrite(LEFT_ENGINE_PIN, HIGH);
	analogWrite(LEFT_ENGINE_PWM_PIN, 0);
	digitalWrite(RIGHT_ENGINE_PIN, HIGH);
	analogWrite(RIGHT_ENGINE_PWM_PIN, 0);
}

void rotateRight() {
	digitalWrite(LEFT_ENGINE_PIN, HIGH);
	analogWrite(LEFT_ENGINE_PWM_PIN, 50);
	digitalWrite(RIGHT_ENGINE_PIN, LOW);
	analogWrite(RIGHT_ENGINE_PWM_PIN, 255);
}

void rotateLeft() {
	digitalWrite(LEFT_ENGINE_PIN, LOW);
	analogWrite(LEFT_ENGINE_PWM_PIN, 0);
	digitalWrite(RIGHT_ENGINE_PIN, HIGH);
	analogWrite(RIGHT_ENGINE_PWM_PIN, 255);
}

void stop() {
	digitalWrite(LEFT_ENGINE_PIN, HIGH);
	analogWrite(LEFT_ENGINE_PWM_PIN, 0);
	digitalWrite(RIGHT_ENGINE_PIN, HIGH);
	analogWrite(RIGHT_ENGINE_PWM_PIN, 0);
}

int getFlameSensorValue() {
	return analogRead(FLAME_SENSOR_PIN);
}
