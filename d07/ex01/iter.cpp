#include <iostream>
#include <string>

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

template< typename T>

void show(T const & toShow) {
	std::cout << toShow << std::endl;
}

template< typename T>

void showTwice(T const & toShow) {
	std::cout << toShow + toShow << std::endl;
}

int main() {
	int array[] = {1, 2, 3, 4};
	std::string strArray[] = {"say", "my", "name"};

	iter(array, sizeof(array) / sizeof(int), show);
	iter(strArray, sizeof(strArray) / sizeof(std::string), show);

	iter(array, sizeof(array) / sizeof(int), showTwice);
	iter(strArray, sizeof(strArray) / sizeof(std::string), showTwice);
	return (0);
}