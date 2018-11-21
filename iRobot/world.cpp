#include "check_if_int.hpp"
#include <fstream>
#include <iostream>

#include "world.hpp"
 

/* 
**************TO-DO*********************
Uebergabeparameter pruefen (Referenzen, Pointer, constant etc)
private / public Zugriffe einfuegen (Variablen, Konstruktoren, Methoden)
Kommentare
Methoden- und Variablennamen pruefen
Destroy Methode implementieren
Include Reihenfolge
Inclusion Guards
Verlinkung zwischen den Robots (DLinked List)

Exception safety

getter & setter ohne get / set

'p' 'P' durch typedef ersetzen

DELTE POINT2d


S M A R T POINTER ,------------------------- \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
****************************************
*/



	world::world()
	{
		
	}
	world::~world()
	{
		
	}

	/* liest uebergebene Config-File der Umgebungskarte ein und legt diese  
	samt der dort vorkommenden Roboter in die entsprechende Datenstruktur ab */
	void world::createWorld(const std::string &path_to_file, world &world)
		{

		std::ifstream file_reader(path_to_file);

		if (!file_reader)
			throw "Config file could not be opened";			
		
		int counter_lines_read = 0;
		bool patchbot_start_found = false;
		bool patchbot_goal_found = false;
		
		
		while (file_reader)
		{
			std::string line_read;
			getline(file_reader, line_read);
			
			counter_lines_read++;

			//Einlesen der Hoehe und Breite des Spielfelds
			if (counter_lines_read <= 2)
			{
				// Pruefung, ob ersten beiden Zeilen des Files Int-Werte sind
				if (!has_only_digits(line_read) || line_read.compare("") == 0)
					throw ("Input at line " + std::to_string(counter_lines_read) + " is not of type INT");

				
				if (counter_lines_read == 1)
					world.row_length_ = std::stoi(line_read);
				else
					world.number_of_rows_ = std::stoi(line_read);
			}
			//Einlesen der Umgebungskartenzeichen
			else
			{
				// falls true, EOF erreicht oder leere Zeile in Config
				if (line_read.compare("") == 0)
				{
					--counter_lines_read;
					break;
				}
				
				if (line_read.length() != world.row_length_)
					throw ("Row length mismatch at line " + std::to_string(counter_lines_read));

				if (line_read.find_first_not_of(map_symbols_) != std::string::npos)
					throw ("Unknown character in line " + std::to_string(counter_lines_read)  
						+ " position " + std::to_string(line_read.find_first_not_of(map_symbols_)));

				/* Alle Zeichen der gelesenen Zeile werden nacheinander der Umgebungskarten-Datenstruktur 
				hinzugefuegt entspricht ein Zeichen einem Roboterstartpunkt, wird dieser zusaetzlich 
				der Roboter-Datenstruktur hinzugefuegt. */
				for (int i = 0; i < line_read.length(); i++)		
				{
					terrain terrain_type = char_to_terrain(line_read[i]);
					if (terrain_type == terrain::unknown_terrain)
						throw ("Unknown character " + std::to_string(line_read[i])
							+ " in line " + std::to_string(counter_lines_read));
					else if (terrain_type == terrain::main_server)
						patchbot_goal_found = true;

					world.board_new_.push_back(terrain_type);

					bool is_robot = (robot_symbols_.find_first_of(line_read[i]) != std::string::npos);
					if (is_robot)
					{
						if (line_read[i] == patchbot_symbol)
						{
							if (patchbot_start_found)
								throw "Too many starting points for Patchbot";
							world.robots_new_.push_back(patchbot(i, (counter_lines_read - 3)));
							patchbot_start_found = true; //TODO WARUM ZU VIELE STARTING POINTS???
						}
						else
						{
							npc_robot_type type_of_robot = char_to_npc_robot_type(line_read[i]);
							npc_bot new_robot = npc_bot(i, (counter_lines_read - 3), type_of_robot);
							world.robots_new_.push_back(new_robot);
						}
					}


					/*
					world.board_.push_back(line_read[i]);

					bool is_robot = (robot_symbols_.find_first_of(line_read[i]) != std::string::npos);
					if (is_robot)
						world.robots_.push_back(line_read[i]);
					if (line_read[i] == 'p')
					{
						if (patchbot_start_found)
							throw "Too many starting points for Patchbot";
						patchbot_start_found = true;
					}
						
					if (line_read[i] == 'P')
						patchbot_goal_found = true;
						*/
				}
			}
		}

		//Pruefung, ob Config korrekte Anzahl an Zeilen, einen Patchbot-Startpunkt sowie ein Ziel beinhaltet hat
		if (counter_lines_read -2 != world.number_of_rows_)
			throw "Row amount mismatch" ;
		if (patchbot_start_found == false)
			throw "Startpoint missing";
		if (patchbot_goal_found == false)
			throw "Goal / main server missing";
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

	npc_robot_type char_to_npc_robot_type(const char &robot_char)
	{
		switch (robot_char)
		{
		case '1':
			return npc_robot_type::bugger;
		case '2':
			return npc_robot_type::pusher;
		case '3':
			return npc_robot_type::digger;
		case '4':
			return npc_robot_type::swimmer;
		case '5':
			return npc_robot_type::follower;
		case '6':
			return npc_robot_type::hunter;
		case '7':
			return npc_robot_type::sniffer;
		default:
			throw "Not a valid robot symbol";
			
		}
	}
	char robot_to_char(const robot &robot)
	{
		//TODO implement Robot to Char
		return '0';
	}
	

// Erlaubte Zeichen fuer Umgebungskarte und Roboter
std::string const world::robot_symbols_ = "1234567p";
char const world::patchbot_symbol = 'p';
std::string const world::map_symbols_ = "1234567pP#MdDg.xO~ ";



