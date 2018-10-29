#include "SuperTrap.hpp"

SuperTrap::SuperTrap(void) : NinjaTrap(), FragTrap() {
	std::cout << "new SuperTrap" << std::endl;
	this->_lvl = 1;
	this->_name = "no name";
	this->_meleeDamage = 60;
	std::srand(std::time(0));
}

SuperTrap::~SuperTrap(void) {
	std::cout << "dead SuperTrap" << std::endl;
}

SuperTrap::SuperTrap(SuperTrap const & frag) {
	std::cout << "Super Copy Constructor is called!" << std::endl;
	*this = frag;
}

SuperTrap & SuperTrap::operator=(SuperTrap const & super) {

	std::cout << "Super Assignation operator called" << std::endl;
	this->setHp(super.getHp());
	this->setEp(super.getEp());
	this->setLvl(super.getLvl());
	this->setMeleeDamage(super.getMeleeDamage());
	this->setRangeDamage(super.getRangeDamage());
	this->setArmorDamageReduce(super.getArmorDamageReduce());
	this->setName(super.getName());
	return (*this);
}

SuperTrap::SuperTrap(std::string name) : NinjaTrap(name), FragTrap(name) {

	std::cout << "new SuperTrap with name" << std::endl;
	this->_lvl = 1;
	this->_meleeDamage = 60;
	std::srand(std::time(0));
}

void SuperTrap::meleeAttack(std::string const & target) const {
	this->NinjaTrap::meleeAttack(target);
}

void SuperTrap::rangedAttack(std::string const & target) const {
	this->FragTrap::rangedAttack(target);
}

int const SuperTrap::_maxEp = NinjaTrap::getMaxEp();