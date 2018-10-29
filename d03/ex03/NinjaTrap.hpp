#include "ClapTrap.hpp"

#define SHOES_NUM 3

#ifndef Ninja_TRAP_H
#define Ninja_TRAP_H

class NinjaTrap : public ClapTrap {
	public:
		NinjaTrap(void);
		NinjaTrap(NinjaTrap const & Ninja);
		NinjaTrap(std::string name);

		~NinjaTrap(void);
		NinjaTrap & operator=(NinjaTrap const & Ninja);

		void		ninjaShoebox(ClapTrap const & clap);

	private:

		void		_joke1(ClapTrap const & clap);
		void		_joke2(ClapTrap const & clap);
		void		_joke3(ClapTrap const & clap);
		static int const _maxHp;
		static int const _maxEp;
};

#endif