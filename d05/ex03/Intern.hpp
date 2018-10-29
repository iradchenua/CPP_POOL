#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern  {
	public:
		Intern(void);

		Intern(Intern const & intern);
		~Intern(void);

		Intern & operator=(const Intern & intern);

		Form *makeForm(std::string const & name, std::string const & target);
		typedef Form* (Intern::*InternCreate)(std::string const &);

		class NoForm: public std::exception {
			public:
				NoForm(void);

				NoForm(NoForm const & e);
				~NoForm(void) throw();

				NoForm & operator=(const NoForm & e);

				virtual const char *what() const throw();
		};

	private:
    	Form*                        _newPresidentialPardonForm(std::string const & target);
    	Form*                        _newRobotomyRequestForm(std::string const & target);
		Form* 						 _newShrubberyCreationForm(std::string const & target);

		static const std::string _knownForms[3];
		static const InternCreate _functions[3];
};