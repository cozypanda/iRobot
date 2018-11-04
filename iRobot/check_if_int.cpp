#include "check_if_int.hpp"
#include <string>


bool has_only_digits(const std::string s)
{
	return s.find_first_not_of("0123456789") == std::string::npos;
}