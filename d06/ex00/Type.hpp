#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <stdlib.h>

#ifndef TYPE_HPP
#define TYPE_HPP

class Type {
	public:
		Type(std::string const & _sValue);

		Type();
		~Type();

		Type(const Type & tp);

		operator double() const;
		operator float() const;
		operator int() const;
		operator char() const;

		Type const & operator=(const Type &  tp);

		bool 	getPossibleChar() const;
		bool 	getPossibleInt() const;
		bool 	getPossibleFloat() const;
		bool 	getPossibleDouble() const;

		std::string const & getSValue() const;
	private:
		std::string _sValue;
		bool	_possibleChar;
		bool	_possibleInt;
		bool	_possibleFloat;
		bool	_possibleDouble;

		double	_dValue;
		float 	_fValue;
		char 	_cValue;
		int		_iValue;
};

#endif