#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : _materias(NULL), _num(0) {

}

void MateriaSource::_expandMaterias(AMateria *newMat) {
	this->_num++;
	AMateria **newMaterias = new AMateria*[this->_num];

	for (int i = 0; i < this->_num - 1; i++)
		newMaterias[i] = this->_materias[i];
	if (this->_materias)
		delete [] this->_materias;
	this->_materias = newMaterias;
	this->_materias[this->_num - 1]  = newMat->clone();
}

int MateriaSource::_findMateria(std::string const & type, int *index) const {
	if (!this->_materias)
		return (0);
	for (int i = 0; i < this->_num; i++) {
		if (this->_materias[i]->getType() == type) {
			if (index)
				*index = i;
			return (1);	
		}
	}
	return (0);
}

void MateriaSource::learnMateria(AMateria *newMat) {
	if (!this->_findMateria(newMat->getType(), NULL))
		this->_expandMaterias(newMat);
}

AMateria * MateriaSource::createMateria(std::string const & type) {
	int index;

	if (this->_findMateria(type, &index))
		return (this->_materias[index]->clone());
	return (NULL);
}

MateriaSource::MateriaSource(MateriaSource const & mat) {
	this->_num = 0;
	*this = mat;
}


void MateriaSource::_deleteMaterias() {
	if (this->_materias) {
		for(int i = 0; i < this->_num; i++)
			delete this->_materias[i];
		delete [] this->_materias;
		this->_materias = NULL;
		this->_num = 0;
	}
}

int MateriaSource::getNum() const {
	return (this->_num);
}

AMateria *MateriaSource::getMatFromArhcive(int index) const {
	if (index >= 0 && index < this->_num)
		return (this->_materias[index]->clone());
	return (NULL);
}

MateriaSource & MateriaSource::operator=(const MateriaSource & mat) {
	int num = mat.getNum();

	this->_deleteMaterias();
	this->_materias = new AMateria*[num]; 

	for (int i = 0; i < num ; i ++) {
		this->_materias[i] = mat.getMatFromArhcive(i);
	}
	this->_num = num;
	return (*this);
}

MateriaSource::~MateriaSource() {
	this->_deleteMaterias();
}

