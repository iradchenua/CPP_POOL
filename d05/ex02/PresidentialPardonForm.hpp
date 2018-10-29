#ifndef PRESIDENTIAL_PARDON_FORM_CLASS_HPP
#define PRESIDENTIAL_PARDON_FORM_CLASS_HPP

#include "Form.hpp"


class PresidentialPardonForm : public Form {
	public:
		PresidentialPardonForm(void);

		PresidentialPardonForm(std::string const & target);
		PresidentialPardonForm(std::string name, unsigned int signGrade, unsigned int execGrade);
		PresidentialPardonForm(PresidentialPardonForm const & form);
		~PresidentialPardonForm(void);

		PresidentialPardonForm & operator=(const PresidentialPardonForm & form);

		virtual void execute(Bureaucrat const & executor) const;

};

#endif