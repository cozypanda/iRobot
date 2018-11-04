#ifndef INCLUDED_PATCHBOT_WORLD_HPP
#define INCLUDED_PATCHBOT_WORLD_HPP
#endif // !INCLUDED_PATCHBOT_WORLD_HPP

class world
{
public:
	world(int number_of_rows, int row_length);
	static world createWorld(const std::string &path_to_file);

};
