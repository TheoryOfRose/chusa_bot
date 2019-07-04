#ifndef ROBOT_H
#define ROBOT_H

#include "AUTO.h"

class Robot{
	public:
		// Constructor
		Robot();
		Robot(location l);

		// Variable
		location loc;
		int num;
		int sensing_angle;
		Mat map;

		// Member Function
		location* Sensing();
		void Move(location l);
		location Searching();
}

#endif
