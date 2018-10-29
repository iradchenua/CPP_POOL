#include "Fixed.class.hpp"

Fixed::Fixed(void) {

	this->_value = 0;
}

int 	Fixed::toInt(void) const {
	return (this->_value >> Fixed::_frBits);
}

float 	Fixed::toFloat(void) const {
	return ((float)this->_value / 256);
}

Fixed::Fixed(int const number) {

	this->_value = number << Fixed::_frBits;
}

Fixed::Fixed(float const number) {

	this->_value = roundf(number * 256);
}

Fixed::Fixed(Fixed const & number) {

	this->_value = number.getRawBits();
}

void Fixed::setRawBits(int const raw) {
	this->_value = raw;
}

int Fixed::getRawBits(void) const {
	return (this->_value);
}

Fixed::~Fixed(void) {
	return ;
}

bool Fixed::operator<(Fixed const & number) const {
	return (this->getRawBits() < number.getRawBits());
}

bool Fixed::operator == (Fixed const & number) const {
	return (this->getRawBits() == number.getRawBits());
}

bool Fixed::operator>(Fixed const & number) const {

	return (!(*this < number || *this == number));
}

bool Fixed::operator >= (Fixed const & number) const {
	return (*this > number || *this == number);
}

bool Fixed::operator <= (Fixed const & number) const {
	return (*this < number || *this == number);
}

bool Fixed::operator != (Fixed const & number) const {
	return (!(*this == number));
}

Fixed  Fixed::operator+(Fixed const & number) const {
	Fixed res;

	res.setRawBits(this->getRawBits() + number.getRawBits());
	return (res);
}

Fixed  Fixed::operator-(Fixed const & number) const {
	Fixed res;

	res.setRawBits(this->getRawBits() - number.getRawBits());
	return (res);
}

Fixed  Fixed::operator*(Fixed const & number) const {
	Fixed res;

	res.setRawBits((this->getRawBits() * number.getRawBits()) >> Fixed::_frBits);
	return (res);
}

Fixed  Fixed::operator/(Fixed const & number) const {
	Fixed res;

	res.setRawBits((this->getRawBits() / number.getRawBits()) << Fixed::_frBits);
	return (res);
}

Fixed & Fixed::operator++(void) {
	this->_value++;
	return (*this);
}

Fixed  Fixed::operator++(int) {
	Fixed cpy = Fixed(*this);
	operator++();
	return (cpy);
}

Fixed & Fixed::operator--(void) {
	this->setRawBits(this->getRawBits() - 1);
	return (*this);
}

Fixed   Fixed::operator--(int) {
	Fixed cpy = Fixed(*this);
	operator--();
	return (cpy);
}

Fixed & Fixed::operator=(Fixed const & number) {

	std::cout << "Assignation operator called" << std::endl;
	this->_value = number.getRawBits();
	return (*this);
}

Fixed & Fixed::max(Fixed & number1, Fixed & number2) {
	return (number1 > number2 ? number1 : number2);
}

Fixed const & Fixed::max(Fixed const & number1, Fixed const & number2) {
	return (number1 > number2 ? number1 : number2);
}

Fixed & Fixed::min(Fixed & number1, Fixed & number2) {
	return (number1 < number2 ? number1 : number2);
}

Fixed const & Fixed::min(Fixed const & number1, Fixed const & number2) {
	return (number1 < number2 ? number1 : number2);
}

std::ostream & operator<<(std::ostream & o, Fixed const & number) {
	o << (number.toFloat());
	return o;
}

int const Fixed::_frBits = 8;