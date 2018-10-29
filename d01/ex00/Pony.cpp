#include "Pony.hpp"

Pony::Pony(std::string color, std::string name, std::string loc) {
	this->_loc = loc;
	this->_color = color;
	this->_name = name;
	this->greeting();
	std::cout << "I was born a moment ago." << std::endl;
}

void	Pony::greeting(void) {
	std::cout << "Hello my name is " \
	<< this->_name << ". I am pony with " \
	<< this->_color << " color!" \
	<< "I live on " << this->_loc \
	<< std:: endl;
}

Pony::~Pony(void) {
	std::cout << "Unfortunetly, pony does not live forever. Goodbye and remember my name was " \
	<< this->_name \
	<< std::endl;	
}