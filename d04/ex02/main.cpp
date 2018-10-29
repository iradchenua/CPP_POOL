#include "Squad.hpp"
#include "TacticalMarine.hpp"
#include "AssaultTerminator.hpp"
int main() {
	{
		Squad 	*ssq = new Squad;
		ISquad *sq = ssq;
		ISpaceMarine *marine = new TacticalMarine;
		ISpaceMarine *newMarine = marine->clone();

		std::cout << sq->getCount() << std::endl;
		newMarine->battleCry();
		newMarine->rangedAttack();
		newMarine->meleeAttack();
		std::cout << sq->push(marine) << std::endl;
		sq->getUnit(0)->rangedAttack();
		std::cout << sq->push(newMarine) << std::endl;
		std::cout << sq->getCount() << std::endl;
		sq->getUnit(1)->meleeAttack();
		sq->getUnit(0)->meleeAttack();
		sq->push(marine);
		sq->push(marine);
		sq->push(marine);

		std::cout << "FROM PUSH " << sq->push(marine) << std::endl;
		std::cout << "FROM GET COUNT " << sq->push(marine) << std::endl;

		Squad *newSq = new Squad(*ssq);

		delete sq;
		newSq->getUnit(0)->rangedAttack();
		newSq->getUnit(1)->meleeAttack();
		delete newSq;
	}
	std::cout << "MAIN FROM PDF" << std::endl;
	{
		ISpaceMarine* bob = new TacticalMarine;
		ISpaceMarine* jim = new AssaultTerminator;
		ISquad* vlc = new Squad;
		vlc->push(bob);
		vlc->push(jim);
		for (int i = 0; i < vlc->getCount(); ++i)
		{
			ISpaceMarine* cur = vlc->getUnit(i);
			cur->battleCry();
			cur->rangedAttack();
			cur->meleeAttack();
		}
		delete vlc;
	}

	return (0);
}