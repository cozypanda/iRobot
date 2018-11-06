#include <fstream>
#include <iostream>
#include <cstdlib> // for exit()
#include "check_if_int.hpp"
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

PRUEFUNG OB ALLE ZEICHEN VALIDE SIND Umgebungskarte

S M A R T POINTER ,------------------------- \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
****************************************
*/





	/* Konstruktoren mit und ohne uebergebenem Element*/
	world::world(const std::string &path_to_file)
	{
		world::createWorld(path_to_file, *this);
	}

	void world::createWorld(const std::string &path_to_file, world &world)
	{
		std::ifstream file_reader(path_to_file);

		if (!file_reader)
		{
			std::cerr << "Config file could not be opened" << std::endl;
			exit(1);
		}

		/* Pruefung auf leere Datei einfuegen*/

		int counter_lines_read = 0;
		
		
		while (file_reader)
		{
			std::string line_read;
			getline(file_reader, line_read);
			counter_lines_read++;
			if (counter_lines_read <= 2)
			{
				// Pruefung, ob ersten beiden Zeilen des Files Int-Werte sind
				if (!has_only_digits(line_read))
					exit(2);
				if (counter_lines_read == 1)
					world.row_length = std::stoi(line_read);
				else
					world.number_of_rows = std::stoi(line_read);

			}
			else
			{
				// Einlesen der Kartenchars
				if (line_read.length() != world.row_length)
					exit(3);
				for (int i = 0; i < line_read.length(); i++)
				{
					world.board.push_back(line_read[i]);
					if (robot_symbols.find_first_of(line_read[i]) != std::string::npos)
						world.robots.push_back(line_read[i]);
				}


			}

			// Pruefung, ob Vector-Laenge == row * columns

		}

		
	}

	

	////////////////////////////////////* Verlinkung zwischen Robotern fehlt (double linked list)*/

	
	
std::string const world::robot_symbols = "1234567p";



