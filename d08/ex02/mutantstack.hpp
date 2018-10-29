#ifndef MUTANT_STACK_HPP
#define MUTANT_STACK_HPP

#include <stack>
#include <iostream>
#include <list>

template<typename T>

class MutantStack : public std::stack<T> {
	public:
		MutantStack<T>() : std::stack<T>() {

		};
		MutantStack<T>(MutantStack<T> const & mstack) : std::stack<T>(mstack) {
			std::list<T> copy = mstack._hide;
			this->_hide = copy;
		};
		~MutantStack<T>() {
	
		};

		MutantStack<T> const & operator=(MutantStack<T> const & mstack) {
			this->std::stack<T>::operator=(mstack);
			std::list<T> copy = mstack._hide;
			this->_hide = mstack._hide;
			return (*this);
		};

		typedef typename std::list<T>::iterator iterator;

		iterator begin() {
			return (this->_hide.begin());
		};
		iterator end() {
			return (this->_hide.end());
		};
		
		void push(T const & val) {
			this->std::stack<T>::push(val);
			this->_hide.push_front(val);
		};

		void pop() {
			this->_hide.pop_front();
			return (this->std::stack<T>::pop());
		};
	private:
		std::list<T> _hide;
};

#endif