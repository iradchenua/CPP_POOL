#ifndef Terrorist_CLASS_HPP
#define Terrorist_CLASS_HPP

#include "AGameEntity.class.hpp"

class Terrorist:public AGameEntity
{
public:
	~Terrorist();
	Terrorist &operator=(const Terrorist &rhs);
	Terrorist();
	Terrorist(int x, int y);
	Terrorist(const Terrorist &rhs);
};

#endif