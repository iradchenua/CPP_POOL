#include "Up.hpp"

Up::Up() {
	this->_symbol = '+';
}

void Up::execute(std::vector<char>::iterator & it) {
	(*it)++;
}

Up::~Up() {
	
}

Up::Up(Up const & ai) {
	static_cast<void>(ai);

}
		
Up const & Up::operator=(const Up & ai) {
	static_cast<void>(ai);
	return (*this);
}