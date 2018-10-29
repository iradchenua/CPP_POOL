#include "mutantstack.hpp"
#include <iostream>

int main()
{ 
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);

		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	{
		MutantStack<char> mstack;
		mstack.push('A');
		mstack.push('B');
		mstack.push('C');
		mstack.push('D');
		mstack.push('E');
		mstack.push('F');
		MutantStack<char> s(mstack);

		mstack.pop();
		MutantStack<char>::iterator it = mstack.begin();
		MutantStack<char>::iterator ite = mstack.end();

		MutantStack<char>::iterator it1 = s.begin();
		MutantStack<char>::iterator ite1 = s.end();

		while (it != ite)
		{
			std::cout << "first stack" << std::endl;
			std::cout << *it << std::endl;
			++it;
		}
		
		while (it1 != ite1)
		{
			std::cout << "second stack" << std::endl;
			std::cout << *it1 << std::endl;
			++it1;
		}		

		MutantStack<char> mstack2;

		mstack2 = mstack;

		MutantStack<char>::iterator it2 = mstack2.begin();
		MutantStack<char>::iterator ite2= mstack2.end();
		while (it2 != ite2)
		{
			std::cout << "third stack" << std::endl;
			std::cout << *it2 << std::endl;
			++it2;
		}
	}
	return (0);
}