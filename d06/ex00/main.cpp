#include "Type.hpp"

//#include <stdexcept>

int main(int ac, char **argv) {
	if (ac != 2)
		return (1);
	Type type = Type(std::string(argv[1]));
	char c_value = static_cast<char>(type);
	float f_value = static_cast<float>(type);
	double d_value = static_cast<double>(type);
	int i_value = static_cast<int>(type);

	std::cout << "char: ";
	if (!type.getPossibleChar())
		std::cout << "impossible" << std::endl;
	else if (isprint(c_value))
		std::cout << "'" << c_value << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;

	std::cout << "int: ";
	if (!type.getPossibleInt())
		std::cout << "impossible" << std::endl;
	else
		std::cout << i_value << std::endl;

	std::cout.precision(1);
	std::cout << std::fixed;

	std::cout << "float: ";
	if (!type.getPossibleFloat())
		std::cout << "impossible" << std::endl;
	else {
		std::cout << f_value << "f" << std::endl;
	}

	
	std::cout << "double: ";
	if (!type.getPossibleFloat())
		std::cout << "impossible" << std::endl;
	else {
		std::cout << d_value << std::endl;
	}

	return (0);
}