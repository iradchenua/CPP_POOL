#include <iostream>
#include <string>

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

class Zombie {
	public: 
		void	announce(void);
		std::string name;
		std::string type;
};

#endif