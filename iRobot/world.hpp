#ifndef INCLUDED_PATCHBOT_WORLD_HPP
#define INCLUDED_PATCHBOT_WORLD_HPP
#include <vector>
#include <string>
#include <list>


class world
{
public:
	world(const std::string &path_to_file);
private:
	std::vector<char> board;
	std::list<char> robots;
	int number_of_rows, row_length;
	static std::string const robot_symbols;
	static void createWorld(const std::string &path_to_file, world &world);
};


#endif // !INCLUDED_PATCHBOT_WORLD_HPP