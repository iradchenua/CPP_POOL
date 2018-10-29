#include "TacticalMarine.hpp"

TacticalMarine::TacticalMarine() {
	std::cout << "Tactical Marine ready for battle" << std::endl;
}

TacticalMarine::TacticalMarine(TacticalMarine const & TacticalMarine) {
	std::cout << "Tactical Marine ready for battle" << std::endl;
	*this = TacticalMarine;
}

TacticalMarine & TacticalMarine::operator=(const TacticalMarine & marine) {
	(void)marine;
	return (*this);
}

ISpaceMarine *TacticalMarine::clone() const {
	TacticalMarine *newMarine = new TacticalMarine(*this);
	return (newMarine);
}

TacticalMarine::~TacticalMarine() {
	std::cout << "Aaargh ..." << std::endl;
}

void	TacticalMarine::battleCry() const {
	std::cout << "For the holy PLOT !" << std::endl;
}

void	TacticalMarine::rangedAttack() const {
	std::cout << "* attacks with bolter *" << std::endl;
}

void	TacticalMarine::meleeAttack() const {
	std::cout << "* attacks with chainsword *" << std::endl;
}