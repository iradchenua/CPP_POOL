#include "AWeapon.hpp"
#include "Enemy.hpp"

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

class Character {
	private:
		std::string const _name;
		int _AP;
		AWeapon *_weapon;
		void	_setAP(int ap);
	public:
		Character(std::string const & name);

		Character();
		Character(Character const & ch);

		~Character();

		void recoverAP();
		void equip(AWeapon *);
		void attack(Enemy *);
		
		Character & operator=(const Character & ch);

		std::string getName() const;
		int getAP() const;
		AWeapon *getWeapon() const;
};


std::ostream & operator<<(std::ostream & o, Character const & ch);

#endif