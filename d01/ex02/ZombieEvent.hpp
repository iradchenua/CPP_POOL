#include "Zombie.hpp"
#include <iostream>
#include <string>
#define NAME_NUM 4
#define TYPE_NUM 5

#ifndef ZOMBIE_EVENT_HPP
# define ZOMBIE_EVENT_HPP

class ZombieEvent {
	public: 
		static void	setZombieType(Zombie *zombie, std::string type);
		static Zombie 	*newZombie(std:: string name);
		static Zombie 	*randomChump(void);
	private:
		static std::string _names[];
		static std::string _types[];
};

#endif