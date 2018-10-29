#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <stdexcept>
#include <iostream>
#include <algorithm>

template<typename T>

int easyfind(const T & a, const int & b) {
	typename T::const_iterator c;

	c = std::find(a.begin(), a.end(), b);
	if (*c == b)
		return (*c);
	throw std::logic_error("Value dose not exist.");
}

#endif
