#include "Enemy.hpp"

#ifndef RAD_SCORPION_HPP
#define RAD_SCORPION_HPP

class RadScorpion : public Enemy {
	public:
		RadScorpion();
		RadScorpion(int hp, std::string const & type);
		RadScorpion(RadScorpion const & en);

		~RadScorpion();

		RadScorpion & operator=(const RadScorpion & en);

};

#endif