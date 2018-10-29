#include "PlasmaRifle.hpp"
#define APCOST 5
#define DAMAGE 21
#define NAME "Plasma Rifle"

PlasmaRifle::PlasmaRifle() : AWeapon(NAME, APCOST, DAMAGE) {

}

PlasmaRifle::~PlasmaRifle() {

}

PlasmaRifle::PlasmaRifle(std::string const & name, int apcost, int damage) : AWeapon(NAME, APCOST, DAMAGE) {
	(void)name;
	(void)apcost;
	(void)damage;
}

PlasmaRifle::PlasmaRifle(PlasmaRifle const & plr) {
	(void)plr;
}

PlasmaRifle & PlasmaRifle::operator=(PlasmaRifle const & plr) {
	(void)plr;
	return (*this);
}

void PlasmaRifle::attack() const {
	std::cout << "* piouuu piouuu piouuu *" << std::endl;
}