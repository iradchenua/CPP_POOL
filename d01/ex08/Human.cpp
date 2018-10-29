#include "Human.hpp"
#define ACT_NUM 3

typedef struct 	s_action
{
	std::string name;	
	void	(Human::*action)(std::string const &);
}				t_action;

void	Human::meleeAttack(std::string const & target) {
	std::cout << "Atack " << target << " in meleerange" << std::endl;
}

void	Human::rangedAttack(std::string const & target) {
	std::cout << "Atack " << target << " in range" << std::endl;
}

void	Human::intimidatingShout(std::string const & target) {
	std::cout << "Piu Piu " << target << std::endl;
}

void	Human::action(std::string const & action_name, std::string const & target) {
	t_action actions[3] = {{"meleeAttack", &Human::meleeAttack}, {"rangedAttack", \
	&Human::rangedAttack}, {"intimidatingShout", &Human::intimidatingShout}};

	for(int i = 0; i < ACT_NUM; i++)
	{
		if (actions[i].name == action_name)
		{
			(this->*actions[i].action)(target);
		}
	}
}