#include "Enemy.hpp"

#ifndef SUPER_MUTANT_HPP
#define SUPER_MUTANT_HPP

class SuperMutant : public Enemy {
	public:
		SuperMutant();
		SuperMutant(int hp, std::string const & type);
		SuperMutant(SuperMutant const & en);

		~SuperMutant();

		SuperMutant & operator=(const SuperMutant & en);

		virtual void takeDamage(int damage);
};

#endif