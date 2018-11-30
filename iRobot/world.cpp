#include "world.hpp"
#include <fstream>
#include <iostream>
#include "check_if_int.hpp"
#include "exceptions.hpp" 



	world::world(int number_of_rows, int row_length, const std::vector<terrain> &terrain, const std::list<robot> &robots) 
		: number_of_rows_(number_of_rows), row_length_(row_length), board_(terrain), robots_(robots)
	{
		
	}
	world::~world()
	{
		
	}

	/*robot world::robot_at_position(int position)
	{
		
		if ((unsigned int)position >= (int)robots_new_.size)
			throw("Invalid position"); //TODO : nicht thrown sondern return?
		
			robot* temp = robots_new_.front;
			int i = 0;
				while (i < position)
				{
					temp = temp + 1;
					i++;
				}
					
				return *temp;
		
	}*/


	/* liest uebergebene Config-File der Umgebungskarte ein und legt diese  
	samt der dort vorkommenden Roboter in die entsprechende Datenstruktur ab */


	world world::createWorld(const std::string &path_to_file)
	{

		std::ifstream file_reader(path_to_file);

		if (!file_reader)
			throw exceptions_file_error();

		
		std::string line_read;
		
		// Einlesen der Kartendimensionen
		int world_dimensions[2];
		
		for (int i = 0; i < 2; i++)
		{
			getline(file_reader, line_read);
			if (!has_only_digits(line_read) || line_read.compare("") == 0)
				throw exceptions_input_not_int();
			world_dimensions[i] = std::stoi(line_read);
		}


		int counter_lines_read = 0;
		int counter_chars_read = 0;
		bool patchbot_start_found = false;
		bool patchbot_goal_found = false;
		
		std::vector<terrain> world_terrains;
		std::list<robot> world_robots;

		//Einlesen der Roboter und des Spielfeldes
		while (!file_reader.eof())
		{
			getline(file_reader, line_read);
			
			counter_lines_read++;

			if (line_read.length() != world_dimensions[0])
				throw exceptions_row_length_mismatch();

			/*Liest nacheinander alle Zeichen einer Zeile ein und
			fuegt die enthaltende Kartensymbole und ggf. Roboter der Datenstrukturen hinzu*/
			for (int i = 0; i < line_read.length(); i++)
			{
				terrain terrain_type = char_to_terrain(line_read[i]);
				if (terrain_type == terrain::unknown_terrain)
					throw exceptions_unknown_terrain_symbol();
				else if (terrain_type == terrain::main_server)
					patchbot_goal_found = true;
				
				
				world_terrains.push_back(terrain_type);

				robot_type type_of_robot = char_to_robot_type(line_read[i]);;
				if (type_of_robot != robot_type::unknown)
				{
					if (type_of_robot == robot_type::patchbot)
					{
						if (patchbot_start_found)
							throw exceptions_too_many_starting_points();
						patchbot_start_found = true; 
					}
											
					robot new_robot = robot(i, (counter_lines_read - 1), type_of_robot);
					world_robots.push_back(new_robot);

				}
			}
			
		}
		file_reader.close();

		//Pruefung, ob Config korrekte Anzahl an Zeilen, einen Patchbot-Startpunkt sowie ein Ziel beinhaltet hat
		if (counter_lines_read != world_dimensions[1])
			throw exceptions_row_amount_mismatch();
		if (patchbot_start_found == false)
			throw exceptions_missing_starting_point();
		if (patchbot_goal_found == false)
			throw exceptions_missing_main_server();

		world new_w = world(world_dimensions[1], world_dimensions[0], world_terrains, world_robots);
		
		return new_w;
	}

	terrain char_to_terrain(const char &input)
	{
		switch (input)
		{
		case 'P':
			return terrain::main_server;
		case ' ':
			return terrain::floor_regular;
		case 'p':
			return terrain::floor_patchbot_start;
		case '1':
			return terrain::floor_npc_start;
		case '2':
			return terrain::floor_npc_start;
		case '3':
			return terrain::floor_npc_start;
		case '4':
			return terrain::floor_npc_start;
		case '5':
			return terrain::floor_npc_start;
		case '6':
			return terrain::floor_npc_start;
		case '7':
			return terrain::floor_npc_start;
		case 'O':
			return terrain::trap_abyss;
		case '~':
			return terrain::trap_water;
		case 'g':
			return terrain::obstacle_alien_weed;
		case '.':
			return terrain::obstacle_gravel;
		case 'x':
			return terrain::obstacle_secret_passage;
		case 'D':
			return terrain::door_automatic_closed;
		case 'd':
			return terrain::door_manual_closed;
		case '#':
			return terrain::wall_concrete;
		case 'M':
			return terrain::wall_rock;
		default :
			return terrain::unknown_terrain;

		}
	}

	// Rueckgabe bei floor_npc_start : 'r'
	// bei unknown : e
	char terrain_to_char(const terrain &input)
	{
		switch (input)
		{
		case terrain::main_server:
			return 'P';
		case terrain::floor_regular:
			return ' ';
		case terrain::floor_patchbot_start:
			return 'p';
		case terrain::floor_npc_start:
			return 'r';
		case terrain::trap_abyss:
			return 'O';
		case terrain::trap_water:
			return '~';
		case terrain::obstacle_alien_weed:
			return 'g';
		case terrain::obstacle_gravel:
			return '.';
		case terrain::obstacle_secret_passage:	
			return 'x';
		case terrain::door_automatic_closed:
			return 'D';
		case terrain::door_manual_closed:
			return 'd';
		case terrain::wall_concrete:
			return '#';
		case terrain::wall_rock:
			return 'M';
		default:
			return 'e';

		}
	}

	robot_type char_to_robot_type(const char &robot_char)
	{
		switch (robot_char)
		{
		case '1':
			return robot_type::bugger;
		case '2':
			return robot_type::pusher;
		case '3':
			return robot_type::digger;
		case '4':
			return robot_type::swimmer;
		case '5':
			return robot_type::follower;
		case '6':
			return robot_type::hunter;
		case '7':
			return robot_type::sniffer;
		case 'p':
			return robot_type::patchbot;
		default:
			return robot_type::unknown;
			
		}
	}

	//Rueckgabe 'e' bei unknown
	char robot_type_to_char(const robot_type &type)
	{
		switch (type)
		{
		case robot_type::bugger:
			return '1';
		case robot_type::pusher:
			return '2';
		case robot_type::digger:
			return '3';
		case robot_type::swimmer:
			return '4';
		case robot_type::follower:
			return '5';
		case robot_type::hunter:
			return '6';
		case robot_type::sniffer:
			return '7';
		case robot_type::patchbot:
			return 'p';
		default:
			return 'e';
		}
		return '0';
	}
	



