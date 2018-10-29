#include "Enemy.hpp"

Enemy::Enemy() : _hp(0), _type("undefined") {

}

Enemy::~Enemy() {
	return ;
}

Enemy::Enemy(int hp, std::string const & type) : \
						 _hp(hp), _type(type) {

}

Enemy::Enemy(Enemy const & en)  : _hp(en.getHp()), _type(en.getType())  {

}

Enemy & Enemy::operator=(const Enemy & en) {
	this->_setHp(en.getHp());
	return (*this);
}

std::string Enemy::getType() const {
	return (this->_type);
}

int Enemy::getHp() const {
	return (this->_hp);
}

void Enemy::_setHp(int newHp) {
	if (newHp <= 0)
		this->_hp = 0;
	else
		this->_hp = newHp;
}
void Enemy::takeDamage(int damage) {
	if (damage <= 0)
		return ;
	this->_setHp(this->_hp - damage);
}

std::ostream & operator<<(std::ostream & o, Enemy const & en) {
	o << "Enemy type is " \
	<< en.getType() \
	<< " has hp " \
	<< en.getHp() \
	<< std::endl;

	return (o);
}