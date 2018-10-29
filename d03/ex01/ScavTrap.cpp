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

int ScavTrap::getHp(void) const {
	return (this->_hp);
}

int ScavTrap::getEp(void) const {
	return (this->_ep);
}

int ScavTrap::getLvl(void) const {
	return (this->_lvl);
}

std::string ScavTrap::getName(void) const {
	return (this->_name);
}

int ScavTrap::getMeleeDamage(void) const {
	return (this->_meleeDamage);
}

int ScavTrap::getRangeDamage(void) const {
	return (this->_rangeDamage);
}

int ScavTrap::getArmorDamageReduce(void) const {
	return (this->_armorDamageReduce);
}

void ScavTrap::setHp(int val)  {
	if (val < 0)
		this->_hp = 0;
	else if (val > ScavTrap::_maxHp)
		this->_hp = ScavTrap::_maxHp;
	else
		this->_hp = val;

}

void ScavTrap::setEp(int val)  {
	if (val < 0)
		this->_ep = 0;
	else if (val > ScavTrap::_maxEp)
		this->_ep = ScavTrap::_maxEp;
	else
		this->_ep = val;
}

void ScavTrap::setLvl(int val)  {
	this->_lvl = val;
}

void ScavTrap::setName(std::string name)  {
	this->_name = name;
}

void ScavTrap::setMeleeDamage(int val)  {
	this->_meleeDamage = val;
}

void ScavTrap::setRangeDamage(int val)  {
	this->_rangeDamage = val;
}

void ScavTrap::setArmorDamageReduce(int val)  {
	this->_armorDamageReduce = val;
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

void	ScavTrap::meleeAttack(std::string const & target) const {
	std::cout << this->getName() \
	<< " attacks " << target \
	<< " at melee range, causing " \
	<< this->getMeleeDamage() \
	<< " points of damage !" 
	<< std::endl;
}

void	ScavTrap::rangedAttack(std::string const & target) const {
	std::cout << this->getName() << \
	" attacks " << target  <<\
	" at range, causing " << this->getRangeDamage() \
	<< " points of damage !" \
	<< std::endl;
}

void	ScavTrap::takeDamage(unsigned int amount) {
	long 			newMount;

	newMount = amount - this->getArmorDamageReduce();
	std::cout << this->getName() << \
	" take damage "  << std::endl;
	if (newMount > 0)
	{
		this->setHp(this->getHp() - newMount);
		std::cout << "Total damage is "  << newMount \
		<< " damage reduce by armor " << this->getArmorDamageReduce() \
		<< " hp is " << this->getHp() \
		<< std::endl;
		return ;
	}
	std::cout << "All damage reduce by armor, well done!" << std::endl;
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

void	ScavTrap::beRepaired(unsigned int amount) {

	std::cout << this->getName() << "is repaired by " \
	<< amount << " of hp " << std::endl;
	this->setHp(this->getHp() + amount);
	std::cout << this->getName() << " hp is " \
	<<this->getHp() << std::endl;
}

std::ostream & operator<<(std::ostream & o, ScavTrap const & frag) {
	o << frag.getName() << std::endl \
	<< "--------------------------" << std::endl \
	<< frag.getHp() << std::endl \
	<< frag.getEp() << std::endl \
	<< frag.getLvl() << std::endl \
	<< frag.getMeleeDamage() << std::endl \
	<< frag.getRangeDamage() << std::endl \
	<< frag.getArmorDamageReduce() << std::endl;

	return (o);
}
int const ScavTrap::_minHp = 0;
int const ScavTrap::_minEp = 0;
int const ScavTrap::_maxHp = 100;
int const ScavTrap::_maxEp = 50;
std::string const ScavTrap::_challenges[CHALANGE_NUM] = {"eat socks", "fuck myself", "eat myself", "listen Buzova"};