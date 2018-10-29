#include "Open.hpp"

Open::Open() {
	this->_symbol = '[';
}

void Open::execute(std::vector<char>::iterator & it) {
	static_cast<void>(it);
}
bool Open::isBreacket() {
	return (true);
}

void Open::execute(std::vector<char>::iterator & it, int & breackets, std::deque<AInstruction *>::iterator & jt, \
	std::deque<AInstruction *>::iterator const & end) {
	if (!(*it)) {
		++breackets;
		while(breackets) {
			jt++;
			if (jt == end)
				throw std::out_of_range("not enough ']'");
			if ((*jt)->isThisInstr('['))
				++breackets;
			if ((*jt)->isThisInstr(']'))
				--breackets;
			if (breackets < 0)
				throw std::out_of_range("a lot of this ']'");
		}
			
	}

}

Open::~Open() {

};

Open::Open(Open const & ai) {
	static_cast<void>(ai);

}
		
Open const & Open::operator=(const Open & ai) {
	static_cast<void>(ai);
	return (*this);
}