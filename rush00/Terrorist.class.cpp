#include "AGameEntity.class.hpp"
#include "Terrorist.class.hpp"

Terrorist::Terrorist():AGameEntity()
{
    _speed = 0.001;
    _entityModel = 'V';
    _entityColorPairId = COLOR_RED;
}

Terrorist::Terrorist(int x, int y):AGameEntity(x, y)
{
    _speed = 0.001;
    _entityModel = 'V';
    _entityColorPairId = COLOR_RED;
}

Terrorist::Terrorist(const Terrorist &rhs):AGameEntity(rhs)
{
    _speed = 0.001;
    _entityModel = 'V';
    _entityColorPairId = COLOR_RED;
}
Terrorist::~Terrorist()
{
}

Terrorist &Terrorist::operator=(const Terrorist &rhs)
{
	if (this == &rhs)
		return (*this);
	_x = rhs.getX();
	_y = rhs.getY();
	return (*this);
}