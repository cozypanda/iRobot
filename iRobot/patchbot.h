#pragma once
#include "robot.h"
class patchbot :
	public robot
{
public:
	patchbot(int position_x, int position_y); //TODO create call to superclass for all subclasses of robot (feet, wheels.. as enum not seperate classes?)
	~patchbot();
};

