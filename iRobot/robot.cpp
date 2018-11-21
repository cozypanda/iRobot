#include "robot.h"

robot::robot(int position_x, int position_y)
	: position_x_(position_x), 
	position_y_(position_y), 
	is_alive_(true)
{}

robot::~robot()
{
}


