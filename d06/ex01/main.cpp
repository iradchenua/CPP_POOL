#include <cstdlib>
#include <iostream>
#include <ctime>

struct Data {
	std::string s1;
	int 		n;
	std::string s2;
};

void	*serialize(void) {
	size_t howManyCharsInInt =sizeof(int) / sizeof(char);
	char *data = new char[8 + howManyCharsInInt + 8]; 
	static const std::string alphanumerical \
	= "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int i = 0;

	while (i < 8) {
		data[i] = alphanumerical.at(std::rand() % alphanumerical.size());
		std::cout << data[i];
		i++;
	}
	std::cout << std::endl;
	int randInt = std::rand();
	char *intAsChar = reinterpret_cast <char *>(&randInt);
	int j = i + howManyCharsInInt;std::cout << randInt << std::endl;
	int z = 0;
	while (i < j) {
		data[i] = intAsChar[z];
		i++;
		z++;
	}
	j = i + 8;
	while (i < j) {
		data[i] = alphanumerical.at(std::rand() % alphanumerical.size());
		std::cout << data[i];
		i++;
	}
	std::cout << std::endl;
	return (reinterpret_cast<void *>(data));
}

Data * deserialize( void * raw ) {
	size_t howManyCharsInInt =sizeof(int) / sizeof(char);
	Data *data = new Data;

	char *charData = reinterpret_cast<char *>(raw);
	char *intAsChar = new char[howManyCharsInInt];
	int k;
	int i;
	int z;
	int *l;

	i = 0;
	while (i < 8) {
		data->s1.push_back(charData[i]);
		i++;
	}
	k = i + howManyCharsInInt;
	z = 0;
	while (i < k) {
		intAsChar[z] = charData[i];
		i++;
		z++;
	}
	l = reinterpret_cast<int *>(intAsChar);
	data->n = *l;

	k = i + 8;
	while (i < k) {
		data->s2.push_back(charData[i]);
		i++;
	}
	delete [] intAsChar;
	return (data);
}

int main() {
	std::srand(std::time(0));
	void *raw = serialize();
	Data *data = deserialize(raw);

	std::cout << data->s1 << std::endl;std::cout << data->n << std::endl;
	std::cout << data->s2 << std::endl;
	return (0);
}