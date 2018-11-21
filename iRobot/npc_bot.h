#pragma once
#include "robot.h"
enum class npc_robot_type;

class npc_bot :
	public robot
{
public:
	npc_bot() = delete;
	npc_bot(int position_x, int position_y,const npc_robot_type &type);
	~npc_bot();
	
	npc_robot_type robot_type();
private:
	npc_robot_type type_;

};

enum class npc_robot_type
{
	pusher,
	digger,
	swimmer,
	follower,
	hunter,
	sniffer,
	bugger
};

