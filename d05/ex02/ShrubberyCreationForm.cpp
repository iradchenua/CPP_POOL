#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"


ShrubberyCreationForm::ShrubberyCreationForm(void) : Form("ShrubberyCreationForm", 145, 137) {
	throw Form::NoTarget();
}


ShrubberyCreationForm::ShrubberyCreationForm(std::string const & target) : Form("ShrubberyCreationForm", 145, 137) {
	this->setTarget(target);
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm & form) {
	*this = form;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
	
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	this->Form::execute(executor);
	std::ofstream file;
	
	try {
		file.open(this->getTarget() + "_shrubbery", std::ofstream::out | std::ofstream::trunc);
		file << "          *          " << std::endl;
	    file << "         / \\         " << std::endl;
	    file << "        /   \\        " << std::endl;
	    file << "       /     \\       " << std::endl;
	    file << "      *       *      " << std::endl;
	    file << "     /          \\     " << std::endl;
	    file << "    *   *   *    *   " << std::endl;
	    file << "   /              \\   " << std::endl;
	    file << "  *                * " << std::endl;
	    file << " /                  \\" << std::endl;
	    file << "*                    *" << std::endl;
		file.close();
	}
	catch (const std::ifstream::failure& e) {
    	std::cout << e.what() << std::endl;
 	}
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm & form) {
	this->setTarget(form.getTarget());
	return (*this);
}