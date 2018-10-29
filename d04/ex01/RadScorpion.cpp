#include "RadScorpion.hpp"
#define HP 80
#define TYPE "Rad Scorpion"

RadScorpion::RadScorpion() : Enemy(HP, TYPE) {
	std::cout << "* click click click *" << std::endl;
}

RadScorpion::~RadScorpion() {
	std::cout << "* SPROTCH *" << std::endl;
}

RadScorpion::RadScorpion(int hp, std::string const & type) : Enemy(HP, TYPE) {
	(void)type;
	(void)hp;
}

RadScorpion::RadScorpion(RadScorpion const & en)  {
	*this = en;
}

RadScorpion & RadScorpion::operator=(const RadScorpion & en) {
	this->Enemy::operator=(en);
	return (*this);
}