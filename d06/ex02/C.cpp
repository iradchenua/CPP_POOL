#include "C.hpp"

C::C() {

}

C::~C() {
	
}

C::C(const C & c) {
	*this = c;
}


const C &  C::operator=(const C & c) {
	static_cast<void>(c);
	return (*this);
}