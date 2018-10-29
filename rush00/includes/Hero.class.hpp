#ifndef HERO_CLASS_HPP
#define HERO_CLASS_HPP

#include "AGameEntity.class.hpp"
#include "Blust.class.hpp"

class Hero:public AGameEntity
{
public:
	Hero();
	Hero(int x, int y);
	Hero(const Hero &rhs);
	~Hero();
	Hero &operator=(const Hero &rhs);
	
	void 	releaseKeys();
	void	checkKey(int key);

	int 	getShoot() const;
    virtual void move();
private:
	bool _moveLeft;
	bool _moveRight;
	bool _moveUp;
	bool _moveDown;
	bool _shoot;
};

#endif