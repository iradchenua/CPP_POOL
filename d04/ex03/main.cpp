#include "AMateria.hpp"
#include "Ice.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"

int main() {
	AMateria *ice = new Ice();

	AMateria *cure = new Cure();
	Character *some = new Character("Artur");

	ICharacter *ch = some;

	//some = ch;

	Character 	*other = new Character("Dima");


	ice->use(*ch);
	ch->equip(ice);
	ch->use(0, *ch);
	ch->unequip(0);
	ch->equip(cure);
	ch->equip(cure);
	ch->equip(ice);
	ch->equip(cure);
	ch->equip(ice);
	ch->equip(ice);
	ch->equip(ice);
	ch->use(0, *ch);
	ch->use(1, *ch);
	*other = *some;
	ch->unequip(2);
	ch->use(2, *ch);
	ch->use(3, *ch);
	ch->use(10, *ch);

	std::cout << other->getName() << std::endl;
	other->use(2, *ch);
	delete other;
	other->use(2, *ch);
	std::cout << "PDF MAIN" << std::endl;

	{
		MateriaSource* bsr = new MateriaSource();
		IMateriaSource* src = bsr;
		MateriaSource* dontKnow = new MateriaSource();

		IMateriaSource* pDontKnow = dontKnow;
		AMateria* tmp;

		tmp = pDontKnow->createMateria("ice");
		if (tmp)
			std::cout << "SOMETHING WAS	" << std::endl;

		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter* zaz = new Character("zaz");
		
		tmp = src->createMateria("ice");
		zaz->equip(tmp);
		tmp = src->createMateria("cure");
		zaz->equip(tmp);
		ICharacter* bob = new Character("bob");

		*dontKnow = *bsr;

		AMateria *other = pDontKnow->createMateria("ice");
		if (other)
			other->use(*bob);

		zaz->use(0, *bob);
		zaz->use(1, *bob);

		delete bob;
		delete zaz;
		delete src;
		return 0;
	}
	return (0);
}