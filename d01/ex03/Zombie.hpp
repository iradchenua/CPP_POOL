#include <iostream>
#include <string>

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

class Zombie {
	public: 
		std::string name;
		std::string type;
		void	announce(void);
};

#endif