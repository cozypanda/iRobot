#ifndef INCLUDED_PATCHBOT_WORLD_HPP
#define INCLUDED_PATCHBOT_WORLD_HPP
#include <vector>
#include <string>
#include <list>

/* Klasse fuer die Speicherung der Umgebungskarte samt der vorkommenden Roboter*/
class world
{
public:
	world();
	~world();
	static void createWorld(const std::string &path_to_file, world &world);
private:
	std::vector<char> board; // Speichert die Umgebungskarte
	std::list<char> robots; //  Enthaelt die Roboter
	int number_of_rows, row_length;
	static std::string const robot_symbols;
	static std::string const map_symbols;
	
	friend void write_to_output_file(const world &world);
};


#endif // !INCLUDED_PATCHBOT_WORLD_HPP