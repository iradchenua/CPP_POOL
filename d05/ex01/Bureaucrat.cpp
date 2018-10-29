#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(void) {
	throw Bureaucrat::NoName();
}

Bureaucrat::Bureaucrat(std::string name, unsigned int grade) : _name(name) {
	if (grade < Bureaucrat::_highGrade)
		throw Bureaucrat::GradeTooHighException();
	else if(grade > Bureaucrat::_lowGrade)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat & bur) {
	*this = bur;
}

Bureaucrat::~Bureaucrat(void) {
	
}

void		Bureaucrat::signForm(Form & form) const {
	try {
		form.beSigned(*this);
		std::cout << this->_name \
		<<" signs " << form.getName() \
		<< std::endl;
	}
	catch (std::exception & e) {
		std::cout << this->_name \
		<<" cannot sign " << form.getName() \
		<< " because his " << e.what() \
		<< std::endl;
	}
}

unsigned int Bureaucrat::getHighGrade(void) {
	return (Bureaucrat::_highGrade);
}

unsigned int Bureaucrat::getLowGrade(void) {
	return (Bureaucrat::_lowGrade);
}

Bureaucrat & Bureaucrat::operator=(const Bureaucrat & bur) {
	this->_grade = bur.getGrade();

	return (*this);
}

void 	Bureaucrat::upGrade(void) {
	if (this->_grade <= Bureaucrat::_highGrade)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade--;
}

void 	Bureaucrat::downGrade(void) {
	if (this->_grade >= Bureaucrat::_lowGrade)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade++;
}

std::string Bureaucrat::getName(void) const {
	return (this->_name);
}

unsigned int Bureaucrat::getGrade(void) const {
	return (this->_grade);
}

const char * Bureaucrat::GradeTooHighException:: what(void) const throw() {
	return ("Grade is to high...");
}

Bureaucrat::GradeTooHighException::GradeTooHighException() {};
Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() {};
Bureaucrat::GradeTooHighException::GradeTooHighException(GradeTooHighException const & e) {
	*this = e;
}

Bureaucrat::GradeTooLowException::GradeTooLowException() {};
Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() {};
Bureaucrat::GradeTooLowException::GradeTooLowException(GradeTooLowException const & e) {
	*this = e;
}


Bureaucrat::NoName::NoName() {};
Bureaucrat::NoName::~NoName() throw() {};
Bureaucrat::NoName::NoName(NoName const & e) {
	*this = e;
}

Bureaucrat::GradeTooLowException	& Bureaucrat::GradeTooLowException::operator=(Bureaucrat::GradeTooLowException const &e)
{
	std::exception::operator=(e);
	return (*this);
}

Bureaucrat::GradeTooHighException	& Bureaucrat::GradeTooHighException::operator=(Bureaucrat::GradeTooHighException const &e)
{
	std::exception::operator=(e);
	return (*this);
}

Bureaucrat::NoName	& Bureaucrat::NoName::operator=(Bureaucrat::NoName const &e)
{
	std::exception::operator=(e);
	return (*this);
}

const char * Bureaucrat::GradeTooLowException:: what(void) const throw() {
	return ("Grade is to low...");
}


const char * Bureaucrat::NoName:: what(void) const throw() {
	return ("Can't create bureaucrat without name...");
}

std::ostream & operator<<(std::ostream & o, Bureaucrat const & bur) {
	o << bur.getName() \
	<< ", bureaucrat grade is " \
	<< bur.getGrade() \
	<< std::endl; 
	return (o);
}

const unsigned int Bureaucrat::_highGrade = 1;
const unsigned int Bureaucrat::_lowGrade = 150;