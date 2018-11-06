#include "point2d.h"



point2d::point2d(int x_coordinate, int y_coordinate) 

{
	x = x_coordinate;
	y = y_coordinate;
}

point2d::point2d()
{

}

point2d::~point2d()
{
}

int point2d::getX()
{
	return x;
}

int point2d::getY()
{
	return y;
}

void point2d::setX(int new_x_value)
{
	x = new_x_value;
}

void point2d::setY(int new_y_value)
{
	x = new_y_value;
}
