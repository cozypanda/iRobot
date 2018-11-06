#include "robot.h"

robot::robot(int position_x, int position_y)
{
	location.setX(position_x);
	location.setY(position_y);
	is_alive = true;
}
robot::robot()
{

}


robot::~robot()
{
}


