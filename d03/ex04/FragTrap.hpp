#include "ClapTrap.hpp"

#define ATTACK_NUM 10

#ifndef FRAG_TRAP_H
#define FRAG_TRAP_H

class FragTrap : virtual public ClapTrap {
	public:
		FragTrap(void);
		FragTrap(FragTrap const & frag);
		FragTrap(std::string name);

		~FragTrap(void);
		FragTrap & operator=(FragTrap const & frag);

		void vaulthunter_dot_exe(std::string const & target);

	private:
		static int const _attacks[ATTACK_NUM];

};

#endif