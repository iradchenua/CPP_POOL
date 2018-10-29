#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(int N)
{
	int i;

	i = 0;
	Zombie 	*zombies = new Zombie[N];
	this->_N = N;
	this->_zombies = zombies;
	std::srand(std::time(nullptr));
	while (i < this->_N)
	{
		zombies[i].name = ZombieHorde::_names[std::rand() % NAME_NUM];
		zombies[i].type = ZombieHorde::_types[std::rand() % TYPE_NUM];
		i++;
	}
}

void	ZombieHorde::announce(void) {
	int i;

	i = 0;
	while (i < this->_N)
	{
		this->_zombies[i].announce();
		i++;
	}
}

ZombieHorde::~ZombieHorde()
{
	delete [] this->_zombies;
}

std::string ZombieHorde::_names[] = {"Frank", "Carl", "Anton", "Artem"};
std::string ZombieHorde::_types[] = {"fat", "good", "bad", "huniest", "wtf"};