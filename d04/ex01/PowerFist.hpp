#include "AWeapon.hpp"

#ifndef POWER_FIST_HPP
#define POWER_FIST_HPP

class PowerFist : public AWeapon {
	public:
		PowerFist();
		PowerFist(std::string const & name, int apcost, int damage);
		PowerFist(PowerFist const & plr);

		~PowerFist();

		PowerFist & operator=(const PowerFist & awp);

		virtual void attack() const;
};

#endif