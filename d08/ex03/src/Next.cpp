#include "Next.hpp"

Next::Next() {
	this->_symbol = '>';
}

void Next::execute(std::vector<char>::iterator & it) {
	it++;
}

Next::~Next() {

};

Next::Next(Next const & ai) {
	static_cast<void>(ai);

}
		
Next const & Next::operator=(const Next & ai) {
	static_cast<void>(ai);
	return (*this);
}