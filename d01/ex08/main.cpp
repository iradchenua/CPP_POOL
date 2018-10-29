#include "Human.hpp"
#define ACT_NUM 3

int main(void)
{
	Human human;

	std::string	action_name[ACT_NUM] = {"meleeAttack", "rangedAttack", "intimidatingShout"};

	for (int i = 0; i < ACT_NUM; i++) {
		human.action(action_name[i], "another human");
	}
	return (0);
}