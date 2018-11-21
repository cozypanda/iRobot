#ifndef INCLUDED_PATCHBOT_ROBOT_HPP
#define INCLUDED_PATCHBOT_ROBOT_HPP


class robot
{
protected:
	int position_x_;
	int position_y_;
	bool is_alive_;
	robot(int position_x, int position_y);
public:	
	robot() = delete;
	~robot();
};
#endif
