#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap(void) {
	std::cout << "Ninja Default constructor is called!" << std::endl;
	this->_hp = 60;
	this->_ep = 120;
	this->_lvl = 1;
	this->_name = "no name";
	this->_meleeDamage = 60;
	this->_rangeDamage = 5;
	this->_armorDamageReduce = 0;
	std::srand(std::time(0));
}

NinjaTrap::~NinjaTrap(void) {
	std::cout << "Ninja Destructor called" << std::endl;
}

NinjaTrap::NinjaTrap(NinjaTrap const & frag) {
	std::cout << "Ninja Copy Constructor is called!" << std::endl;
	*this = frag;
}

NinjaTrap::NinjaTrap(std::string name) {
	std::cout << "Ninja constructor with name is called!" << std::endl;
	this->setHp(60);
	this->setEp(120);
	this->setLvl(1);
	this->setName(name);
	this->setMeleeDamage(60);
	this->setRangeDamage(5);
	this->setArmorDamageReduce(0);
}

NinjaTrap & NinjaTrap::operator=(NinjaTrap const & frag) {

	std::cout << "Ninja Assignation operator called" << std::endl;
	this->setHp(frag.getHp());
	this->setEp(frag.getEp());
	this->setLvl(frag.getLvl());
	this->setMeleeDamage(frag.getMeleeDamage());
	this->setRangeDamage(frag.getRangeDamage());
	this->setArmorDamageReduce(frag.getArmorDamageReduce());
	this->setName(frag.getName());
	return (*this);
}

void		NinjaTrap::_joke1(ClapTrap const & clap) {
	if (this->_ep >= 10)
	{
		this->setEp(this->_ep - 10);
		std::cout << "you move as your grandmother but not in the bed " << std::endl;
		this->rangedAttack(clap.getName());
	}
	else
		std::cout << "not enough energy to do joke2" << std::endl;
}

void		NinjaTrap::_joke2(ClapTrap const & clap) {
	if (this->_ep >= 5)
	{
		this->setEp(this->_ep - 5);
		std::cout << " take the rock of destiny " << std::endl;
		this->meleeAttack(clap.getName());
	}
	else
		std::cout << "not enough energy to do joke2" << std::endl;
}


void		NinjaTrap::_joke3(ClapTrap const & clap) {
	if (this->_ep >= 30)
	{
		this->setEp(this->_ep - 30);
		std::cout << " this star and this blade will kill you, motherfucker " << std::endl;
		this->meleeAttack(clap.getName());
		this->rangedAttack(clap.getName());
	}
	else
		std::cout << "not enough energy to do joke2" << std::endl;
}

void		NinjaTrap::ninjaShoebox(ClapTrap const & clap) {
	int i = rand() % SHOES_NUM;

	if (i == 0)
		this->_joke1(clap);
	else if (i == 1)
		this->_joke2(clap);
	else
		this->_joke3(clap);
}

int const NinjaTrap::_maxHp = 60;
int const NinjaTrap::_maxEp = 120;