#include <vector>
#include <string>
#include <list>
#include <fstream>
#include <iostream>
#include <cstdlib> // for exit()
#include "check_if_int.hpp"

/* 
**************TO-DO*********************
Uebergabeparameter pruefen (Referenzen, Pointer, constant etc)
private / public Zugriffe einfuegen (Variablen, Konstruktoren, Methoden)
Kommentare
Methoden- und Variablennamen pruefen
Destroy Methode implementieren
Include Reihenfolge
Inclusion Guards
****************************************
*/

class world
{
public:

	/* Konstruktoren mit und ohne uebergebenem Element*/
	world(int number_of_rows, int row_length)
	{
		board.reserve(number_of_rows * row_length);
		this->number_of_rows = number_of_rows;
		this->row_length = row_length;
	}

	static world createWorld(const std::string &path_to_file)
	{
		std::ifstream file_reader(path_to_file);

		if (!file_reader)
		{
			std::cerr << "Config file could not be opened" << std::endl;
			exit(1);
		}

		/* Pruefung auf leere Datei einfuegen*/

		int counter_lines_read = 0;
		while (!file_reader)
		{
			if (counter_lines_read < 2)
			{

			}
			counter_lines_read++;
		}

		return world(2, 4);
	}

	
private:
	std::vector<char> board;
	std::list<char> robots;
	int number_of_rows, row_length;

	void append_tile_to_board(char c)
	{
		board.push_back(c);
	}

	/* Verlinkung zwischen Robotern fehlt (double linked list)*/
	void add_new_robot(char c)
	{
		robots.push_back;
	}
	
	

	
};

