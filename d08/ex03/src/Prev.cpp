#include "Prev.hpp"

Prev::Prev() {
	this->_symbol = '<';
}

void Prev::execute(std::vector<char>::iterator & it) {
	it--;
}

Prev::~Prev() {

};

Prev::Prev(Prev const & ai) {
	static_cast<void>(ai);

}
		
Prev const & Prev::operator=(const Prev & ai) {
	static_cast<void>(ai);
	return (*this);
}