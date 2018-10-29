#include "Type.hpp"

bool is_number(const std::string& s)
{
	int pCount = 0;

	for (size_t i = 0; i < s.size(); i++) {
		if (!std::isdigit(s[i])) {
			if (s[i] == '.' && pCount >= 1)
				return (0);
			else if (i == s.size() - 1) {
				if (s[i] != 'f')
					return (0);
			}
			else if (s[i] == '.')
				pCount++;
			else
				return (0);
		}
	}
	return (1);
}

Type::Type() : _sValue("nan"), _possibleChar(0), \
_possibleInt(0), _possibleFloat(0), _possibleDouble(0), _dValue(0), _fValue(0), _cValue(0), _iValue(0)
{

}

Type::~Type() {

}

std::string const & Type::getSValue() const {
	return (this->_sValue);
}

Type::Type(const Type & tp) {
	*this = tp;
}

bool Type::getPossibleChar() const {
	return (this->_possibleChar);
}

bool Type::getPossibleInt() const {
	return (this->_possibleInt);
}

bool Type::getPossibleFloat() const {
	return (this->_possibleFloat);
}

bool Type::getPossibleDouble() const {
	return (this->_possibleDouble);
}

Type::operator double() const {
	return (this->_dValue);
}

Type::operator float() const {
	return (this->_fValue);
}

Type::operator int() const {
	return (this->_iValue);
}

Type::operator char() const {
	return (this->_cValue);
}

Type::Type(std::string const & sValue) : _sValue(sValue), _possibleChar(1), \
_possibleInt(1), _possibleFloat(1), _possibleDouble(1) {
	
	if (this->_sValue.size() == 1 && !std::isdigit(this->_sValue.at(0))) {
		this->_cValue = static_cast<char>(this->_sValue.at(0));
		this->_fValue = static_cast<float>(this->_sValue.at(0));
		this->_dValue = static_cast<double>(this->_sValue.at(0));
		this->_iValue = static_cast<int>(this->_sValue.at(0));
	}
	else if ((this->_sValue != "inf" && this->_sValue != "-inf" && this->_sValue != "+inf") && !is_number(this->_sValue)){
		this->_possibleInt = 0;
		this->_possibleChar = 0;
		this->_possibleFloat = 0;
		this->_possibleDouble = 0;
	}
	else {
		this->_dValue = static_cast<double>(std::atof(this->_sValue.c_str()));
		this->_fValue = static_cast<float>(this->_dValue);

		if (std::isnan(this->_dValue))
			this->_possibleInt = 0;
		else if (this->_dValue < std::numeric_limits<int>::min() || this->_dValue > std::numeric_limits<int>::max())
			this->_possibleInt = 0;
		else {
			this->_iValue = static_cast<int>(this->_dValue);
		}
		

		if (!this->_possibleInt)
			this->_possibleChar = 0;
		else if (this->_iValue > std::numeric_limits<char>::max() || this->_iValue < std::numeric_limits<char>::min()) {
			this->_possibleChar = 0;
		}
		else {
			this->_cValue = static_cast<char>(this->_iValue);
		}
	}
}

Type const & Type::operator=(const Type &  tp) {
	
	this->_sValue = tp.getSValue();
	return (*this);
}