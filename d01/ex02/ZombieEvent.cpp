#include "ZombieEvent.hpp"

void	ZombieEvent::setZombieType(Zombie *zombie, std::string type) {
	zombie->type = type;
}

Zombie *ZombieEvent::newZombie(std::string name) {
	Zombie *zombie;

	zombie = new Zombie();
	zombie->name = name;
	ZombieEvent::setZombieType(zombie, "fat");
	return (zombie);
}

Zombie *ZombieEvent::randomChump(void) {
	Zombie *zombie;

	std::srand(std::time(nullptr));
	zombie = ZombieEvent::newZombie(ZombieEvent::_names[std::rand() % NAME_NUM]);
	ZombieEvent::setZombieType(zombie, ZombieEvent::_types[std::rand() % TYPE_NUM]);
	return (zombie);
}

std::string ZombieEvent::_names[] = {"Frank", "Carl", "Anton", "Artem"};
std::string ZombieEvent::_types[] = {"fat", "good", "bad", "huniest", "wtf"};