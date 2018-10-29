#include "ZombieEvent.hpp"

int main(void) {
	Zombie Mark;
	Zombie Carl;
	Zombie *Anna;
	Zombie *random;

	Anna = ZombieEvent::newZombie("Anna");
	Anna->announce();
	random = ZombieEvent::randomChump();
	Mark.name = "Mark";
	Carl.name = "Carl";
	ZombieEvent::setZombieType(&Mark, "fat");
	ZombieEvent::setZombieType(&Carl, "wtf");
	ZombieEvent::setZombieType(Anna, "huniest");
	random->announce();
	delete random;
	Anna->announce();
	delete Anna;
	Mark.announce();
	Carl.announce();
	return (0);
}