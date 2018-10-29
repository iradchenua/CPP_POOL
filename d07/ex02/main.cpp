#include "Array.tpp"
#include <iostream>

template< typename T>

void iter(T const *array, size_t length, void (*f)(T const &)) {
	if (!array)
		return ;
	if (!f)
		return ;
	for (size_t i = 0; i < length; i++) {
		f(array[i]);
	}
}

template< typename U>

void iter(Array<U> const  & array, size_t length, void (*f)(U const &)) {
	if (!f)
		return ;
	for (size_t i = 0; i < length; i++) {
		f(array[i]);
	}
}

template< typename T>

void show(T const & toShow) {
	std::cout << toShow << std::endl;
}

template< typename T>

void testType(Array<T> const & array, size_t length) {
	Array<T> newArray(array);
	Array<T> zeroArray(0);
	
	std::cout << "zero sized array: " << std::endl;
	iter(zeroArray, 0, show);
	std::cout << "passed array: " << std::endl;
	iter(array, length, show);
	std::cout << "array by copy constructor" << std::endl;
	iter(newArray, length, show);
	std::cout << "array by copy constructor change 2 index on 3 index" << std::endl;

	try {
		newArray[2] = newArray[3];
		iter(newArray, length, show);	
	}
	catch(std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "passed array after change in copied array" << std::endl;
	iter(array, length, show);

	std::cout << "array by = operator" << std::endl;
	zeroArray = array;
	iter(zeroArray, length, show);
	std::cout << "array by = operator change 2 index on 3 index" << std::endl;

	try {
		zeroArray[2] = newArray[3];
		iter(zeroArray, length, show);	
	}
	catch(std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "passed array after change in copied by = operator array" << std::endl;
	iter(array, length, show);
	std::cout << "try get -1 index from passed array" << std::endl;
	try {
		std::cout << array[-1] << std::endl;
	}
	catch (std::exception & e)  {
		std::cout << e.what() << std::endl;
	}
}

int main() {
	{
		const Array<int> array1(5);
		Array<int> array2(5);

		array2[0] = 1;
		array2[1] = 2;
		array2[2] = 3;
		array2[3] = 4;
		array2[4] = 5;

		testType(array1, 5);
		testType(array2, 5);	
	}
	{
		const Array<std::string> array1(5);
		Array<std::string> array2(5);

		array2[0] = "hello";
		array2[1] = "world";
		array2[2] = "you";
		array2[3] = "are";
		array2[4] = "ugly";

		testType(array1, 5);
		testType(array2, 5);
	}	
	{
		const Array<bool> array1(5);
		Array<bool> array2(5);

		array2[0] = 0;
		array2[1] = 1;
		array2[2] = 0;
		array2[3] = 1;
		array2[4] = 0;

		testType(array1, 5);
		testType(array2, 5);
	}
	return (0);
}