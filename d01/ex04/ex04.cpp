#include <iostream>

int		main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *p_str;
	std::string &r_str = str;

	p_str = &str;
	std::cout << *p_str << std::endl;
	std::cout << r_str << std::endl;
}