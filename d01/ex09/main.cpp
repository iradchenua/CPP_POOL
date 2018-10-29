#include "Logger.hpp"

int main(void)
{
	Logger logger = Logger("log");

	std::string	dest[2] = {"console", "file"};

	for (int i = 0; i < 2; i++) {
		logger.log(dest[i], "looooog");
	}
	return (0);
}