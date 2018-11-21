#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib> // for exit()
#include "world.hpp"

/* Schreibt zu erst die Hoehe, dann die Breite der Karte und 
 anschliessend die Umgebungskarte samt Robotern in eine Ausgabedatei
dabei wird der eindimensionale Kartenvektor wieder in eine zweidim.
Ausgabe umgewandelt.*/
void write_to_output_file(const world &world)
{
	// include friend in robot / done
	std::ofstream file_writer("test_output.txt");
	if (!file_writer)
		throw "Output file could not be opened / created.";
	else
	{
		file_writer << world.row_length_ << std::endl;
		file_writer << world.number_of_rows_ << std::endl;

		for (int i = 0; i < world.board_.size(); i++)
		{
			file_writer << world.board_[i];
			if ((i + 1) % world.row_length_ == 0) 
				file_writer << std::endl;
		}
	}
}


int main(int argc, char** argv)
{
	// Pruefung, ob genau ein Argument uebergeben wurde /// aktivieren fuer live
	/*if (argc != 2)
	{
		std::cout << "Invalid amount of arguments." << std::endl;
		exit(-1);
	}*/
		
	world a;
	std::string test123 = "test123.txt";
	try
	{
		world::createWorld(test123, a);
		// world::createWorld(*(argv+1), a);
	}
	catch (const char* exception)
	{
		std::cout << "World creation error: " << exception << std::endl;
		exit(-1);
	}
	catch (const std::string exception)
	{
		std::cout << "World creation error: " << exception << std::endl;
		exit(-1);
	}
	try
	{
		patchbot p = a.
		write_to_output_file(a);
	}
	catch (const char* exception)
	{
		std::cout << "ERROR: " << exception << std::endl;
		exit(-1);
	}
}
/*
int main()
{
	std::string a = "1234567pP#MdDg.xO~ ";
	int i = 0;
	while (i < a.length())
	{
		terrain t =  char_to_terrain(a[i]);
		char c = terrain_to_char(t);
		i++;
	}
	
}*/

