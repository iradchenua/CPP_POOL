#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"


RobotomyRequestForm::RobotomyRequestForm(void) : Form("RobotomyRequestForm", 72, 45) {
	throw Form::NoTarget();
	std::srand(std::time(0));
}


RobotomyRequestForm::RobotomyRequestForm(std::string const & target) : Form("RobotomyRequestForm", 72, 45) {
	this->setTarget(target);
	std::srand(std::time(0));
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm & form) {
	*this = form;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
	
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	this->Form::execute(executor);
	std::cout << "****some drilling noises ***" << std::endl;
	if (std::rand() % 2)
		std::cout << this->getTarget() + "  has been robotomized successfully " << std::endl;
	else
		std::cout << " failure " << std::endl;
}

RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm & form) {
	this->setTarget(form.getTarget());
	return (*this);
}