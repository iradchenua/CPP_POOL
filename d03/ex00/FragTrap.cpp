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

int FragTrap::getHp(void) const {
	return (this->_hp);
}

int FragTrap::getEp(void) const {
	return (this->_ep);
}

int FragTrap::getLvl(void) const {
	return (this->_lvl);
}

std::string FragTrap::getName(void) const {
	return (this->_name);
}

int FragTrap::getMeleeDamage(void) const {
	return (this->_meleeDamage);
}

int FragTrap::getRangeDamage(void) const {
	return (this->_rangeDamage);
}

int FragTrap::getArmorDamageReduce(void) const {
	return (this->_armorDamageReduce);
}

void FragTrap::setHp(int val)  {
	if (val < 0)
		this->_hp = 0;
	else if (val > FragTrap::_maxHp)
		this->_hp = FragTrap::_maxHp;
	else
		this->_hp = val;

}

void FragTrap::setEp(int val)  {
	if (val < 0)
		this->_ep = 0;
	else if (val > FragTrap::_maxEp)
		this->_ep = FragTrap::_maxEp;
	else
		this->_ep = val;
}

void FragTrap::setLvl(int val)  {
	this->_lvl = val;
}

void FragTrap::setName(std::string name)  {
	this->_name = name;
}

void FragTrap::setMeleeDamage(int val)  {
	this->_meleeDamage = val;
}

void FragTrap::setRangeDamage(int val)  {
	this->_rangeDamage = val;
}

void FragTrap::setArmorDamageReduce(int val)  {
	this->_armorDamageReduce = val;
}


FragTrap::FragTrap(FragTrap const & frag) {
	std::cout << "Copy Constructor is called!" << std::endl;
	*this = frag;
}

FragTrap::FragTrap(std::string name) {
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

void	FragTrap::meleeAttack(std::string const & target) const {
	std::cout << this->getName() \
	<< " attacks " << target \
	<< " at melee range, causing " \
	<< this->getMeleeDamage() \
	<< " points of damage !" 
	<< std::endl;
}

void	FragTrap::rangedAttack(std::string const & target) const {
	std::cout << this->getName() << \
	" attacks " << target  <<\
	" at range, causing " << this->getRangeDamage() \
	<< " points of damage !" \
	<< std::endl;
}

void	FragTrap::takeDamage(unsigned int amount) {
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

void	FragTrap::beRepaired(unsigned int amount) {

	std::cout << this->getName() << "is repaired by " \
	<< amount << " of hp " << std::endl;
	this->setHp(this->getHp() + amount);
	std::cout << this->getName() << " hp is " \
	<<this->getHp() << std::endl;
}

std::ostream & operator<<(std::ostream & o, FragTrap const & frag) {
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
int const FragTrap::_minHp = 0;
int const FragTrap::_minEp = 0;
int const FragTrap::_maxHp = 100;
int const FragTrap::_maxEp = 100;
int const FragTrap::_attacks[ATTACK_NUM] = {1, 50, 20, 40, 10, 2, 5, 8, 9, 100};