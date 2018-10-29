#include "Get.hpp"

Get::Get() {
	this->_symbol = ',';
}

void Get::execute(std::vector<char>::iterator & it) {
	std::cin >> *it;
}

Get::~Get() {

};

Get::Get(Get const & ai) {
	static_cast<void>(ai);

}
		
Get const & Get::operator=(const Get & ai) {
	static_cast<void>(ai);
	return (*this);
}