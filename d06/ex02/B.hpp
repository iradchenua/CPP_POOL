#include "Base.hpp"

#ifndef B_HPP
#define B_HPP

class B : public Base {
	public:
		B();
		~B();

		B(const B & b);
		const B & operator=(const B & b);
};

#endif