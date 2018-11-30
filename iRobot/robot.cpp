#include "robot.hpp"

robot::robot(int position_x, int position_y, robot_type &type)
	: position_x_(position_x), 
	position_y_(position_y), 
	is_alive_(true), type_(type)
{}

robot::~robot()
{
}

robot_type robot::type_robot() { return this->type_; }

int robot::position_x() { return position_x_; }
int robot::position_y() { return position_y_; }
bool robot::is_alive() { return is_alive_; }