#include "Weapon.hpp"

#ifndef HUMANA_HPP
#define HUMANA_HPP

class HumanA {
	public:
		HumanA(std::string name, Weapon & Weapon);
		void	attack(void);
	private:
		std::string _name;
		Weapon 		&_weapon;
};

#endif