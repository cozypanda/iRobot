#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib> // for exit()
#include <iterator> // for std::next()

#include "world.hpp"
#include "exceptions.hpp"
#include "graphic.hpp"

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
	
}

void write_graphic_to_file(const std::string &file, const graphic &graphic) {
	std::ofstream file_writer(file, std::ofstream::binary);
	if (!file_writer)
		throw exceptions_file_error();

	//Schreibe Headerdaten
	char short_to_char[2];
	file_writer << graphic.header_data_.id_length_;
	file_writer << graphic.header_data_.color_map_type_;
	file_writer << graphic.header_data_.data_type_;

	short_to_char[0] = graphic.header_data_.color_map_origin_ & 0xff;
	short_to_char[1] = (graphic.header_data_.color_map_origin_ >> 8) & 0xff;
	file_writer << short_to_char[0] << short_to_char[1];

	short_to_char[0] = graphic.header_data_.color_map_length_ & 0xff;
	short_to_char[1] = (graphic.header_data_.color_map_length_ >> 8) & 0xff;
	file_writer << short_to_char[0] << short_to_char[1];

	file_writer << graphic.header_data_.color_map_depth_;

	short_to_char[0] = graphic.header_data_.x_origin_ & 0xff;
	short_to_char[1] = (graphic.header_data_.x_origin_ >> 8) & 0xff;
	file_writer << short_to_char[0] << short_to_char[1];

	short_to_char[0] = graphic.header_data_.y_origin_ & 0xff;
	short_to_char[1] = (graphic.header_data_.y_origin_ >> 8) & 0xff;
	file_writer << short_to_char[0] << short_to_char[1];

	short_to_char[0] = graphic.header_data_.width_ & 0xff;
	short_to_char[1] = (graphic.header_data_.width_ >> 8) & 0xff;
	file_writer << short_to_char[0] << short_to_char[1];

	short_to_char[0] = graphic.header_data_.height_ & 0xff;
	short_to_char[1] = (graphic.header_data_.height_ >> 8) & 0xff;
	file_writer << short_to_char[0] << short_to_char[1];

	file_writer << graphic.header_data_.bits_per_pixel_;
	file_writer << graphic.header_data_.attributes_;

	//Schreibe Pixeldaten
	for (int i = 0; i < graphic.image_data_.size(); i++) {
		const pixel_rgb* pixel = &(graphic.image_data_.at(i));
		file_writer << pixel->b_ << pixel->g_ << pixel->r_ << pixel->a_;
	}

	//Schreibe Footerdaten

	for (int i = 0; i < 8; i++)
		file_writer << '\0';
	file_writer << "TRUEVISION-XFILE" << '.' << '\0';

}

/*
int main(int argc, char** argv)
{
	// Pruefung, ob genau ein Argument uebergeben wurde /// aktivieren fuer live
	if (argc != 2)
	{
		std::cout << "Invalid amount of arguments." << std::endl;
		return;
	}
		
	world* a;
	try
	{
		a = new world(world::create_world(*(argv+1)));
	}
	catch (const std::exception& except)
	{
		std::cerr << "World creation error: " << except.what() << std::endl;
		return;
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
		return;
	}

	delete a; //TODO: obsolet sobald auf smart_pointer umgestellt wurde
}*/

int main(int argc, char** argv) {
	graphic* g = nullptr;
	try {
		g = new graphic(graphic::create_graphic(*(argv + 1)));
	}
	catch (const std::exception &except) {
		std::cerr << "ERROR: " << except.what() << std::endl;
	}

	std::string suffix = "_output.tga";
	std::string outputfile = *(argv + 1); // init mit Inputfilename
	outputfile.replace(outputfile.size() - 4, 4, suffix); // Erweitert den Filename um den angegebenen Suffix
	if (g != nullptr)
		write_graphic_to_file(outputfile, *g);
	delete g;
	return 0;
}

