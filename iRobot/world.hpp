#ifndef INCLUDED_PATCHBOT_WORLD_HPP
#define INCLUDED_PATCHBOT_WORLD_HPP
#include <vector>
#include <string>
#include <list>
#include "enum_terrain.hpp"
#include "robot.h"
#include "npc_bot.h"
#include "patchbot.h"

/* Klasse fuer die Speicherung der Umgebungskarte samt der vorkommenden Roboter*/
class world
{
public:
	world();
	~world();
	static void createWorld(const std::string &path_to_file, world &world);
private:
	std::vector<char> board_; // Speichert die Umgebungskarte
	std::list<char> robots_; //  Enthaelt die Roboter

	std::vector<terrain> board_new_; // Speichert die Umgebungskarte
	std::list<robot> robots_new_; //  Enthaelt die Roboter

	int number_of_rows_, row_length_;
	static std::string const robot_symbols_;
	static std::string const map_symbols_;
	static char const patchbot_symbol;
	
	friend void write_to_output_file(const world &world);
	
};

terrain char_to_terrain(const char &input);
char terrain_to_char(const terrain &input);
npc_robot_type char_to_npc_robot_type(const char &robot_char);
char robot_to_char(const robot &robot);


#endif // !INCLUDED_PATCHBOT_WORLD_HPP