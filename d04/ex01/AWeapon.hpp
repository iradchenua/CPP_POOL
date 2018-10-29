#include <string>
#include <iostream>

#ifndef AWEAPON_HPP
#define AWEAPON_HPP

class AWeapon {
	private:
		std::string const _name;
		int const _apcost;
		int const _damage;
	public:
		AWeapon();
		AWeapon(std::string const & name, int apcost, int damage);
		AWeapon(AWeapon const & awp);

		~AWeapon();

		AWeapon & operator=(const AWeapon & awp);

		std::string getName() const;

		int getAPcost() const;
		int getDamage() const;

		virtual void attack() const = 0;
};

std::ostream & operator<<(std::ostream & o, AWeapon const & awp);

#endif