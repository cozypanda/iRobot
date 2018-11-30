#ifndef INCLUDED_PATCHBOT_EXCEPTIONS_WORLD_CONFIG_HPP
#define INCLUDED_PATCHBOT_EXCEPTIONS_WORLD_CONFIG_HPP
#include <exception>
#include <string>

class exceptions_world_config : public std::exception {
private:
	std::string error_message_;
public:
	exceptions_world_config(std::string error_message);
	const char* what() const noexcept;
};
#endif // !INCLUDED_PATCHBOT_EXCEPTIONS_WORLD_CONFIG.H

