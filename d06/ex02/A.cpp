#include "A.hpp"

A::A() {

}

A::~A() {
	
}

A::A(const A & a) {
	*this = a;
}


const A & A::operator=(const A & a) {
	static_cast<void>(a);
	return (*this);
}