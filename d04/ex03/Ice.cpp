#include "Ice.hpp"
#define TYPE "ice"

Ice::Ice() : AMateria(TYPE) {
	//std::cout << "* teleports from space *" << std::endl;
}

Ice::Ice(Ice const & ic) {
	*this = ic;
	//std::cout << "* teleports from space *" << std::endl;
}

Ice & Ice::operator=(const Ice & ic) {
	this->AMateria::operator=(ic);
	return (*this);
}

Ice::~Ice() {
	//std::cout << "I’ll be back ..." << std::endl;
}

AMateria *Ice::clone() const {
	AMateria *newMateria = new Ice();
	return (newMateria);
}


void Ice::use(ICharacter & target) {
	this->AMateria::use(target);
	std::cout << "* shoots an ice bolt at "  \
	<< target.getName() << \
	" *" << std::endl;
}