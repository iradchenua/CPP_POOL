#include <string>
#include <iostream>

#ifndef CLAP_TRAP_H
#define CLAP_TRAP_H

class ClapTrap {
	public:
		ClapTrap(void);
		ClapTrap(ClapTrap const & Clap);
		ClapTrap(std::string name);

		~ClapTrap(void);
		ClapTrap & operator=(ClapTrap const & Clap);

		void rangedAttack(std::string const & target) const;
		void meleeAttack(std::string const & target) const;

		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		int  		getHp(void) const;
		int  		getEp(void) const;
		int  		getLvl(void) const;
		std::string  getName(void) const;
		int  		getMeleeDamage(void) const;
		int  		getRangeDamage(void) const;
		int  		getArmorDamageReduce(void) const;

		void  		setHp(int val);
		void 		setEp(int val);
		void 		setLvl(int val);
		void 		setName(std::string val);
		void  		setMeleeDamage(int val);
		void 		setRangeDamage(int val);
		void 		setArmorDamageReduce(int val);

	protected:
		int _hp;
		int _ep;
		int _lvl;

		std::string _name;

		int _meleeDamage;
		int _rangeDamage;

		int _armorDamageReduce;

		static int const _minHp;
		static int const _minEp;
		static int const _maxHp;
		static int const _maxEp;
};

std::ostream & operator<<(std::ostream & o, ClapTrap const & Clap);

#endif