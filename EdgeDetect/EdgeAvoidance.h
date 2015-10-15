// Only modify this file to include
// - function definitions (prototypes)
// - include files
// - extern variable definitions
// In the appropriate section

#ifndef _EdgeAvoidance_H_
#define _EdgeAvoidance_H_
#include "Arduino.h"
//add your includes for the project EdgeAvoidance here

struct Edge {
	int tilt;
	int distance;
};

//end of add your includes here
#ifdef __cplusplus
extern "C" {
#endif
void loop();
void setup();
Edge detectEdge(int pan);
int getDistance();
void moveToEdge();
void setClosest(Edge left, Edge right);
void startEngine();
#ifdef __cplusplus
} // extern "C"
#endif

//add your function definitions for the project EdgeAvoidance here




//Do not add code below this line
#endif /* _EdgeAvoidance_H_ */
