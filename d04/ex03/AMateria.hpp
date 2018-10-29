#include <string>
#include <iostream>
#include "ICharacter.hpp"

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

class AMateria {
	private:
		std::string const _type;
		unsigned int xp_;
	public:
		AMateria();
		AMateria(std::string const & type);
		AMateria(AMateria const & am);

		virtual ~AMateria();

		AMateria & operator=(const AMateria & am);

		std::string const & getType() const;

		unsigned int getXP() const;
		
		virtual AMateria *clone() const = 0;
		virtual void use(ICharacter & target);
};

#endif