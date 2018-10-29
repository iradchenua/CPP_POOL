#include "Down.hpp"

Down::Down() {
	this->_symbol = '-';
}

void Down::execute(std::vector<char>::iterator & it) {
	(*it)--;
}

Down::~Down() {

};

Down::Down(Down const & ai) {
	static_cast<void>(ai);

}
		
Down const & Down::operator=(const Down & ai) {
	static_cast<void>(ai);
	return (*this);
}