#ifndef INCLUDED_PATCHBOT_ROBOT_HPP
#define INCLUDED_PATCHBOT_ROBOT_HPP

enum class robot_type
{
	pusher,
	digger,
	swimmer,
	follower,
	hunter,
	sniffer,
	bugger,
	patchbot,
	unknown
};

class robot
{
private:
	int position_x_;
	int position_y_;
	
	bool is_alive_;
	
	robot_type type_;

public:	
	robot(int position_x, int position_y, robot_type &type);
	robot() = delete;
	
	~robot();
	
	robot_type type_robot();
	
	int position_x();
	int position_y();
	
	bool is_alive();
};


#endif //!INCLUDED_PATCHBOT_ROBOT_HPP
