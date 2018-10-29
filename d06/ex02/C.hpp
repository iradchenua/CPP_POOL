#include "Base.hpp"

#ifndef C_HPP
#define C_HPP

class C : public Base {
	public:
		C();
		~C();

		C(const C & c);
		const C & operator=(const C & c);
};

#endif