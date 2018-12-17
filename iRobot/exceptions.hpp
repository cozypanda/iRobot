#ifndef INCLUDED_PATCHBOT_EXCEPTIONS_WORLD_CONFIG_HPP
#define INCLUDED_PATCHBOT_EXCEPTIONS_WORLD_CONFIG_HPP
#include <exception>
#include <string>

class exceptions : public std::exception {
private:
	std::string error_message_;
public:
	exceptions(const std::string &error_message);
	const char* what() const noexcept;
};

/* World Exceptions */
class exceptions_missing_main_server : public exceptions {
public:
	exceptions_missing_main_server();
};

class exceptions_missing_starting_point : public exceptions {
public:
	exceptions_missing_starting_point();
};

class exceptions_too_many_starting_points : public exceptions {
public:
	exceptions_too_many_starting_points();
};

class exceptions_row_amount_mismatch : public exceptions {
public:
	exceptions_row_amount_mismatch();
};

class exceptions_row_length_mismatch : public exceptions {
public:
	exceptions_row_length_mismatch();
};

class exceptions_unknown_terrain_symbol : public exceptions {
public:
	exceptions_unknown_terrain_symbol();
};

class exceptions_input_not_int : public exceptions {
public:
	exceptions_input_not_int();
};

/* File Access Exceptions*/

class exceptions_file_error : public exceptions {
public:
	exceptions_file_error();
};


/* Graphic Exceptions */
class exceptions_reading_pixel_data : public exceptions {
public: 
	exceptions_reading_pixel_data();
};

class exceptions_reading_header_data : public exceptions {
public:
	exceptions_reading_header_data(const std::string &exception_string);
};

class exceptions_tga_id_length : public exceptions {
public:
	exceptions_tga_id_length();
};

class exceptions_tga_color_map_type : public exceptions {
public:
	exceptions_tga_color_map_type();
};

class exceptions_tga_data_type : public exceptions {
public:
	exceptions_tga_data_type();
};

class exceptions_tga_color_map_origin : public exceptions {
public:
	exceptions_tga_color_map_origin();
};

class exceptions_tga_color_map_length : public exceptions {
public:
	exceptions_tga_color_map_length();
};

class exceptions_tga_color_map_depth : public exceptions {
public:
	exceptions_tga_color_map_depth();
};

class exceptions_tga_x_origin : public exceptions {
public:
	exceptions_tga_x_origin();
};

class exceptions_tga_y_origin : public exceptions {
public:
	exceptions_tga_y_origin();
};

class exceptions_tga_width : public exceptions {
public:
	exceptions_tga_width();
};

class exceptions_tga_height : public exceptions {
public:
	exceptions_tga_height();
};

class exceptions_tga_bits_per_pixel : public exceptions {
public:
	exceptions_tga_bits_per_pixel();
};

class exceptions_tga_attributes : public exceptions {
public:
	exceptions_tga_attributes();
};

#endif // !INCLUDED_PATCHBOT_EXCEPTIONS_WORLD_CONFIG.H