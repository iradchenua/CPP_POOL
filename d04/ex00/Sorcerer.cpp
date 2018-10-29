#include "Sorcerer.hpp"

Sorcerer::~Sorcerer(void) {
	std::cout << this->getName() << \
	", " << this->getTitle() << \
	", is dead. Consequences will never be the same !" \
	<< std::endl;
}

std::string Sorcerer::getName(void) const {
	return (this->_name);
}

std::string Sorcerer::getTitle(void) const {
	return (this->_title);
}

void	Sorcerer::polymorph(Victim const & v) const {
	v.getPolymorphed();
}

Sorcerer::Sorcerer(std::string const & name, std::string const & title) : _name(name), _title(title) {
	std::cout << this->getName() << ", " \
	<<this->getTitle() << ", " << "is born !" \
	<< std::endl;		
}

std::ostream & operator<<(std::ostream & o, Sorcerer const & s) {
	o << "I am " << s.getName() \
	<< ", " << s.getTitle() \
	<< ", and I like ponies !" \
	<< std::endl;
	return (o);
}