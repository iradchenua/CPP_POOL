#include "Squad.hpp"

Squad::Squad() : _count(0), _marines(NULL) {

}

void Squad::_deleteMarines() {
	if (this->_marines) {
		for(int i = 0; i < this->_count; i++) {
			delete this->_marines[i];
		}
		delete [] this->_marines;
	}
}

int Squad::_searchMarine(ISpaceMarine *marine) {
	for (int i = 0; i < this->_count; i++) {
		if (marine == this->_marines[i])
			return (1);
	}
	return (0);
}

Squad::~Squad() {
	this->_deleteMarines();
}

Squad::Squad(Squad const & squad) : _count(0), _marines(NULL) {
	*this = squad;
}

Squad & Squad::operator=(Squad const & squad) {
	this->_deleteMarines();
	for (int i = 0; i < squad.getCount(); i++) {
		this->push(squad.getUnit(i)->clone());
	}
	return (*this);
}

int Squad::push(ISpaceMarine *marine) {
	ISpaceMarine **newMarines;

	if (marine && !this->_searchMarine(marine)) {
		this->_count++;
		newMarines = new ISpaceMarine*[this->_count];
		for (int i = 0; i < this->_count - 1; i++)
			newMarines[i] = this->_marines[i];
		if (this->_marines)
			delete [] this->_marines;
		this->_marines = newMarines;
		this->_marines[this->_count - 1] = marine;
	}
	return (this->_count);
};

ISpaceMarine *Squad::getUnit(int unitNum) const {
	if (unitNum >= 0 && unitNum <= this->_count)
		return (this->_marines[unitNum]);
	return (NULL);
};

int Squad::getCount() const {
	return (this->_count);
}
