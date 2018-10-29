#include "Cure.hpp"
#define TYPE "cure"

Cure::Cure() : AMateria(TYPE) {
}

Cure::Cure(Cure const & ic) {
	*this = ic;
}

Cure & Cure::operator=(const Cure & ic) {
	this->AMateria::operator=(ic);
	return (*this);
}

Cure::~Cure() {
}

AMateria *Cure::clone() const {
	AMateria *newMateria = new Cure();
	return (newMateria);
}


void Cure::use(ICharacter & target) {
	this->AMateria::use(target);
	std::cout << "* heals " \
	<< target.getName() \
	<< "'s wounds * " \
	<< std::endl;
}