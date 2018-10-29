#include <iostream>
#include "Contact.class.hpp"

void	Contact::addContact(void)
{
	for (int i = 0; i < F_NUM; i++)
	{
		std::cout << Contact::fieldsName[i] << ": ";
		std::getline(std::cin, this->fields[i]);
	}
	Contact::setCNb(Contact::getCNb() + 1);
}

void	Contact::showContact(void)
{
	for (int i = 0; i < F_NUM; i++)
	{
		std::cout << Contact::fieldsName[i] << ": ";
		std::cout << this->fields[i] << std::endl;
	}
}

void 	Contact::setCNb(int cNb){
	Contact::_cNb = cNb;
}

int 	Contact::getCNb(void){
	return (Contact::_cNb);
}

std::string Contact::fieldsName[F_NUM] = {"first name", "last name", "nickname", "login",
						"postal address", "email address", "phone number",
						"birthday date", "date", "favorite meal", "underwear color",
						"darkest secret"};
int Contact::_cNb = 0;