#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void) {

	int c = std::rand() % 3;
	if (c == 0) {
		std::cout << "A" << std::endl;
		return (new A);
	}
	else if (c == 1) {
		std::cout << "B" << std::endl;
		return (new B);
	}
	std::cout << "C" << std::endl;
	return (new C);
}

void	identify_from_pointer (Base *ptr) {
	Base *p = dynamic_cast<A *>(ptr);
	if (p != NULL) {
		std::cout << "A" << std::endl;
		return ;
	}
	p = dynamic_cast<B *>(ptr);
	if (p != NULL) {
		std::cout << "B" << std::endl;
		return ;
	}
	p = dynamic_cast<C *>(ptr);
	if (p != NULL)
		std::cout << "C" << std::endl;
	return ;
}

void	identify_from_reference (Base  &ptr) {
	try {
		Base & p = dynamic_cast<A & >(ptr);
		static_cast<void>(p);
		std::cout << "A" << std::endl;
		return ;
	}
	catch (std::bad_cast & bc) {
		
	}
	try {
		Base & p = dynamic_cast<B & >(ptr);
		static_cast<void>(p);
		std::cout << "B" << std::endl;
		return ;
	}
	catch (std::bad_cast & bc) {
		
	}
	try {
		Base & p = dynamic_cast<C & >(ptr);
		static_cast<void>(p);
		std::cout << "C" << std::endl;
		return ;
	}
	catch (std::bad_cast & bc) {
		
	}
}

int main() {

	std::srand(std::time(0));
	Base *some = generate();

	identify_from_reference(*some);
	identify_from_pointer(some);
	return (0);
}