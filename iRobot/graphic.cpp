#include "graphic.hpp"

#include <fstream>
#include <iostream>

#include "exceptions.hpp"

pixel_rgb::pixel_rgb(
	unsigned char b, unsigned char g,
	unsigned char r, unsigned char a)
	: r_(r), g_(g), b_(b), a_(a)
{}

graphic::graphic(
	const graphic_header &header,
	const std::vector<pixel_rgb> &image_data)
	: header_data_(header), 
	image_data_(image_data)
{}

/* Liest übergebene TGA-File ein und liest die angegebenen Headerdaten
sowie die enthaltenen Pixel-RGBa-Werte ein und speichert sie 
in einem entsprechenden Graphic-Objekt */

const graphic graphic::create_graphic(const std::string &tga_file) {
	std::ifstream tga_reader(tga_file, std::ifstream::binary);
	if (!tga_reader)
		throw exceptions_file_error();

	graphic_header header; 

	//TODO: Insert check header length

	/* Einlesen der Headerdaten inkl. Prüfung, ob Werte dem 
	gewünschten Format entsprechen */
	tga_reader.get(header.id_length_);
	if ((int)header.id_length_ != 0)
		throw exceptions_tga_id_length(); 
	
	tga_reader.get(header.color_map_type_);
	if ((int)header.color_map_type_ != 0)
		throw exceptions_tga_color_map_type(); 

	tga_reader.get(header.data_type_);
	if ((int)header.data_type_ != 2)
		throw exceptions_tga_data_type();

	tga_reader.read((char*)&header.color_map_origin_, sizeof(short));
	if (header.color_map_origin_ != 0)
		throw exceptions_tga_color_map_origin();

	tga_reader.read((char*)&header.color_map_length_, sizeof(short));
	if (header.color_map_length_ != 0)
		throw exceptions_tga_color_map_length();

	tga_reader.get(header.color_map_depth_);
		
	tga_reader.read((char*)&header.x_origin_, sizeof(short));
	if (header.x_origin_ != 0)
		throw exceptions_tga_x_origin();

	tga_reader.read((char*)&header.y_origin_, sizeof(short));
	if (header.y_origin_ != 0)
		throw exceptions_tga_y_origin();

	tga_reader.read((char*)&header.width_, sizeof(short));
	if (header.width_ < 0)
		throw exceptions_tga_width();
	
	tga_reader.read((char*)&header.height_, sizeof(short));
	if (header.height_ < 0)
		throw exceptions_tga_height();
	
	tga_reader.get(header.bits_per_pixel_);
	if ((int)header.bits_per_pixel_ != 32)
		throw exceptions_tga_bits_per_pixel();

	tga_reader.get(header.attributes_);
	if (header.attributes_ < 0)
		throw exceptions_tga_attributes();

	
	std::vector<pixel_rgb> image_data; 
	unsigned char rgba[4]; 

	/* Beginn des Einlesens der Daten Pixel für Pixel */
	for (int i = 0; i < header.height_ * header.width_; i++) {	
		/* einlesen des nächsten Pixels - Format bgra */
		for (int j = 0; j < 4; j++) 
		{	
			if (tga_reader.peek() == EOF) 
				// Fileende, obwohl angegebene Anzahl an Pixel 
				// noch nicht gelesen wurden
				throw exceptions_reading_pixel_data();

			rgba[j] = (unsigned char)tga_reader.get();			
		}
		
		image_data.push_back(pixel_rgb(rgba[0], rgba[1], rgba[2], rgba[3]));
	}	
		
	return graphic(header, image_data);
}

