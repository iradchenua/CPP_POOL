#include <string>
#include <iostream>

#define CHALANGE_NUM 4 

#ifndef SCAV_TRAP_H
#define SCAV_TRAP_H

class ScavTrap {
	public:
		ScavTrap(void);
		ScavTrap(ScavTrap const & Scav);
		ScavTrap(std::string name);

		~ScavTrap(void);
		ScavTrap & operator=(ScavTrap const & Scav);

		void rangedAttack(std::string const & target) const;
		void meleeAttack(std::string const & target) const;

		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		void		challengeNewcomer(void);

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

	private:
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
		static std::string const _challenges[CHALANGE_NUM];

};

std::ostream & operator<<(std::ostream & o, ScavTrap const & Scav);

#endif