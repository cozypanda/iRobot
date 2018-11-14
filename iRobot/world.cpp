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

Exception safety

S M A R T POINTER ,------------------------- \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
****************************************
*/





	/* Konstruktoren mit und ohne uebergebenem Element*/
	world::world()
	{
		//world::createWorld(path_to_file, *this);
	}
	world::~world()
	{
		//board.~vector();
		//robots.~list();

	}

	/* liest uebergebene Config-File der Umgebungskarte ein und legt diese  
	samt der dort vorkommenden Roboter in die entsprechende Datenstruktur ab */
	void world::createWorld(const std::string &path_to_file, world &world)
		{

		std::ifstream file_reader(path_to_file);

		if (!file_reader)
			throw "Config file could not be opened";			
		
		/* Pruefung auf leere Datei einfuegen*/

		int counter_lines_read = 0;
		bool patchbot_start_found = false;
		bool patchbot_goal_found = false;
		
		
		while (file_reader)
		{
			std::string line_read;
			getline(file_reader, line_read);
			
			counter_lines_read++;


			if (counter_lines_read <= 2)
			{
				// Pruefung, ob ersten beiden Zeilen des Files Int-Werte sind
				if (!has_only_digits(line_read) || line_read.compare("") == 0)
					throw ("Input at line " + std::to_string(counter_lines_read) + " is not of type INT");

				//Einlesen der Hoehe und Breite des Spielfelds
				if (counter_lines_read == 1)
					world.row_length = std::stoi(line_read);
				else
					world.number_of_rows = std::stoi(line_read);
			}
			else
			{
				// falls true, EOF erreicht oder leere Zeile in Config
				if (line_read.compare("") == 0)
				{
					--counter_lines_read;
					break;
				}
				
				if (line_read.length() != world.row_length)
					throw ("Row length mismatch at line " + std::to_string(counter_lines_read));

				if (line_read.find_first_not_of(map_symbols) != std::string::npos)
					throw ("Unknown character in line " + std::to_string(counter_lines_read) + " position " + std::to_string(line_read.find_first_not_of(map_symbols)));

				/* Alle Zeichen der gelesenen Zeile werden nacheinander der Umgebungskarten-Datenstruktur hinzugefuegt
				entspricht ein Zeichen einem Roboterstartpunkt, wird dieser zusaetzlich der Roboter-Datenstruktur hinzugefuegt. */
				for (int i = 0; i < line_read.length(); i++)		
				{				
					world.board.push_back(line_read[i]);
					if (robot_symbols.find_first_of(line_read[i]) != std::string::npos)
						world.robots.push_back(line_read[i]);
					if (line_read[i] == 'p')
					{
						if (patchbot_start_found)
							throw "Too many starting points for Patchbot";
						patchbot_start_found = true;
					}
						
					if (line_read[i] == 'P')
						patchbot_goal_found = true;
				}
			}
		}

		//Pruefung, ob Config korrekte Anzahl an Zeilen, einen Patchbot-Startpunkt sowie ein Ziel beinhaltet hat
		if (counter_lines_read -2 != world.number_of_rows)
			throw "Row amount mismatch" ;
		if (patchbot_start_found == false)
			throw "Startpoint missing";
		if (patchbot_goal_found == false)
			throw "Goal / main server missing";
	}
	
	

	////////////////////////////////////* Verlinkung zwischen Robotern fehlt (double linked list)*/

	
// Erlaubte Zeichen fuer Umgebungskarte und Roboter
std::string const world::robot_symbols = "1234567p";
std::string const world::map_symbols = "1234567pP#MdDg.xO~ ";



