#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) : _type(type) {

}

AMateria::AMateria() : _type("no type"), xp_(0) {
}

AMateria::AMateria(AMateria const & am) : _type(am.getType()) {
	*this = am;
}

AMateria & AMateria::operator=(const AMateria & am) {
	this->xp_ = am.getXP();
	return (*this);
}

AMateria::~AMateria() {
}

unsigned int	AMateria::getXP() const {
	return (this->xp_);
}

std::string const &	AMateria::getType() const {
	return (this->_type);
}

void AMateria::use(ICharacter & target) {
	this->xp_ += 10;
	(void)target;
}