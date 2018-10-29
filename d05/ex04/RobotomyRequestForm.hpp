#ifndef ROBOTOMY_REQUEST_FORM_CLASS_HPP
#define ROBOTOMY_REQUEST_FORM_CLASS_HPP

#include "Form.hpp"
#include <ctime>

class RobotomyRequestForm : public Form {
	public:
		RobotomyRequestForm(void);

		RobotomyRequestForm(std::string const & target);
		RobotomyRequestForm(std::string name, unsigned int signGrade, unsigned int execGrade);
		RobotomyRequestForm(RobotomyRequestForm const & form);
		~RobotomyRequestForm(void);

		RobotomyRequestForm & operator=(const RobotomyRequestForm & form);

		virtual void execute(Bureaucrat const & executor) const;

};

#endif