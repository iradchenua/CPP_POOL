#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) {
	std::cout << "Clap Default constructor is called!" << std::endl;
	this->_hp = 100;
	this->_ep = 100;
	this->_lvl = 1;
	this->_name = "no name";
	this->_meleeDamage = 30;
	this->_rangeDamage = 20;
	this->_armorDamageReduce = 5;
	std::srand(std::time(0));
}

ClapTrap::~ClapTrap(void) {
	std::cout << "Clap Destructor called" << std::endl;
}

int ClapTrap::getHp(void) const {
	return (this->_hp);
}

int ClapTrap::getEp(void) const {
	return (this->_ep);
}

int ClapTrap::getLvl(void) const {
	return (this->_lvl);
}

std::string ClapTrap::getName(void) const {
	return (this->_name);
}

int ClapTrap::getMeleeDamage(void) const {
	return (this->_meleeDamage);
}

int ClapTrap::getRangeDamage(void) const {
	return (this->_rangeDamage);
}

int ClapTrap::getArmorDamageReduce(void) const {
	return (this->_armorDamageReduce);
}

void ClapTrap::setHp(int val)  {
	if (val < 0)
		this->_hp = 0;
	else if (val > ClapTrap::_maxHp)
		this->_hp = ClapTrap::_maxHp;
	else
		this->_hp = val;

}

void ClapTrap::setEp(int val)  {
	if (val < 0)
		this->_ep = 0;
	else if (val > ClapTrap::_maxEp)
		this->_ep = ClapTrap::_maxEp;
	else
		this->_ep = val;
}

void ClapTrap::setLvl(int val)  {
	this->_lvl = val;
}

void ClapTrap::setName(std::string name)  {
	this->_name = name;
}

void ClapTrap::setMeleeDamage(int val)  {
	this->_meleeDamage = val;
}

void ClapTrap::setRangeDamage(int val)  {
	this->_rangeDamage = val;
}

void ClapTrap::setArmorDamageReduce(int val)  {
	this->_armorDamageReduce = val;
}


ClapTrap::ClapTrap(ClapTrap const & clap) {
	std::cout << "Clap Copy Constructor is called!" << std::endl;
	*this = clap;
}

ClapTrap::ClapTrap(std::string name) {
	std::cout << "Clap constructor with name is called!" << std::endl;
	this->setHp(100);
	this->setEp(100);
	this->setLvl(1);
	this->setName(name);
	this->setMeleeDamage(30);
	this->setRangeDamage(20);
	this->setArmorDamageReduce(5);
}

ClapTrap & ClapTrap::operator=(ClapTrap const & clap) {

	std::cout << "Clap Assignation operator called" << std::endl;
	this->setHp(clap.getHp());
	this->setEp(clap.getEp());
	this->setLvl(clap.getLvl());
	this->setMeleeDamage(clap.getMeleeDamage());
	this->setRangeDamage(clap.getRangeDamage());
	this->setArmorDamageReduce(clap.getArmorDamageReduce());
	this->setName(clap.getName());
	return (*this);
}

void	ClapTrap::meleeAttack(std::string const & target) const {
	std::cout << this->getName() \
	<< " attacks " << target \
	<< " at melee range, causing " \
	<< this->getMeleeDamage() \
	<< " points of damage !" 
	<< std::endl;
}

void	ClapTrap::rangedAttack(std::string const & target) const {
	std::cout << this->getName() << \
	" attacks " << target  <<\
	" at range, causing " << this->getRangeDamage() \
	<< " points of damage !" \
	<< std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
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

void	ClapTrap::beRepaired(unsigned int amount) {

	std::cout << this->getName() << "is repaired by " \
	<< amount << " of hp " << std::endl;
	this->setHp(this->getHp() + amount);
	std::cout << this->getName() << " hp is " \
	<<this->getHp() << std::endl;
}

std::ostream & operator<<(std::ostream & o, ClapTrap const & clap) {
	o << "Name is " << clap.getName() << std::endl \
	<< "--------------------------" << std::endl \
	<< "Hit points is " << clap.getHp() << std::endl \
	<< "Energy points is " << clap.getEp() << std::endl \
	<< "Lvl " << clap.getLvl() << std::endl \
	<< "Melee damage " << clap.getMeleeDamage() << std::endl \
	<< "Range damage " << clap.getRangeDamage() << std::endl \
	<< "Armor damage reduce " << clap.getArmorDamageReduce() \
	<< std::endl;
	return (o);
}

int const ClapTrap::_minHp = 0;
int const ClapTrap::_minEp = 0;
int const ClapTrap::_maxHp = 100;
int const ClapTrap::_maxEp = 100;