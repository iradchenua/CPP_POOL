#include "TacticalMarine.hpp"

#ifndef ASSAULT_TERMINATOR_HPP
#define ASSAULT_TERMINATOR_HPP

class AssaultTerminator : public ISpaceMarine {
	public: 
		AssaultTerminator();
		AssaultTerminator(AssaultTerminator const & AssaultTerminator);

		~AssaultTerminator();

		AssaultTerminator & operator=(const AssaultTerminator & marine);

		ISpaceMarine *clone() const;
		void	battleCry() const;
		void	rangedAttack() const;
		void	meleeAttack() const;
};

#endif