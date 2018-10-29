#include "AWeapon.hpp"

#ifndef PLASMA_RIFLE_HPP
#define PLASMA_RIFLE_HPP

class PlasmaRifle : public AWeapon {
	public:
		PlasmaRifle();
		PlasmaRifle(std::string const & name, int apcost, int damage);
		PlasmaRifle(PlasmaRifle const & plr);

		~PlasmaRifle();

		PlasmaRifle & operator=(const PlasmaRifle & awp);

		virtual void attack() const;
};

#endif