#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void) {
	try
	{
		Form *form = new ShrubberyCreationForm();
		std::cout << *form;
		delete form;
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Form *form = new ShrubberyCreationForm("home");
		std::cout << *form;
		Bureaucrat bur = Bureaucrat("John", 10);
		form->execute(bur);
		delete form;
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Form *form = new ShrubberyCreationForm("home");
		std::cout << *form;
		Bureaucrat bur = Bureaucrat("John", 10);
		bur.signForm(*form);
		std::cout << *form;
		form->execute(bur);
		bur.executeForm(*form);
		delete form;
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Form *form = new ShrubberyCreationForm("home");
		std::cout << *form;
		Bureaucrat bur = Bureaucrat("John", 145);
		bur.signForm(*form);
		std::cout << *form;
		form->execute(bur);
		bur.executeForm(*form);
		delete form;
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Form *form = new PresidentialPardonForm("Devid");
		std::cout << *form;
		Bureaucrat bur = Bureaucrat("John", 145);
		bur.signForm(*form);
		form->execute(bur);
		delete form;
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Form *form = new PresidentialPardonForm("Devid");
		std::cout << *form;
		Bureaucrat bur = Bureaucrat("John", 60);
		bur.signForm(*form);
		std::cout << *form;
		form->execute(bur);
		delete form;
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Form *form = new PresidentialPardonForm("Devid");
		std::cout << *form;
		Bureaucrat bur = Bureaucrat("John", 30);
		bur.signForm(*form);
		std::cout << *form;
		form->execute(bur);
		delete form;
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}


	try
	{
		Form *form = new PresidentialPardonForm("Devid");
		std::cout << *form;
		Bureaucrat bur = Bureaucrat("John", 145);
		bur.signForm(*form);
		form->execute(bur);
		delete form;
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Form *form = new PresidentialPardonForm("Devid");
		std::cout << *form;
		Bureaucrat bur = Bureaucrat("John", 21);
		bur.signForm(*form);
		std::cout << *form;
		form->execute(bur);
		bur.executeForm(*form);
		delete form;
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Form *form = new PresidentialPardonForm("Devid");
		std::cout << *form;
		Bureaucrat bur = Bureaucrat("John", 2);
		bur.signForm(*form);
		std::cout << *form;
		form->execute(bur);
		bur.executeForm(*form);
		delete form;
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}