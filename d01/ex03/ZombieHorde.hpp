#include "Zombie.hpp"
#include <iostream>
#include <string>
#define NAME_NUM 4
#define TYPE_NUM 5

#ifndef ZOMBIE_HORDE_HPP
# define ZOMBIE_HORDE_HPP

class ZombieHorde {
	public:
		void	announce(void);
		ZombieHorde(int N);
		~ZombieHorde(void);
	private:
		static std::string _names[];
		static std::string _types[];
		int 	_N;
		Zombie 	*_zombies;
};

#endif