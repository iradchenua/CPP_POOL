#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <list>
#include <limits>
#include <stdexcept>

class Span {
	public:
		Span();
		Span(unsigned int const & N);
		Span(const Span & span);
		~Span();
		Span(std::list<int>::const_iterator begin, std::list<int>::const_iterator end);
		Span const & operator=(const Span & span);

		unsigned int shortestSpan() const;
		unsigned int longestSpan() const;

		int const & 	getMax() const;
		int const & 	getMin() const;

		unsigned int const & getSize() const;
		std::list<int> const & getElementsLikeList() const;

		void	addNumber(int num);

	private:
		std::list<int> *_numbers;
		const unsigned int _N;
		int _max;
		int _min;
};

#endif