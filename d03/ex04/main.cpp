#include "SuperTrap.hpp"

int main(void) {
	
	SuperTrap super("SUPER");
	SuperTrap another("ANOTHER SUPER");
	SuperTrap copyAnother(another);
	std::cout << super;
	super.meleeAttack("me");
	super.rangedAttack("me");
	super.vaulthunter_dot_exe("special_me");
	super.ninjaShoebox(super);
	FragTrap frag("Frag");
	std::cout << frag;
	frag.rangedAttack("me");
	NinjaTrap ninja("Ninja");
	ninja.meleeAttack("ninja");
	std::cout << ninja;
	return (0);
}