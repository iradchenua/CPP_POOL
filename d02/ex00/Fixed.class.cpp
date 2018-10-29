#include "Fixed.class.hpp"

Fixed::Fixed(void) {

	std::cout << "Default constructor called" << std::endl;
	this->_value = 0;
}

Fixed::Fixed(Fixed const & number) {

	std::cout << "Copy constructor called" << std::endl;
	this->_value = number.getRawBits();
}

void Fixed::setRawBits(int const raw) {
	this->_value = raw;
}

int Fixed::getRawBits(void) const {

	std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

Fixed::~Fixed(void) {

	std::cout << "Destructor called" << std::endl;
	return ;
}

Fixed & Fixed::operator=(Fixed const & number) {

	std::cout << "Assignation operator called" << std::endl;
	this->_value = number.getRawBits();
	return (*this);
}

int const Fixed::_frBits = 8;