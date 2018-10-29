#include "Bureaucrat.hpp"

int main(void) {
	try
	{
		Bureaucrat bur1;
		std::cout << bur1;
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat bur1 = Bureaucrat("Anton", 200);
		std::cout << bur1;
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat bur2 = Bureaucrat("Artem", 0);
		std::cout << bur2;
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Bureaucrat bur3 = Bureaucrat("Anna", 145);
		for (int i = 0; i < 10; i++)
		{
			bur3.downGrade();
			std::cout << bur3;
		}
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat bur3 = Bureaucrat("Dima", 10);
		for (int i = 10; i > 0; i--)
		{
			bur3.upGrade();
			std::cout << bur3;
		}
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}