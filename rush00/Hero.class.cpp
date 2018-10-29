#include "AGameEntity.class.hpp"
#include "Hero.class.hpp"

Hero::Hero():AGameEntity()
{

    _isAlive = true;
    _speed = 1;
    _entityModel = 'A';
    _entityColorPairId = COLOR_GREEN;
    _moveLeft = 0;
    _moveRight = 0;
    _moveUp = 0;
    _moveDown = 0;
    _shoot = 0;

}

Hero::Hero(int x, int y):AGameEntity(x, y)
{
    _isAlive = true;
    _speed = 1;
    _entityModel = 'A';
    _entityColorPairId = COLOR_GREEN;
    _moveLeft = 0;
    _moveRight = 0;
    _moveUp = 0;
    _moveDown = 0;
    _shoot = 0;
}

Hero::Hero(const Hero &rhs):AGameEntity(rhs)
{
    _isAlive = true;
    _speed = 1;
    _entityModel = 'A';
    _entityColorPairId = COLOR_GREEN;
    _moveLeft = 0;
    _moveRight = 0;
    _moveUp = 0;
    _moveDown = 0;
    _shoot = 0;
}

void Hero::releaseKeys() {
    _moveRight = 0;
    _moveLeft = 0;
    _moveUp = 0;
    _moveDown = 0;
    _shoot = 0;
}

int     Hero::getShoot() const {
    return (_shoot);
}

void Hero::checkKey(int key) {
    if (key == KEY_RIGHT)
        _moveRight = 1;
    if (key == KEY_LEFT)
        _moveLeft = 1;
    if (key == KEY_UP)
        _moveUp = 1;
    if (key == KEY_DOWN)
        _moveDown = 1;
    if (key == ' ')
        _shoot = 1;
}

Hero::~Hero()
{
	
}

void Hero::move()
{
    if (_moveRight)
        _x += _speed;
    if (_moveLeft)
        _x -= _speed;
    if (_moveUp)
        _y -= _speed;
    if (_moveDown)
        _y += _speed;
}

Hero &Hero::operator=(const Hero &rhs)
{
	if (this == &rhs)
		return (*this);
	_x = rhs.getX();
	_y = rhs.getY();
	return (*this);
}