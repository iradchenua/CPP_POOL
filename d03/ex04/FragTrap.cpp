#include "FragTrap.hpp"

FragTrap::FragTrap(void) {
	std::cout << "Frag Default constructor is called!" << std::endl;
	this->_hp = 100;
	this->_ep = 100;
	this->_lvl = 1;
	this->_name = "no name";
	this->_meleeDamage = 30;
	this->_rangeDamage = 20;
	this->_armorDamageReduce = 5;
	std::srand(std::time(0));
}

FragTrap::~FragTrap(void) {
	std::cout << "Frag Destructor called" << std::endl;
}


FragTrap::FragTrap(FragTrap const & frag) {
	std::cout << "Frag Copy Constructor is called!" << std::endl;
	*this = frag;
}

FragTrap::FragTrap(std::string name) {
	std::cout << "Frag constructor with name is called!" << std::endl;
	this->setHp(100);
	this->setEp(100);
	this->setLvl(1);
	this->setName(name);
	this->setMeleeDamage(30);
	this->setRangeDamage(20);
	this->setArmorDamageReduce(5);
}

FragTrap & FragTrap::operator=(FragTrap const & frag) {

	std::cout << "Frag Assignation operator called" << std::endl;
	this->setHp(frag.getHp());
	this->setEp(frag.getEp());
	this->setLvl(frag.getLvl());
	this->setMeleeDamage(frag.getMeleeDamage());
	this->setRangeDamage(frag.getRangeDamage());
	this->setArmorDamageReduce(frag.getArmorDamageReduce());
	this->setName(frag.getName());
	return (*this);
}

void	FragTrap::vaulthunter_dot_exe(std::string const & target) {
	if (this->getEp() >= 25)
	{
		std::cout << this->getName() << \
		" attacks " << target \
		<< " with random attack  " << FragTrap::_attacks[std::rand() % ATTACK_NUM] \
		<< " points of damage !" \
		<< std::endl;
		this->setEp(this->getEp() - 25);
	}
	else
		std::cout << this->getName() << " not enough energy for attack with " \
		<< " vaulthunter_dot_exe, need more or equal 25 energy points " << std::endl;
}

int const FragTrap::_attacks[ATTACK_NUM] = {1, 50, 20, 40, 10, 2, 5, 8, 9, 100};