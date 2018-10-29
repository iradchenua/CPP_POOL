#include <iostream>
#include <iomanip>
#include "Contact.class.hpp"
#define C_NUM 8
#define BUFF_S 512

void	showContacts(Contact phoneBook[C_NUM]) {

	int i;
	int j;
	int cNb;

	cNb = Contact::getCNb();
	i = 0;
	for (i = 0; i < cNb; i++)
	{
		std::cout << std::setfill(' ') << std::setw(10);
		std::cout << std::to_string(i + 1) << "|";
		for (j = 0; j < 3; j++)
		{
			std::cout << std::setfill(' ') << std::setw(9);
			if (phoneBook[i].fields[j].length() > 10)
			{
				std::cout << phoneBook[i].fields[j].substr(0, 9);
				std::cout << ".";
			}
			else
				std::cout << phoneBook[i].fields[j];
			if (j != 2)
				 std::cout << "|";
		}
		std::cout << std::endl;
	}
}

void	findContact(Contact phoneBook[C_NUM], std::string s_ind)
{
	int ind;

	ind = std::atoi(s_ind.c_str());
	if (ind >= 9 || ind <= 0 || ind > Contact::getCNb())
		std::cout << "No contact with this index" << std::endl;
	else
		phoneBook[ind - 1].showContact();
}

void	hello(void)
{
	std::cout << "Welcome to phoneBook30000 the future is now." << std::endl;
	std::cout << "Try to prompt: ADD, SEARCH, EXIT." << std::endl;
	std::cout << "We think our interface is the best in the world, so you will not have problem with it." << std::endl;
	std::cout << "Good Luck, and remember BIG BROTHER is watching you!" << std::endl;
}

int		main(void) {
	char	buff[BUFF_S];
	std::string ind;
	Contact phoneBook[C_NUM];

	hello();
	while (1)
	{
		std::cin.getline(buff, BUFF_S);
		if (!std::strcmp(buff, "ADD") && Contact::getCNb() < C_NUM)
			phoneBook[Contact::getCNb()].addContact();
		else if (!std::strcmp(buff, "SEARCH"))
		{
			if (Contact::getCNb() == 0)
				continue;
			showContacts(phoneBook);
			std::getline(std::cin, ind);
			findContact(phoneBook, ind);
		}
		else if (Contact::getCNb() >= C_NUM)
			std::cout << "Phone Book is overload." << std::endl;
		else if (!std::strcmp(buff, "EXIT"))
		{
			std::cout << "Thank for using our service, be careful Ostazia's agent everywhere." << std::endl;
			break;
		}
		else
			std::cout << "Bad input only: ADD, EXIT, SEARCH" << std::endl;
	}

	return (0);
}