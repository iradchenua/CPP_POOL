#include "Bureaucrat.hpp"
#include "Form.hpp"


Form::Form(void) : _name("form"), _isSign(false) {
 	throw Form::NoName();
}

Form::Form(std::string name, unsigned int signGrade, unsigned int execGrade) : _name(name), _isSign(false) {
	if (signGrade < Bureaucrat::getHighGrade() || execGrade < Bureaucrat::getHighGrade())
		throw Form::GradeTooHighException();
	else if(signGrade > Bureaucrat::getLowGrade() || execGrade > Bureaucrat::getLowGrade())
		throw Form::GradeTooLowException();
	else
	{
		this->_signGrade = signGrade;
		this->_execGrade = execGrade;
	}
}

Form::Form(const Form & form) {
	*this = form;
}

Form::~Form(void) {
	
}

Form & Form::operator=(const Form & form) {
	(void)form;

	return (*this);
}

void 	Form::beSigned(const Bureaucrat & bur) {
	if (bur.getGrade() <= this->_signGrade)
		this->_isSign = true;
	else
		throw Form::GradeTooLowException();
}

std::string Form::getName(void) const {
	return (this->_name);
}

unsigned int Form::getSignGrade(void) const {
	return (this->_signGrade);
}

bool		Form::getIsSign(void) const {
	return (this->_isSign);
}

unsigned int Form::getExecGrade(void) const {
	return (this->_execGrade);
}

Form::GradeTooHighException::GradeTooHighException() {};
Form::GradeTooHighException::~GradeTooHighException() throw() {};
Form::GradeTooHighException::GradeTooHighException(GradeTooHighException const & e) {
	*this = e;
}

Form::GradeTooLowException::GradeTooLowException() {};
Form::GradeTooLowException::~GradeTooLowException() throw() {};
Form::GradeTooLowException::GradeTooLowException(GradeTooLowException const & e) {
	*this = e;
}

Form::NoName::NoName() {};
Form::NoName::~NoName() throw() {};
Form::NoName::NoName(NoName const & e) {
	*this = e;
}

Form::NoTarget::NoTarget() {};
Form::NoTarget::~NoTarget() throw() {};
Form::NoTarget::NoTarget(NoTarget const & e) {
	*this = e;
}

Form::NoSign::NoSign() {};
Form::NoSign::~NoSign() throw() {};
Form::NoSign::NoSign(NoSign const & e) {
	*this = e;
}


void Form::execute(Bureaucrat const & executor) const {
	if (!this->_isSign)
		throw Form::NoSign();
	if (executor.getGrade() > this->getExecGrade())
		throw Form::GradeTooLowException();
}

void Form::setTarget(std::string const & target) {
	this->_target = target;
}


std::string Form::getTarget(void) const {
	return (this->_target);
}

const char * Form::NoSign:: what(void) const throw() {
	return ("The form is not signed for to be executed...");
}

const char * Form::NoName:: what(void) const throw() {
	return ("Can't create form without name...");
}

const char * Form::NoTarget:: what(void) const throw() {
	return ("Can't create form without target...");
}

Form::NoName	& Form::NoName::operator=(Form::NoName const &e)
{
	std::exception::operator=(e);
	return (*this);
}

Form::NoSign	& Form::NoSign::operator=(Form::NoSign const &e)
{
	std::exception::operator=(e);
	return (*this);
}

Form::NoTarget	& Form::NoTarget::operator=(Form::NoTarget const &e)
{
	std::exception::operator=(e);
	return (*this);
}

Form::GradeTooLowException	& Form::GradeTooLowException::operator=(Form::GradeTooLowException const &e)
{
	std::exception::operator=(e);
	return (*this);
}

Form::GradeTooHighException	& Form::GradeTooHighException::operator=(Form::GradeTooHighException const &e)
{
	std::exception::operator=(e);
	return (*this);
}

std::ostream & operator<<(std::ostream & o, Form const & form) {
	o << form.getName() \
	<< ", sign grade is " \
	<< form.getSignGrade() \
	<< ", exec grade is " \
	<< form.getExecGrade() \
	<< ". This form is" \
	<< (form.getIsSign() ? " " : " not ") \
	<< "signed." \
	<< std::endl; 
	return (o);
}