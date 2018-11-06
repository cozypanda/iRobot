#ifndef INCLUDED_PATCHBOT_ROBOT_HPP
#define INCLUDED_PATCHBOT_ROBOT_HPP
 
#include "point2d.h"

class robot
{
private:
	point2d location;
	bool is_alive;
public:
	robot(int position_x, int position_y);
	robot();
	~robot();
};
#endif
