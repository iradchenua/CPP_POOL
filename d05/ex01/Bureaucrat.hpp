#ifndef BUREAUCRAT_CLASS_HPP
#define BUREAUCRAT_CLASS_HPP
#include <iostream>
#include <string>
#include <stdexcept>


class Form;

class Bureaucrat {
	public:
		Bureaucrat(void);

		Bureaucrat(std::string name, unsigned int grade);
		Bureaucrat(Bureaucrat const & bur);
		~Bureaucrat(void);

		Bureaucrat & operator=(const Bureaucrat & bur);

		void			upGrade(void);
		void			downGrade(void);

		std::string 	getName(void) const;
		unsigned int 	getGrade(void) const;

		void			signForm(Form & form) const;

		class GradeTooHighException: public std::exception {
			public:
				GradeTooHighException(void);

				GradeTooHighException(GradeTooHighException const & e);
				~GradeTooHighException(void) throw();

				GradeTooHighException & operator=(const GradeTooHighException & e);

				virtual const char *what() const throw();
		};

		class GradeTooLowException: public std::exception {
			public:
				GradeTooLowException(void);

				GradeTooLowException(GradeTooLowException const & e);
				~GradeTooLowException(void) throw();

				GradeTooLowException & operator=(const GradeTooLowException & e);

				virtual const char *what() const throw();
		};
		class NoName: public std::exception {
			public:
				NoName(void);

				NoName(NoName const & e);
				~NoName(void) throw();

				NoName & operator=(const NoName & e);

				virtual const char *what() const throw();
		};

		static unsigned int 	getHighGrade(void);
		static unsigned int 	getLowGrade(void);
	private:
		const std::string			_name;
		unsigned int				_grade;
		static const unsigned int 	_highGrade;
		static const unsigned int 	_lowGrade;
};

std::ostream & operator<<(std::ostream & o, Bureaucrat const & bur);

#endif