#include "PowerFist.hpp"

#define APCOST 8
#define DAMAGE 50

PowerFist::PowerFist() : AWeapon("Power Fist", APCOST, DAMAGE) {

}

PowerFist::~PowerFist() {

}



PowerFist::PowerFist(std::string const & name, int apcost, int damage) : AWeapon("Power Fist", APCOST, DAMAGE) {
	(void)name;
	(void)apcost;
	(void)damage;
}

PowerFist::PowerFist(PowerFist const & plr) : AWeapon(plr) {

}

PowerFist & PowerFist::operator=(PowerFist const & plr) {
	this->AWeapon::operator=(plr);
	return (*this);
}

void PowerFist::attack() const {
	std::cout << "* pschhh... SBAM! *" << std::endl;
}