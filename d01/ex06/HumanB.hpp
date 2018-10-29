#include "Weapon.hpp"

#ifndef HUMANB_HPP
#define HUMANB_HPP

class HumanB {
	public:
		HumanB(std::string name);
		void	setWeapon(Weapon & weapon);
		void	attack(void);
	private:
		std::string _name;
		Weapon 		*_weapon;
};

#endif