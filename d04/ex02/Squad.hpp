#include "ISquad.hpp"

#ifndef SQUAD_HPP
#define SQUAD_HPP

class Squad : public ISquad {
	private:
		int _count;
		ISpaceMarine **_marines;
		void	_deleteMarines();
		int 	_searchMarine(ISpaceMarine *marine);
	public:
		Squad();
		Squad(Squad const & squad);

		~Squad();

		Squad & operator=(const Squad & sq);

		int getCount() const;
		virtual ISpaceMarine *getUnit(int) const;
		virtual int push(ISpaceMarine *);
};

#endif