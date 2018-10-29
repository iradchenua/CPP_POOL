#include "Fixed.class.hpp"

Fixed::Fixed(void) {

	std::cout << "Default constructor called" << std::endl;
	this->_value = 0;
}

int 	Fixed::toInt(void) const {
	return (this->_value >> Fixed::_frBits);
}

float 	Fixed::toFloat(void) const {
	return ((float)this->_value / 256);
}

Fixed::Fixed(int const number) {

	std::cout << "Int constructor called" << std::endl;
	this->_value = number << Fixed::_frBits;
}

Fixed::Fixed(float const number) {
	std::cout << "Default constructor called" << std::endl;

	this->_value = roundf(number * 256);
}

Fixed::Fixed(Fixed const & number) {

	std::cout << "Copy constructor called" << std::endl;
	this->_value = number.getRawBits();
}

void Fixed::setRawBits(int const raw) {
	this->_value = raw;
}

int Fixed::getRawBits(void) const {

	//std::cout << "getRawBits member function called" << std::endl;
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

std::ostream & operator<<(std::ostream & o, Fixed const & number) {
	o << (number.toFloat());
	return o;
}

int const Fixed::_frBits = 8;