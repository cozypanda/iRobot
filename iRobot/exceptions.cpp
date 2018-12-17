#include "exceptions.hpp"
exceptions::exceptions(const std::string &error_message)
	: error_message_(error_message)
{}
const char* exceptions::what() const noexcept
{
	return error_message_.c_str();
}


/* World Exceptions */

exceptions_missing_main_server::exceptions_missing_main_server()
	: exceptions("Main Server missing") {}

exceptions_missing_starting_point::exceptions_missing_starting_point()
	: exceptions("Starting point missing") {}

exceptions_too_many_starting_points::exceptions_too_many_starting_points()
	: exceptions("Too many starting points") {}

exceptions_row_amount_mismatch::exceptions_row_amount_mismatch()
	: exceptions("Row amount mismatch") {}

exceptions_row_length_mismatch::exceptions_row_length_mismatch()
	: exceptions("Row length mismatch") {}

exceptions_unknown_terrain_symbol::exceptions_unknown_terrain_symbol()
	: exceptions("Unknown terrain character") {}

exceptions_input_not_int::exceptions_input_not_int()
	: exceptions("Dimension input not of type int") {}

exceptions_file_error::exceptions_file_error()
	: exceptions("File could not be opened") {}


/* File Access Exceptions*/

exceptions_reading_pixel_data::exceptions_reading_pixel_data()
	: exceptions("Unexpected end of file") {}


/* Graphic Exceptions */

exceptions_tga_id_length::exceptions_tga_id_length()
	: exceptions("Header id length has to be 0") {}
exceptions_tga_color_map_type::exceptions_tga_color_map_type()
	: exceptions("Header color map type has to be 0") {}

exceptions_tga_data_type::exceptions_tga_data_type()
	: exceptions("Header data type has to be 2") {}

exceptions_tga_color_map_origin::exceptions_tga_color_map_origin()
	: exceptions("Header color map origin has to be 0") {}

exceptions_tga_color_map_length::exceptions_tga_color_map_length()
	: exceptions("Header color map length has to be 0") {}

exceptions_tga_color_map_depth::exceptions_tga_color_map_depth() 
: exceptions("Header color map depth has to be a positive value") {}

exceptions_tga_x_origin::exceptions_tga_x_origin()
	: exceptions("Header x origin has to be 0") {}

exceptions_tga_y_origin::exceptions_tga_y_origin()
	: exceptions("Header y origin has to be 0") {}

exceptions_tga_width::exceptions_tga_width()
	: exceptions("Header width has to be a positive value") {}

exceptions_tga_height::exceptions_tga_height()
	: exceptions("Header height has to be a positive value") {}

exceptions_tga_bits_per_pixel::exceptions_tga_bits_per_pixel()
	: exceptions("Header bits per pixel has to be 32") {}

exceptions_tga_attributes::exceptions_tga_attributes()
	: exceptions("Header attributes has to be a positive value") {}