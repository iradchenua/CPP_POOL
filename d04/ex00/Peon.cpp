#include "Peon.hpp"

Peon::~Peon(void) {
	std::cout << "Bleuark..." \
	<< std::endl;
}

std::string Peon::getName(void) const {
	return (this->_name);
}

Peon::Peon(std::string const & name) : Victim(name), _name(name) {
	std::cout << "Zog zog" \
	<< std::endl;		
}

void	Peon::getPolymorphed(void) const {
	std::cout << this->getName() << \
	" has been turned into a pink pony !" \
	<< std::endl;
}

std::ostream & operator<<(std::ostream & o, Peon const & p) {
	o << "I am " << p.getName() \
	<< ", and i like otters !" \
	<< std::endl;
	return (o);
}