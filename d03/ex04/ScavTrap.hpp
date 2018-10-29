#include "ClapTrap.hpp"

#define CHALANGE_NUM 4 

#ifndef SCAV_TRAP_H
#define SCAV_TRAP_H

class ScavTrap : public ClapTrap {
	public:
		ScavTrap(void);
		ScavTrap(ScavTrap const & Scav);
		ScavTrap(std::string name);

		~ScavTrap(void);
		ScavTrap & operator=(ScavTrap const & Scav);

		void		challengeNewcomer(void);

	private:
		static std::string const _challenges[CHALANGE_NUM];
		static int const _maxEp;
};

#endif