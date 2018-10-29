#include <string>
#include <iostream>

#ifndef ENEMY_HPP
#define ENEMY_HPP

class Enemy {
	protected:
		void	_setHp(int newHp);
	private:
		int _hp;
		std::string const _type;
	public:
		Enemy();
		Enemy(int hp, std::string const & type);
		Enemy(Enemy const & en);

		virtual ~Enemy();

		Enemy & operator=(const Enemy & en);

		std::string getType() const;
		int getHp() const;

		virtual void takeDamage(int damage);
};

std::ostream & operator<<(std::ostream & o, Enemy const & en);

#endif