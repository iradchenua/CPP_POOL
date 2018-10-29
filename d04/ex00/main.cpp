#include "Sorcerer.hpp"
#include "Peon.hpp"

int main(void) {
	Sorcerer Andrew("Andrew", "Zaretsky");
	Victim 	Alfred("Alfred");
	Peon 	Geka("Geka");

	std::cout << Andrew;
	Andrew.polymorph(Alfred);
	Andrew.polymorph(Geka);
	std::cout << Alfred;

	Sorcerer robert("Robert", "the Magnificent");
	Victim jim("Jimmy");
	Peon joe("Joe");
	std::cout << robert << jim << joe;
	robert.polymorph(jim);
	robert.polymorph(joe);
	return (0);
}