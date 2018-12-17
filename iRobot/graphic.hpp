#ifndef INCLUDED_PATCHBOT_GRAPHIC_HPP
#define INCLUDED_PATCHBOT_GRAPHIC_HPP

#include <string>
#include <vector>

#include "exceptions.hpp"

struct pixel_rgb;

// Datenstruktur des TGA-Headers
struct graphic_header {
	char id_length_; // muss 0
	char color_map_type_; // muss 0
	char data_type_; // muss 2
	short color_map_origin_; // muss 0
	short color_map_length_; // muss 0
	char color_map_depth_;
	short x_origin_; // muss 0
	short y_origin_; // muss 0
	short width_;
	short height_;
	char bits_per_pixel_; // muss 32
	char attributes_;
};


// Datenstruktur des kompletten TGA-Files
class graphic {

public:	
	static const graphic create_graphic(const std::string &tga_file); 

	friend void write_graphic_to_file(const std::string &file, 
		const graphic &graphic); // Schreibt Graphik zurück in übergebenes File

private:
	graphic(
		const graphic_header &header, 
		const std::vector<pixel_rgb> &image_data);

	graphic_header header_data_; // Daten des TGA - Headers
	std::vector<pixel_rgb> image_data_; // RGBA-Daten aller Pixel 	
};


// Speicherung der RGBA-Werte eines Pixels
struct pixel_rgb {
	pixel_rgb(unsigned char b, unsigned char g, 
		unsigned char r, unsigned char a);

	unsigned char r_, g_, b_, a_;
};




#endif // !INCLUDED_PATCHBOT_GRAPHIC_HPP

