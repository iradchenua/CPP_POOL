#include "Intern.hpp"

Intern::Intern() {

}

Intern::Intern(Intern const & intern) {
	(void)intern;
}

Intern::~Intern() {

}


Intern::NoForm::NoForm() {};
Intern::NoForm::~NoForm() throw() {};
Intern::NoForm::NoForm(NoForm const & e) {
	*this = e;
}

Intern::NoForm	& Intern::NoForm::operator=(Intern::NoForm const &e)
{
	std::exception::operator=(e);
	return (*this);
}


const char * Intern::NoForm:: what(void) const throw() {
	return ("I don't know this form, please don't free me...");
}

Form*                        Intern::_newPresidentialPardonForm(std::string const & target) {
	return (new PresidentialPardonForm(target));
}

Form*                        Intern::_newRobotomyRequestForm(std::string const & target) {
	return (new RobotomyRequestForm(target));
}

Form*                        Intern::_newShrubberyCreationForm(std::string const & target) {
	return (new ShrubberyCreationForm(target));
}

Intern & Intern::operator=(const Intern & intern) {
	(void)intern;
	return (*this);
}

Form *Intern::makeForm(std::string const & name, std::string const & target) {
	for (int i = 0; i < 3; i++) {
		if (Intern::_knownForms[i] == name) {
			std::cout << "Intern creates " + name << std::endl;
			return (this->*Intern::_functions[i])(target);
		}
	}
	throw Intern::NoForm();	
	return (NULL);
}

const std::string Intern::_knownForms[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
const Intern::InternCreate Intern::_functions[3] = {&Intern::_newPresidentialPardonForm, &Intern::_newRobotomyRequestForm, &Intern::_newShrubberyCreationForm};