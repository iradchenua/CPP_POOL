#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"
#include "Enemy.hpp"
#include "SuperMutant.hpp"
#include "RadScorpion.hpp"
#include "Character.hpp"

int main()
{
	Character* zaz = new Character("zaz");
	std::cout << *zaz;
	Enemy* b = new RadScorpion();
	AWeapon* pr = new PlasmaRifle();
	AWeapon* pf = new PowerFist();
	Enemy* a = new SuperMutant();

	zaz->equip(pr);
	std::cout << *zaz;
	zaz->equip(pf);
	zaz->attack(b);
	std::cout << *zaz;
	zaz->equip(pr);
	std::cout << *zaz;
	zaz->attack(b);
	std::cout << *zaz;
	zaz->attack(b);

	std::cout << *zaz;

	std::cout << *a;
	zaz->attack(a);

	std::cout << *a;
	std::cout << *zaz;

	zaz->attack(a);
	zaz->attack(a);
	zaz->attack(a);
	zaz->attack(a);
	zaz->attack(a);
	zaz->attack(a);
	zaz->attack(a);
	zaz->attack(a);
	zaz->attack(a);
	zaz->attack(a);

	std::cout << *a;
	std::cout << *zaz;
	zaz->recoverAP();
	std::cout << *zaz;

	zaz->recoverAP();
	zaz->recoverAP();
	zaz->recoverAP();
	zaz->recoverAP();
	zaz->recoverAP();
	zaz->recoverAP();
	zaz->recoverAP();
	zaz->recoverAP();
	zaz->recoverAP();
	zaz->recoverAP();

	std::cout << *zaz;	
	zaz->attack(a);
	zaz->attack(a);
	zaz->attack(a);
	zaz->attack(a);
	zaz->attack(a);
	zaz->attack(a);
	zaz->attack(a);
	zaz->attack(a);
	zaz->attack(a);
	
	std::cout << *zaz;	
	std::cout << *a;	
	return 0;
}