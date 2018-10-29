#include "Show.hpp"

Show::Show() {
	this->_symbol = '.';
}

void Show::execute(std::vector<char>::iterator & it) {
	std::cout << *it;
}

Show::~Show() {

};

Show::Show(Show const & ai) {
	static_cast<void>(ai);

}
		
Show const & Show::operator=(const Show & ai) {
	static_cast<void>(ai);
	return (*this);
}