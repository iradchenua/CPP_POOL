#include "SuperMutant.hpp"
#define HP 170
#define TYPE "Super Mutant"

SuperMutant::SuperMutant() : Enemy(HP, TYPE) {
	std::cout << "Gaaah. Me want smash heads !" << std::endl;
}

SuperMutant::~SuperMutant() {
	std::cout << "Aaargh ..." << std::endl;
}

SuperMutant::SuperMutant(int hp, std::string const & type) : Enemy(HP, TYPE) {
	(void)type;
	(void)hp;
}

SuperMutant::SuperMutant(SuperMutant const & en)  {
	*this = en;
}

SuperMutant & SuperMutant::operator=(const SuperMutant & en) {
	this->Enemy::operator=(en);
	return (*this);
}

void SuperMutant::takeDamage(int damage) {
	this->Enemy::takeDamage(damage - 3);
}
