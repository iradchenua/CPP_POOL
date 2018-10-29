#include "OfficeBlock.hpp"

int main()
{
	{
		Intern idiotOne;
		Bureaucrat hermes = Bureaucrat("Hermes Conrad", 37);
		Bureaucrat bob = Bureaucrat("Bobby Bobson", 123);
		OfficeBlock ob;
		ob.setIntern(idiotOne);
		ob.setSigner(bob);
		ob.setExecutor(hermes);
		try
		{
			ob.doBureaucracy("mutant pig termination", "Pigley");
		}
		catch (OfficeBlock::BadConstructor & e){
			std::cout << e.what() << std::endl;
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	{
		Intern idiotOne;
		Bureaucrat hermes = Bureaucrat("Hermes Conrad", 37);
		Bureaucrat bob = Bureaucrat("Bobby Bobson", 123);
		OfficeBlock ob;
		ob.setIntern(idiotOne);
		ob.setSigner(bob);
		ob.setExecutor(hermes);
		try
		{
			ob.doBureaucracy("shrubbery creation", "Pigley");
		}
		catch (OfficeBlock::BadConstructor & e){
			std::cout << e.what() << std::endl;
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	{
		Intern idiotOne;
		Bureaucrat hermes = Bureaucrat("Hermes Conrad", 37);
		Bureaucrat bob = Bureaucrat("Bobby Bobson", 25);
		OfficeBlock ob;
		ob.setIntern(idiotOne);
		ob.setSigner(bob);
		ob.setExecutor(hermes);
		try
		{
			ob.doBureaucracy("presidential pardon", "Pigley");
		}
		catch (OfficeBlock::BadConstructor & e){
			std::cout << e.what() << std::endl;
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	{
		Intern idiotOne;
		Bureaucrat hermes = Bureaucrat("Hermes Conrad", 5);
		Bureaucrat bob = Bureaucrat("Bobby Bobson", 50);
		OfficeBlock ob;
		ob.setIntern(idiotOne);
		ob.setSigner(bob);
		ob.setExecutor(hermes);
		try
		{
			ob.doBureaucracy("robotomy request", "Pigley");
		}
		catch (OfficeBlock::BadConstructor & e){
			std::cout << e.what() << std::endl;
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}

	}

	{
		Intern idiotOne;
		Bureaucrat hermes = Bureaucrat("Hermes Conrad", 5);
		Bureaucrat bob = Bureaucrat("Bobby Bobson", 74);
		OfficeBlock ob;
		ob.setIntern(idiotOne);
		ob.setSigner(bob);
		ob.setExecutor(hermes);
		try
		{
			ob.doBureaucracy("robotomy request", "Pigley");
		}
		catch (OfficeBlock::BadConstructor & e){
			std::cout << e.what() << std::endl;
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}

	}

	{
		Intern idiotOne;
		Bureaucrat hermes = Bureaucrat("Hermes Conrad", 5);
		Bureaucrat bob = Bureaucrat("Bobby Bobson", 74);
		OfficeBlock ob;
		ob.setSigner(bob);
		ob.setExecutor(hermes);
		try
		{
			ob.doBureaucracy("robotomy request", "Pigley");
		}
		catch (OfficeBlock::BadConstructor & e){
			std::cout << e.what() << std::endl;
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}

	}

	{
		Intern idiotOne;
		Bureaucrat hermes = Bureaucrat("Hermes Conrad", 5);
		Bureaucrat bob = Bureaucrat("Bobby Bobson", 74);
		OfficeBlock ob(idiotOne, bob, hermes);
		try
		{
			ob.doBureaucracy("robotomy request", "Pigley");
		}
		catch (OfficeBlock::BadConstructor & e){
			std::cout << e.what() << std::endl;
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}

	}
	{
		Intern idiotOne;
		Bureaucrat hermes = Bureaucrat("Hermes Conrad", 5);
		Bureaucrat bob = Bureaucrat("Bobby Bobson", 74);
		OfficeBlock ob(idiotOne, bob, hermes);

		try
		{
			OfficeBlock od = ob;
			ob.doBureaucracy("robotomy request", "Pigley");
		}

		catch (OfficeBlock::BadConstructor & e){
			std::cout << e.what() << std::endl;
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}

	}
	{
		Intern idiotOne;
		Bureaucrat hermes = Bureaucrat("Hermes Conrad", 5);
		Bureaucrat bob = Bureaucrat("Bobby Bobson", 74);
		OfficeBlock ob(idiotOne, bob, hermes);

		try
		{
			OfficeBlock od = OfficeBlock(ob);
			ob.doBureaucracy("robotomy request", "Pigley");
		}

		catch (OfficeBlock::BadConstructor & e){
			std::cout << e.what() << std::endl;
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}

	}

	return (0);
}