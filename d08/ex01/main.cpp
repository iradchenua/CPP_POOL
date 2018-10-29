#include "span.hpp"
#include <iostream>

int main()
{
	Span sp = Span(5);
	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	Span sp2 = Span(sp);
	int *myints = new int[10001];
	for (int i = 0; i < 10001; i++) {
		myints[i] = 100*i + 100;
		if (i % 2)
			myints[i] = -myints[i];
	}
  	std::list<int> hundered(myints, myints + 10001 );

  	try {
		std::cout << "10001 size test" << std::endl;
		Span sp3(hundered.begin(), hundered.end());
		std::cout << sp3.shortestSpan() << std::endl;
		std::cout << sp3.longestSpan() << std::endl;
		std::cout << "10001 size test end" << std::endl;
	} catch (std::logic_error const & e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << "empty constructor test" << std::endl;
		Span sp;
	} catch (std::logic_error const & e) {
		std::cout << e.what() << std::endl;
		std::cout << "empty constructor test end" << std::endl;
	}

	try {
		std::cout << "bad size assign operator test" << std::endl;
		Span sp1(10);
		Span sp2 (9);
		sp1 = sp2;
	} catch (std::logic_error const & e) {
		std::cout << e.what() << std::endl;
		std::cout << "bad size assign operator test end" << std::endl;
	}

	try {
		int newints1[] = {1,2,3,4,5};
		int newints2[] = {5,7,12,14,20};
		std::list<int> list1(newints1, newints1 + 5);
		std::list<int> list2(newints2, newints2 + 5);
		std::cout << "assign operator test" << std::endl;
		Span sp1(list1.begin(), list1.end());
		Span sp2 (list2.begin(), list2.end());

		std::cout << "first span" << std::endl;
		std::cout << sp1.longestSpan() << std::endl;
		std::cout << sp1.shortestSpan() << std::endl;

		std::cout << "second span" << std::endl;
		std::cout << sp2.longestSpan() << std::endl;
		std::cout << sp2.shortestSpan() << std::endl;

		sp1 = sp2;

		std::cout << "first span" << std::endl;
		std::cout << sp1.longestSpan() << std::endl;
		std::cout << sp1.shortestSpan() << std::endl;

		std::cout << "second span" << std::endl;
		std::cout << sp2.longestSpan() << std::endl;
		std::cout << sp2.shortestSpan() << std::endl;
		std::cout << "assign operator test end" << std::endl;
	} catch (std::logic_error const & e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << "bad size test" << std::endl;
		Span sp(1);
	} catch (std::logic_error const & e) {
		std::cout << e.what() << std::endl;
		std::cout << "bad size test end" << std::endl;
	}
	try {
		std::cout << "bad size test" << std::endl;
		Span sp(0);
	} catch (std::logic_error const & e) {
		std::cout << e.what() << std::endl;
		std::cout << "bad size test end" << std::endl;
	}

	std::cout << "simple test" << std::endl;
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	std::cout << "simple test end" << std::endl;

	std::cout << "test copy operator" << std::endl;
	std::cout << sp2.shortestSpan() << std::endl;
	std::cout << sp2.longestSpan() << std::endl;
	std::cout << "test copy operator end" << std::endl;
	

}