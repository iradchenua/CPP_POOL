#ifndef FORM_CLASS_HPP
#define FORM_CLASS_HPP

#include "Bureaucrat.hpp"

class Form {
	public:
		Form(void);

		Form(std::string name, unsigned int signGrade, unsigned int execGrade);
		Form(Form const & bur);
		virtual ~Form(void) = 0;

		Form & operator=(const Form & bur);

		void			beSigned(const Bureaucrat & bur);	
		bool 			getIsSign(void) const;
		std::string 	getName(void) const;
		unsigned int 	getSignGrade(void) const;
		unsigned int 	getExecGrade(void) const;

		void			setTarget(std::string const & target);
		std::string 	getTarget(void) const;
		
		virtual 		void execute(Bureaucrat const & executor) const;

		class GradeTooHighException : public Bureaucrat::GradeTooHighException {
			public:
				GradeTooHighException(void);

				GradeTooHighException(std::string name, unsigned int grade);
				GradeTooHighException(GradeTooHighException const & e);
				~GradeTooHighException(void) throw();

				GradeTooHighException & operator=(const GradeTooHighException & e);
		};
		class GradeTooLowException : public Bureaucrat::GradeTooLowException {
			public:
				GradeTooLowException(void);

				GradeTooLowException(std::string name, unsigned int grade);
				GradeTooLowException(GradeTooLowException const & e);
				~GradeTooLowException(void) throw();

				GradeTooLowException & operator=(const GradeTooLowException & e);
		};
		class NoSign : public std::exception {
			public:
				NoSign(void);

				NoSign(NoSign const & e);
				~NoSign(void) throw();

				NoSign & operator=(const NoSign & e);
				virtual const char *what() const throw();

		};
		class NoName : public Bureaucrat::NoName {
			public:
				NoName(void);

				NoName(NoName const & e);
				~NoName(void) throw();

				NoName & operator=(const NoName & e);
				virtual const char *what() const throw();
		};
		class NoTarget : public std::exception {
			public:
				NoTarget(void);

				NoTarget(NoTarget const & e);
				~NoTarget(void) throw();

				NoTarget & operator=(const NoTarget & e);
				virtual const char *what() const throw();
		};
	private:
		const std::string 	_name;
		bool 				_isSign;
		std::string 		_target;
		unsigned int 	_signGrade;
		unsigned int 	_execGrade;
};

std::ostream & operator<<(std::ostream & o, const Form & form);

#endif