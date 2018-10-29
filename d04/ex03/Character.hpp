#include "AMateria.hpp"
#include "ICharacter.hpp"

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

class Character : public ICharacter {
	private:
		int 	_count;
		AMateria *_inventory[4];
		std::string const _name;
		void	_copyInventory(Character const & ch);
		void	_setNullInventory();
	public:
		
		Character();
		Character(std::string const & type);
		Character(Character const & ch);

		~Character();

		Character & operator=(const Character & ch);

		virtual std::string const & getName() const;
		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);
		AMateria *getMateria(int idx) const;
};

#endif