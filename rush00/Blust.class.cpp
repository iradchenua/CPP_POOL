#include "AGameEntity.class.hpp"
#include "Blust.class.hpp"
#include <iostream>

Blust::Blust():AGameEntity()
{
    _speed = -0.002;
    _entityModel = '!';
    _entityColorPairId = (std::rand() + 1) % 7;;
}

Blust::Blust(int x, int y):AGameEntity(x, y)
{
    _isAlive = 0;
    _speed = -0.002;
    _entityModel = '!';
    _entityColorPairId = (std::rand() + 1) % 7;;
}

Blust::Blust(const Blust &rhs):AGameEntity(rhs)
{
    _isAlive = 0;
    _speed = -0.002;
    _entityModel = '!';
    _entityColorPairId = (std::rand() + 1) % 7;;
}
Blust::~Blust()
{
	
}

Blust &Blust::operator=(const Blust &rhs)
{
	if (this == &rhs)
		return (*this);
	_x = rhs.getX();
	_y = rhs.getY();
	return (*this);
}