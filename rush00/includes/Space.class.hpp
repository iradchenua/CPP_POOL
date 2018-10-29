#ifndef SPACE_CLASS_HPP
#define SPACE_CLASS_HPP

#include "AGameEntity.class.hpp"

class Space:public AGameEntity
{
public:
	Space();
	Space(int x, int y);
	Space(const Space &rhs);
	virtual ~Space();
	Space &operator=(const Space &rhs);
};

#endif