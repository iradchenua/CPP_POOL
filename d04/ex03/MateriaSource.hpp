#include "IMateriaSource.hpp"

#ifndef MATERIA_SOURCE_HPP
#define MATERIA_SOURCE_HPP

class MateriaSource : public IMateriaSource {
	private:
		AMateria **_materias;
		int _num;
		void _expandMaterias(AMateria *newMat);
		int _findMateria(std::string const & type, int *index) const;
		void _deleteMaterias();
	public:
		
		MateriaSource();
		MateriaSource(MateriaSource const & mat);

		~MateriaSource();

		MateriaSource & operator=(const MateriaSource & mat);

		int getNum() const;
		AMateria *getMatFromArhcive(int index) const;
		virtual void learnMateria(AMateria *);
		virtual AMateria * createMateria(std::string const & type);
};

#endif