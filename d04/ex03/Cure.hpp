#include "AMateria.hpp"

#ifndef CURE_HPP
#define CURE_HPP

class Cure : public AMateria {
	public:
		Cure();
		Cure(Cure const & ic);

		~Cure();

		Cure & operator=(const Cure & ic);

		virtual AMateria *clone() const;
		virtual void use(ICharacter & target);
};

#endif