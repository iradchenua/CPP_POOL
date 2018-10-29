#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"

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

	ScavTrap scav1;
	ScavTrap scav2 = ScavTrap("scav2");
	ScavTrap scav3 = ScavTrap("scav3");
	ScavTrap scav4 = ScavTrap("scav4");

	std::cout << frag1;
	scav1.meleeAttack("human");
	scav1.rangedAttack("human");
	scav2.meleeAttack("dog");
	scav2.rangedAttack("dog");
	std::cout << scav4;
	scav4 = ScavTrap(scav3);
	std::cout << scav4;
	std::cout << scav3;
	std::cout << (scav3 = scav2);
	scav4.takeDamage(20);
	scav4.takeDamage(98);
	scav4.beRepaired(100);
	scav4.beRepaired(200);
	scav4.challengeNewcomer();
	scav4.challengeNewcomer();
	scav1.challengeNewcomer();

	NinjaTrap ninja1;
	NinjaTrap ninja2 = NinjaTrap("ninja2");
	NinjaTrap ninja3 = NinjaTrap("ninja3");
	NinjaTrap ninja4 = NinjaTrap("ninja4");

	std::cout << frag1;
	ninja1.meleeAttack("human");
	ninja1.rangedAttack("human");
	ninja2.meleeAttack("dog");
	ninja2.rangedAttack("dog");
	std::cout << ninja4;
	ninja4 = NinjaTrap(ninja3);
	std::cout << ninja4;
	std::cout << ninja3;
	std::cout << (ninja3 = ninja2);
	ninja4.takeDamage(20);
	ninja4.takeDamage(98);
	ninja4.beRepaired(100);
	ninja4.beRepaired(200);
	ninja4.ninjaShoebox(ninja4);
	ninja4.ninjaShoebox(scav4);
	ninja1.ninjaShoebox(frag4);
	return (0);
}