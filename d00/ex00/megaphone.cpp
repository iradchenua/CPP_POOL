#include <iostream>

void	show_upper_word(char *word)
{
	while (*word)
	{
		std::cout << (char)std::toupper(*word);
		word++;
	}
}

int		main(int ac, char **av) {
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for (int i = 1; i < ac; i++)
		{
			if (i != 1)
				std::cout << " ";
			show_upper_word(av[i]);
		}
	}
	std::cout << std::endl;
	return (0);
}