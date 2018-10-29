#include "OfficeBlock.hpp"

OfficeBlock::OfficeBlock() : _intern(NULL), _signer(NULL), _executor(NULL){

}

OfficeBlock::OfficeBlock(OfficeBlock const & OfficeBlock) {
	*this = OfficeBlock;
}

OfficeBlock::~OfficeBlock() {

}

OfficeBlock::OfficeBlock(Intern & intern, Bureaucrat & signer, Bureaucrat & executor) {
	this->setSigner(signer);
	this->setIntern(intern);
	this->setExecutor(executor);
}

OfficeBlock::OfficeBlock(Intern *intern, Bureaucrat *signer, Bureaucrat *executor) {
	this->setSigner(signer);
	this->setIntern(intern);
	this->setExecutor(executor);
}

OfficeBlock & OfficeBlock::operator=(OfficeBlock const & ob) {
	(void)ob;
	throw OfficeBlock::BadConstructor();
	return (*this);
}

void	OfficeBlock::setSigner(Bureaucrat & signer) {
	this->_signer = &signer;
}

void	OfficeBlock::setIntern(Intern & intern) {
	this->_intern = &intern;
}

void	OfficeBlock::setExecutor(Bureaucrat & executor) {
	this->_executor = &executor;
}

void	OfficeBlock::setSigner(Bureaucrat *signer) {
	this->_signer = signer;
}

void	OfficeBlock::setIntern(Intern *intern) {
	this->_intern = intern;
}

void	OfficeBlock::setExecutor(Bureaucrat *executor) {
	this->_executor = executor;
}

void	OfficeBlock::doBureaucracy(std::string const & formName, std::string const & target) const {
	if (!this->_intern || !this->_signer ||  !this->_executor)
		throw OfficeBlock::NoLink();
	else {
		Form *form;
		Bureaucrat *last;
		try {
			form = this->_intern->makeForm(formName, target);
			std::cout << *form;
			last = this->_signer;
			this->_signer->signForm(*form);
			std::cout << *form;
			last = this->_executor;
			this->_executor->executeForm(*form);
			delete form;
		}
		catch(Intern::NoForm const & e) {
			std::cout << "Intern has failed" << std::endl;
			std::cout << e.what() << std::endl;
		}
		catch(Form::GradeTooLowException const & e){
			std::cout << last->getName() << " can't do thing because " << std::endl;
			std::cout << e.what() << std::endl;
		}
		catch(std::exception const & e) {
			std::cout << e.what() << std::endl;
		}
	}
}

OfficeBlock::BadConstructor::BadConstructor() {};
OfficeBlock::BadConstructor::~BadConstructor() throw() {};
OfficeBlock::BadConstructor::BadConstructor(BadConstructor const & e) {
	*this = e;
}

OfficeBlock::BadConstructor	& OfficeBlock::BadConstructor::operator=(OfficeBlock::BadConstructor const &e)
{
	std::exception::operator=(e);
	return (*this);
}


const char * OfficeBlock::BadConstructor:: what(void) const throw() {
	return ("Bad constructor...");
}

OfficeBlock::NoLink::NoLink() {};
OfficeBlock::NoLink::~NoLink() throw() {};
OfficeBlock::NoLink::NoLink(NoLink const & e) {
	*this = e;
}

OfficeBlock::NoLink	& OfficeBlock::NoLink::operator=(OfficeBlock::NoLink const &e)
{
	std::exception::operator=(e);
	return (*this);
}


const char * OfficeBlock::NoLink:: what(void) const throw() {
	return ("There is no link in bureaucrat's chain...");
}
