#include "Victim.hpp"

Victim::~Victim(void) {
	std::cout << "Victim " \
	<< this->getName() << \
	" just died for no apparent reason" \
	<< std::endl;
}

std::string Victim::getName(void) const {
	return (this->_name);
}

Victim::Victim(std::string const & name) : _name(name) {
	std::cout << "Some random victim called " << \
	this->getName() << " just popped !" \
	<< std::endl;		
}

void	Victim::getPolymorphed(void) const {
	std::cout << this->getName() << \
	" has been turned into a cute little sheep !" \
	<< std::endl;
}

std::ostream & operator<<(std::ostream & o, Victim const & v) {
	o << "I am " << v.getName() \
	<< ", and i like otters !" \
	<< std::endl;
	return (o);
}