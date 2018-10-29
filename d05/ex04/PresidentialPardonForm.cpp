#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"


PresidentialPardonForm::PresidentialPardonForm(void) : Form("PresidentialPardonForm", 25, 5) {
	throw Form::NoTarget();
}


PresidentialPardonForm::PresidentialPardonForm(std::string const & target) : Form("PresidentialPardonForm", 25, 5) {
	this->setTarget(target);
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm & form) {
	*this = form;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
	
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	this->Form::execute(executor);
	std::cout << this->getTarget() + " has been pardoned by Zafod Beeblebrox " << std::endl;
}

PresidentialPardonForm & PresidentialPardonForm::operator=(const PresidentialPardonForm & form) {
	this->setTarget(form.getTarget());
	return (*this);
}