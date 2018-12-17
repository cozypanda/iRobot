#ifndef INCLUDED_PATCHBOT_WORLD_HPP
#define INCLUDED_PATCHBOT_WORLD_HPP

#include <vector>
#include <string>
#include <list>

#include "enum_terrain.hpp"
#include "robot.hpp"
#include "exceptions.hpp"

/* Klasse fuer die Speicherung der Umgebungskarte samt der vorkommenden Roboter*/
class world
{
public:
	world(int number_of_rows, int row_length, 
		const std::vector<terrain> &terrain,
		const std::list<robot> &robots);
	world() = delete;
		
	static world create_world(const std::string &path_to_file);

private:
	std::vector<terrain> board_; // Speichert die Umgebungskarte
	std::list<robot> robots_; //  Enthaelt die Roboter

	int number_of_rows_, row_length_; // Dimensionen der Karte
	
	friend void write_to_output_file(const world &world, const std::string &outputfile); // Um Datenstruktur in Outputfile zu schreiben	
};

terrain char_to_terrain(const char &input); //Wandelt uebergebenes Zeichen in entsprechendes Terrain um
char terrain_to_char(const terrain &input); //Wandelt uebergebenes Terrain in entsprechendes Zeichen um
robot_type char_to_robot_type(const char &robot_char); //Wandelt uebergebenes Zeichen in entsprechendes Robotertyp um
char robot_type_to_char(const robot_type &robot); //Wandelt uebergebenen Robotertyp in entsprechendes Zeichen um



#endif // !INCLUDED_PATCHBOT_WORLD_HPP