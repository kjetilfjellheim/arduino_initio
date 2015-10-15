// Only modify this file to include
// - function definitions (prototypes)
// - include files
// - extern variable definitions
// In the appropriate section

#ifndef _FireFightingRobot_H_
#define _FireFightingRobot_H_
#include "Arduino.h"
//add your includes for the project FireFightingRobot here


//end of add your includes here
#ifdef __cplusplus
extern "C" {
#endif
void loop();
void setup();
void lookForFire();
void centerOnFire();
void moveToFire();
void waterTime();
void runStraight();
void rotateRight();
void rotateLeft();
void stop();
int getFlameSensorValue();
#ifdef __cplusplus
} // extern "C"
#endif

//add your function definitions for the project FireFightingRobot here




//Do not add code below this line
#endif /* _FireFightingRobot_H_ */
