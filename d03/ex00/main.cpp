#include "FragTrap.hpp"

int main(void) {
	FragTrap frag1;
	FragTrap frag2 = FragTrap("frag2");
	FragTrap frag3 = FragTrap("frag3");
	FragTrap frag4 = FragTrap("frag4");

	std::cout << frag1;
	frag1.meleeAttack("human");
	frag1.rangedAttack("human");
	frag2.meleeAttack("dog");
	frag2.rangedAttack("dog");
	std::cout << frag4;
	frag4 = FragTrap(frag3);
	std::cout << frag4;
	std::cout << frag3;
	std::cout << (frag3 = frag2);
	frag4.takeDamage(20);
	frag4.takeDamage(98);
	frag4.beRepaired(100);
	frag4.beRepaired(200);
	frag4.vaulthunter_dot_exe("human");
	frag4.vaulthunter_dot_exe("human");
	return (0);
}