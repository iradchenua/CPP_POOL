// constructing vectors
#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <map>

int main (void)
{
  int ints[] = {10, 123, 43, 42, 432, 100};
  std::vector<int> vec (ints, ints + sizeof(ints) / sizeof(int));
  std::vector<int>::const_iterator l;
  std::list<int>::const_iterator it;

  std::list<int> listt (ints, ints + sizeof(ints) / sizeof(int) );

  try {
  	std::cout << "value is find " << easyfind(listt, 100) << std::endl;
  }
  catch(std::logic_error const & e) {
  	std::cout << e.what() << std::endl;
  }

   try {
  	std::cout << "value is find " << easyfind(vec, 42) << std::endl;
  }
  catch(std::logic_error const & e) {
  	std::cout << e.what() << std::endl;
  }
  return 0;
}