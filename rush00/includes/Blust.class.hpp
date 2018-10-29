#ifndef Blust_CLASS_HPP
#define Blust_CLASS_HPP

#include "AGameEntity.class.hpp"

class Blust:public AGameEntity
{
public:
	Blust();
	Blust(int x, int y);
	Blust(const Blust &rhs);
	~Blust();
	Blust &operator=(const Blust &rhs);
};

#endif