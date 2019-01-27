#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib> // for exit()
#include <iterator> // for std::next()
#include "world.hpp"
#include "exceptions.hpp"

/* Schreibt zu erst die Hoehe, dann die Breite der Karte und 
 anschliessend die Umgebungskarte samt Robotern in eine Ausgabedatei
dabei wird der eindimensionale Kartenvektor wieder in eine zweidim.
Ausgabe umgewandelt.*/
void write_to_output_file(const world &world, const std::string &outputfile)
{
	std::ofstream file_writer(outputfile);
	if (!file_writer)
		throw exceptions_file_error();


	file_writer << world.row_length_ << std::endl;
	file_writer << world.number_of_rows_ << std::endl;
	
	robot next_robot_to_print = *world.robots_.begin();
	int pos_next_robot = next_robot_to_print.position_y()*world.row_length_
		+ next_robot_to_print.position_x(); // Position des naechsten Roboters, wird dann in der Schleife mit i verglichen

	int i = 1;
	
	// Findet ersten auszugebenden Roboter samt seiner zugehoerigen Position
	while (i < world.robots_.size())
	{
		robot r = *std::next(world.robots_.begin(), i);
		int position_r = r.position_y()*world.row_length_ + r.position_x();
		if (position_r < pos_next_robot)
		{
			next_robot_to_print = r;
			pos_next_robot = position_r;
		}
		i++;

	}


		
	for (int i = 0; i < world.board_.size(); i++)
	{
		
		// Falls true, wird ein Robotersymbol in das File geschrieben, sonst das naechste Terrain Zeichen
		if (i == pos_next_robot) 
		{
			file_writer << robot_type_to_char(next_robot_to_print.type_robot());
			
			int j = 1;
			pos_next_robot = world.row_length_ * world.number_of_rows_; // = Maximal moeglicher Wert 

			// Findet naechsten auszugebenden Roboter samt seiner zugehoerigen Position
			while (j < world.robots_.size())
			{
				robot r = *std::next(world.robots_.begin(), j);
				int position_r = r.position_y()*world.row_length_ + r.position_x();
				if (position_r < pos_next_robot && position_r > i)
				{
					next_robot_to_print = r;
					pos_next_robot = position_r;
				}
				j++;
			}
		}
		else
		{
			file_writer << terrain_to_char(world.board_.at(i));
		}
		
		if ((i + 1) % world.row_length_ == 0)
			file_writer << std::endl;
		
	}
	file_writer.close();
}


int main(int argc, char** argv)
{
	// Pruefung, ob genau ein Argument uebergeben wurde /// aktivieren fuer live
	if (argc != 2)
	{
		std::cout << "Invalid amount of arguments." << std::endl;
		exit(-1);
	}
		
	world* a;
	try
	{
		a = new world(world::createWorld(*(argv+1)));
	}
	catch (const std::exception& except)
	{
		std::cerr << "World creation error: " << except.what() << std::endl;
		exit(-1);
	}
	
	try
	{
		std::string suffix = "_output.txt"; 
		std::string outputfile = *(argv + 1); // init mit Inputfilename
		outputfile.replace(outputfile.size() - 4, 4, suffix); // Erweitert den Filename um den angegebenen Suffix
		write_to_output_file(*a, outputfile);
	}
	catch (const std::exception& except)
	{
		std::cerr << "ERROR: " << except.what() << std::endl;
		exit(-1);
	}
}

