#include "AGameEntity.class.hpp"
#include <iostream>

AGameEntity::AGameEntity()
{
    defaultSetter();
    _x = 0;
    _y = 0;
}

AGameEntity::AGameEntity(int x, int y)
{
    defaultSetter();
    _x = x;
    _y = y;
}

AGameEntity::AGameEntity(AGameEntity const & src)
{
    defaultSetter();
    _x = src._x;
    _y = src._y;
}

AGameEntity &AGameEntity::operator=(const AGameEntity &rhs)
{
    if (this == &rhs)
        return (*this);
    _x = rhs.getX();
    _y = rhs.getY();
    return (*this);
}

AGameEntity::~AGameEntity(){}

void    AGameEntity::move() {
    _y += _speed;
}

void AGameEntity::defaultSetter()
{

    _isAlive = false;
    _speed = 0;
}

float AGameEntity::getX() const
{
    return (_x);
}

float AGameEntity::getY() const
{
    return (_y);
}

bool AGameEntity::getIsAlive() const {
    return (_isAlive);
}

void    AGameEntity::kill() {
    _isAlive = false;
}

void    AGameEntity::live() {
    _isAlive = true;
}

float       AGameEntity::getSpeed() const {
    return (_speed);
}

void       AGameEntity::setSpeed(float speed) {
    _speed = speed;
}

void AGameEntity::setX(float x)
{
    _x = x;
}

void AGameEntity::setY(float y)
{
    _y = y;
}

unsigned int   AGameEntity::getEntityColorPairId() const
{
    return(_entityColorPairId);
}

char           AGameEntity::getEntityModel() const
{
    return(_entityModel);
}