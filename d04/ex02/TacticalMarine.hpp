#include "ISpaceMarine.hpp"

#ifndef TACTICAL_MARINE_HPP
#define TACTICAL_MARINE_HPP

class TacticalMarine : public ISpaceMarine {
	public: 
		TacticalMarine();
		TacticalMarine(TacticalMarine const & TacticalMarine);

		~TacticalMarine();

		TacticalMarine & operator=(const TacticalMarine & marine);

		ISpaceMarine *clone() const;
		void	battleCry() const;
		void	rangedAttack() const;
		void	meleeAttack() const;
};

#endif