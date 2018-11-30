#include "exceptions_world_config.hpp"
exceptions_world_config::exceptions_world_config(std::string error_message)
	: error_message_(error_message)
{}
const char* exceptions_world_config::what() const noexcept
{
	return error_message_.c_str();
}