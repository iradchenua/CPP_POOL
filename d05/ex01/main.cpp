#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void) {
	try
	{
		Form form = Form();
		std::cout << form;
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Form form = Form("Form", 100, 100);
		std::cout << form;
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Form form = Form("Artem", 160, 0);
		std::cout << form;
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Form form = Form("Anna", 120, 0);
		
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Form form = Form("Anna", 200, 0);
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Form form = Form("Anna", 50, 50);
		Bureaucrat bur = Bureaucrat("Artem", 70	);
		form.beSigned(bur);
		std::cout << form;
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Form form = Form("Form", 50, 50);
		Bureaucrat bur = Bureaucrat("Artem", 20);
		form.beSigned(bur);
		std::cout << form;
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Form form = Form("Form", 50, 50);
		Bureaucrat bur = Bureaucrat("Artem", 20);
		std::cout << form;
		std::cout << bur;
		bur.signForm(form);
		std::cout << form;
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Form form = Form("Form", 50, 50);
		Bureaucrat bur = Bureaucrat("Artem", 100);
		bur.signForm(form);
		std::cout << form;
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}