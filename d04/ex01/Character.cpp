#include "Character.hpp"
#define AP 40

Character::Character() : _name("no name"), _AP(AP), _weapon(NULL) {
	//std::cout << "* click click click *" << std::endl;
}

Character::~Character() {
	//std::cout << "* SPROTCH *" << std::endl;
}

Character::Character(std::string const & name) : _name(name), _AP(AP),  _weapon(NULL) {

}

Character::Character(Character const & ch) : _name(ch.getName()), _AP(AP), _weapon(NULL)  {
	//*this = ch;
}

std::string Character::getName() const {
	return (this->_name);
}

int Character::getAP() const {
	return (this->_AP);
}

AWeapon *Character::getWeapon() const {
	return (this->_weapon);
}

void Character::_setAP(int ap) {
	if (ap > AP)
		this->_AP = AP;
	else
		this->_AP = ap;
}

void Character::equip(AWeapon *weapon) {
	this->_weapon = weapon;
}

void Character::attack(Enemy *en) {
	if (!this->_weapon || !en)
		return ;
	int APCost = this->_weapon->getAPcost();
	if (APCost <= this->_AP) {

		std::cout << this->_name \
		<< " attacks " << en->getType() \
		<< " with a " << this->_weapon->getName() \
		<< std::endl;
		this->_weapon->attack();
		this->_setAP(this->_AP - APCost);
		if (en->getHp() <= 0)
			return ;
		en->takeDamage(this->_weapon->getDamage());
		if (en->getHp() <= 0)
			delete en;
	}
}

void Character::recoverAP() {
	this->_setAP(this->_AP + 10);
}

Character & Character::operator=(const Character & ch) {
	(void)ch;
	return (*this);
}


std::ostream & operator<<(std::ostream & o, Character const & ch) {
	AWeapon *weapon;

	o << ch.getName() \
	<< " has " \
	<< ch.getAP() \
	<< " AP and ";
	weapon = ch.getWeapon();
	if (weapon) {
		o << "wields a " \
		<< weapon->getName();
	}
	else {
		o << "is unarmed";
	}
	o << std::endl;
	return (o);
}
