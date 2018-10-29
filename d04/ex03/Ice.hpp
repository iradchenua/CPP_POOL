#include "AMateria.hpp"

#ifndef ICE_HPP
#define ICE_HPP

class Ice : public AMateria {
	public:
		Ice();
		Ice(Ice const & ic);

		~Ice();

		Ice & operator=(const Ice & ic);

		virtual AMateria *clone() const;
		virtual void use(ICharacter & target);
};

#endif