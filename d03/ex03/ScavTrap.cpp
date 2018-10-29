#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) {
	std::cout << "Scav Default constructor is called!" << std::endl;
	this->_hp = 100;
	this->_ep = 50;
	this->_lvl = 1;
	this->_name = "no name";
	this->_meleeDamage = 20;
	this->_rangeDamage = 15;
	this->_armorDamageReduce = 3;
	std::srand(std::time(0));
}

ScavTrap::~ScavTrap(void) {
	std::cout << "Scav Destructor called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const & frag) {
	std::cout << "Scav Copy Constructor is called!" << std::endl;
	*this = frag;
}

ScavTrap::ScavTrap(std::string name) {
	std::cout << "Scav constructor with name is called!" << std::endl;
	this->setHp(100);
	this->setEp(50);
	this->setLvl(1);
	this->setName(name);
	this->setMeleeDamage(20);
	this->setRangeDamage(15);
	this->setArmorDamageReduce(3);
}

ScavTrap & ScavTrap::operator=(ScavTrap const & frag) {

	std::cout << "Scav Assignation operator called" << std::endl;
	this->setHp(frag.getHp());
	this->setEp(frag.getEp());
	this->setLvl(frag.getLvl());
	this->setMeleeDamage(frag.getMeleeDamage());
	this->setRangeDamage(frag.getRangeDamage());
	this->setArmorDamageReduce(frag.getArmorDamageReduce());
	this->setName(frag.getName());
	return (*this);
}

void	ScavTrap::challengeNewcomer(void) {
	if (this->getEp() >= 25)
	{
		std::cout << this->getName() \
		<< " take random challenge  " << ScavTrap::_challenges[std::rand() % CHALANGE_NUM] \
		<< " i hope it will be easy " \
		<< std::endl;
		this->setEp(this->getEp() - 25);
	}
	else
		std::cout << this->getName() << " not enough energy for attack with " \
		<< " vaulthunter_dot_exe, need more or equal 25 energy points " << std::endl;
}

std::string const ScavTrap::_challenges[CHALANGE_NUM] = {"eat socks", "fuck myself", "eat myself", "listen Buzova"};
int const ScavTrap::_maxEp = 50;