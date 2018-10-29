#include "B.hpp"

B::B() {

}

B::~B() {
	
}

B::B(const B & b) {
	*this = b;
}


const B & B::operator=(const B & b) {
	static_cast<void>(b);
	return (*this);
}