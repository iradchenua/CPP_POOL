#include <iostream>
#include <fstream>
#include <string>

void error(std::string message) {

	std::cout << message << std::endl;
	exit (1);
}

std::string replace_empty(std::string line, std::string str1, std::string str2) {

	std::string buff;
	std::size_t len;
	std::size_t pos;
	std::size_t step;

	step =  str2.length() + 1;
	pos = 0;
	len = (line.length() - 1) * str2.length() + str1.length();
	while (pos < len)
	{
		buff = line.substr(pos, 1);
		buff.append(str2);
		line.replace(pos, 1, buff);
		pos += step;
	}
	return (line);

}

std::string replace_in_line(std::string line, std::string str1, std::string str2) {
	std::size_t pos;

	if (!str1.length())
		return (replace_empty(line, str1, str2));
	pos = line.find(str1);
	while (pos != std::string::npos)
	{
		line.replace(pos,str1.length(),str2);
		pos = line.find(str1, pos + str2.length());
	}
	return (line);
}

int main(int ac, char **av) {

	if (ac < 4)
		error("expected 3 arguments: filename str1 str2");
	std::ifstream ifs(av[1]);
	std::string		str1;
	std::string		str2;
	std::string 	new_file;

	if (!ifs)
		error("Can't open file.");
	new_file = av[1];
	new_file.append(".replace");
	str1 = av[2];
	str2 = av[3];
	std::ofstream ofs(new_file);
	for (std::string line; std::getline(ifs, line);)
	{	
		if (ifs.bad())
			error("can't read file");
		if (!ifs.eof())
			line.append("\n");
		ofs << replace_in_line(line, str1, str2);

	}
	return (0);
}