#include <iostream>
#include <fstream>
#include <string>
#include <sys/stat.h>

void message(std::string message) {

	std::cout << message << std::endl;
}

void cat_file(std::string filename) {
	std::ifstream ifs(filename);
	struct stat buf;
	stat(filename.c_str(), &buf);

	if (S_ISDIR(buf.st_mode))
	{
		message("cat: " + filename + ":" + \
			" Is a directory");
		return ;
	}
	if (!ifs)
	{
		message("cat: " + filename + ":" + \
			" No such file or directory");
		return ;
	}
	for (std::string line; std::getline(ifs, line);)
	{	
		if (ifs.bad())
			message("can't read file");
		std::cout << line;
		if (!ifs.eof())
			std::cout << std::endl;
	}
}

void	do_like_me(void) {
	std::string line;

	while (std::cin) {
		std::getline(std::cin, line);
		if (errno == EINTR)
		{
			message("cat: stdin: Interrputed system call");
			exit(1);
		}
		message(line);
	}
}

int main(int ac, char **av) {
	std::string line;

	if (ac < 2)
		do_like_me();
	for (int i = 1; i < ac; i++)
		cat_file(av[i]);
	return (0);
}
