#include "exceptions.hpp"
exceptions::exceptions(std::string error_message)
	: error_message_(error_message)
{}
const char* exceptions::what() const noexcept
{
	return error_message_.c_str();
}

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

