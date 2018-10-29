#include "Brain.hpp"

std::string Brain::identify(void) const {
	std::stringstream ss;

	ss << this;
	return (ss.str());
}