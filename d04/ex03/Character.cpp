#include "Character.hpp"

void Character::_setNullInventory() {
	this->_count = 0;
	for(int i = 0; i < 4; i++) {
		if (this->_inventory[i]) {
			this->_inventory[i] = NULL;
		}
	}
}

void Character::_copyInventory(Character const & ch) {
	AMateria *m;

	for(int i = 0; i < 4; i++) {
		m = ch.getMateria(i);
		if (m) {
			this->_inventory[i] = m->clone();
		}
	}
}

Character::Character(std::string const & name) : _name(name) {
	this->_setNullInventory();
}

Character::Character() : _name("no name") {
	this->_setNullInventory();
}

Character::Character(Character const & ch) : _name(ch.getName()) {
	this->_setNullInventory();
	*this = ch;
}

Character & Character::operator=(const Character & ch) {
	this->_copyInventory(ch);
	return (*this);
}

Character::~Character() {
	this->_count = 0;
	for(int i = 0; i < 4; i++) {
		if (this->_inventory[i]) {
			delete this->_inventory[i];
		}
	}
}

AMateria *Character::getMateria(int idx) const {
	if (idx < 4 && idx >= 0)
		return (this->_inventory[idx]);
	return (NULL);
}

std::string const &	Character::getName() const {
	return (this->_name);
}

void Character::equip(AMateria *m) {
	if (this->_count < 3 && m) {
		int idx = 0;
		while (this->getMateria(idx))
			idx++;
		this->_inventory[idx] = m;
		this->_count++;
	}
}

void Character::unequip(int idx) {
	AMateria *m = this->getMateria(idx);
	if (!m)
		return ;
	this->_inventory[idx] = NULL;
	this->_count--;
}

void Character::use(int idx, ICharacter & target) {
	AMateria *m = this->getMateria(idx);
	if (m)
		m->use(target);
}