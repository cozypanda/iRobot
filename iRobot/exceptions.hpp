#ifndef INCLUDED_PATCHBOT_EXCEPTIONS_WORLD_CONFIG_HPP
#define INCLUDED_PATCHBOT_EXCEPTIONS_WORLD_CONFIG_HPP
#include <exception>
#include <string>

class exceptions : public std::exception {
private:
	std::string error_message_;
public:
	exceptions(std::string error_message);
	const char* what() const noexcept;
};


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

class exceptions_file_error : public exceptions {
public:
	exceptions_file_error();

};

#endif // !INCLUDED_PATCHBOT_EXCEPTIONS_WORLD_CONFIG.H