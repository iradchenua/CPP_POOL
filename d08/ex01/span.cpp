#include "span.hpp"
#include <iostream>

Span::Span() : _numbers(NULL), _N(0), _max(std::numeric_limits<int>::min()), _min( std::numeric_limits<int>::max()) {
	throw std::logic_error("There is no sense to create span with 0 size");
}

Span::Span(unsigned int const & N) : _N(N),_max(std::numeric_limits<int>::min()), _min(std::numeric_limits<int>::max()) {
	if (this->_N <= 1)
		throw std::logic_error( "There is no sense to create span with " + std::to_string(N) + " size");
	this->_numbers = new std::list<int>();
}

Span::Span(const Span & span) : _numbers(NULL), _N(span.getSize()) {
	*this = span;
}

unsigned int const & Span::getSize() const {
	return (this->_N);
}

std::list<int> const & Span::getElementsLikeList() const {
	return (*(this->_numbers));
}

int const & Span::getMax() const {
	return (this->_max);
}

Span::Span(std::list<int>::const_iterator begin, std::list<int>::const_iterator end) : \
_numbers(NULL), _N(std::distance(begin, end)), _max(std::numeric_limits<int>::min()), _min(std::numeric_limits<int>::max()) {
	if (this->_N <= 1)
		throw std::logic_error( "There is no sense to create span with " + std::to_string(this->_N) + " size");
	this->_numbers = new std::list<int>();
	for (std::list<int>::const_iterator it = begin; it != end; it++)
	{
		this->_numbers->push_back(*it);
		if (this->_max < *it)
			this->_max = *it;
		if (this->_min > *it)
			this->_min = *it;
	}
}

int const & Span::getMin() const {
	return (this->_min);
}


Span const & Span::operator=(const Span & span) {
	if (this->_N != span.getSize())
		throw std::out_of_range("span that is used like src larger then span that is used like dst.");
	if (this->_numbers)
		delete this->_numbers;
	this->_numbers = new std::list<int>(span.getElementsLikeList());
	this->_max = span.getMax();
	this->_min = span.getMin();
	return (*this);
}

Span::~Span() {
	if (this->_numbers)
		delete this->_numbers;
}

unsigned int Span::shortestSpan() const {
	if (this->_numbers->size() <= 1)
		throw std::logic_error( "There is no sense to find span with current " \
			+ std::to_string(this->_numbers->size()) + " size");
	unsigned int shorestSpan;
	unsigned long len = 0;
	std::list<int>::iterator jt;
	std::list<int>::iterator it;

	for (it = this->_numbers->begin(); it != this->_numbers->end(); it++)
	{
		if (it == this->_numbers->begin())
			shorestSpan = *it;
    	for (jt = it; jt != this->_numbers->end(); jt++)
    	{
    		len = std::abs(*it - *jt);
    		if (shorestSpan > len && len != 0) {
    			shorestSpan = len;
    		}
    	}
    }
	return (shorestSpan);
}

unsigned int Span::longestSpan() const {
	if (this->_numbers->size() <= 1)
		throw std::logic_error( "There is no sense to find span with current " \
			+ std::to_string(this->_numbers->size()) + " size");
	return (this->_max - this->_min);
}

void	Span::addNumber(int num) {
	if (this->_numbers->size() < this->_N)
	{
		if (this->_numbers->size() == 0) {
			this->_min = num;
			this->_max = num;
		}
		this->_numbers->push_back(num);
		if (this->_min > num)
			this->_min = num;
		if (this->_max < num)
			this->_max = num;
	}
	else
		throw std::out_of_range( "This is already " + std::to_string(this->_N) + " elements");
}