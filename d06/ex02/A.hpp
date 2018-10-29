#include "Base.hpp"

#ifndef A_HPP
#define A_HPP

class A : public Base {
	public:
		A();
		~A();

		A(const A & a);
		const A & operator=(const A & a);
};

#endif