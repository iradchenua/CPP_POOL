#include "AGameEntity.class.hpp"
#include "Space.class.hpp"
#include <iostream>

Space::Space():AGameEntity()
{
    _isAlive = true;
    _speed = 0.00051;
    _entityModel = '.';
    _entityColorPairId = (std::rand() + 1) % 7;
}

Space::Space(int x, int y):AGameEntity(x, y)
{
    _isAlive = true;
    _speed = 0.00051;
    _entityModel = '.';
    _entityColorPairId = (std::rand() + 1) % 7;
}

Space::Space(const Space &rhs):AGameEntity(rhs)
{
    _isAlive = true;
    _speed = 0.00051;
    _entityModel = '.';
    _entityColorPairId = (std::rand() + 1) % 7;
}

Space::~Space()
{
	
}

Space &Space::operator=(const Space &rhs)
{
	if (this == &rhs)
		return (*this);
	_x = rhs.getX();
	_y = rhs.getY();
	return (*this);
}