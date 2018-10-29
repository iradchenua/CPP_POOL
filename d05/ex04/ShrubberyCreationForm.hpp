#ifndef SHRUBERRY_CREATION_CLASS_HPP
#define SHRUBERRY_CREATION_CLASS_HPP

#include <iostream>
#include <fstream>
#include "Form.hpp"

class ShrubberyCreationForm : public Form {
	public:
		ShrubberyCreationForm(void);

		ShrubberyCreationForm(std::string const & target);
		ShrubberyCreationForm(std::string name, unsigned int signGrade, unsigned int execGrade);
		ShrubberyCreationForm(ShrubberyCreationForm const & form);
		~ShrubberyCreationForm(void);

		ShrubberyCreationForm & operator=(const ShrubberyCreationForm & form);

		virtual void execute(Bureaucrat const & executor) const;

};

#endif