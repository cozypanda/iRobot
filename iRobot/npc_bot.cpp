#include "npc_bot.h"

npc_bot::npc_bot(int position_x, int position_y, const npc_robot_type &type)
	: robot::robot(position_x, position_y), type_(type)
{
}


npc_bot::~npc_bot()
{
}

npc_robot_type npc_bot::robot_type() { return this->type_; }
