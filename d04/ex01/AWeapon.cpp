#include "AWeapon.hpp"

AWeapon::AWeapon() : _name("undefined"), _apcost(0), _damage(0) {

}

AWeapon::~AWeapon() {
	return ;
}

AWeapon::AWeapon(std::string const & name, int apcost, int damage) : \
						 _name(name), _apcost(apcost), _damage(damage) {

}

AWeapon::AWeapon(AWeapon const & awp)  : _name(awp.getName()) , _apcost(awp.getAPcost()), _damage(awp.getDamage()) {
	//*this = awp;
}

AWeapon & AWeapon::operator=(const AWeapon & awp) {
	(void)awp;
	return (*this);
}

int AWeapon::getAPcost() const {
	return (this->_apcost);
}

std::string AWeapon::getName() const {
	return (this->_name);
}

int AWeapon::getDamage() const {
	return (this->_damage);
}

std::ostream & operator<<(std::ostream & o, AWeapon const & awp) {
	o << "Weapon " \
	<< awp.getName() \
	<< " has damage " \
	<< awp.getDamage() \
	<< " with " \
	<< awp.getAPcost() \
	<< " apcost." \
	<< std::endl \
	<< " with attack: " \
	<< std::endl;
	awp.attack();
	return (o);
}