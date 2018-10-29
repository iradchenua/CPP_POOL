#include "Close.hpp"

Close::Close() {
	this->_symbol = ']';
}

void Close::execute(std::vector<char>::iterator & it) {
	static_cast<void>(it);
}

void Close::execute(std::vector<char>::iterator & it, int & breackets, std::deque<AInstruction *>::iterator & jt, \
	std::deque<AInstruction *>::iterator const & end) {
	static_cast<void>(end);
	if (*it) {
		breackets++;
		while (breackets) {
			--jt;
			if (jt == end)
				throw std::out_of_range("not enough '['");
			if ((*jt)->isThisInstr(']'))
				breackets++;
			if ((*jt)->isThisInstr('['))
				breackets--;
			if (breackets < 0)
				throw std::out_of_range("a lot of this '['");
		}
		--jt;
	}
}

bool Close::isBreacket() {
	return (true);
}

Close::~Close() {

};

Close::Close(Close const & ai) {
	static_cast<void>(ai);

}
		
Close const & Close::operator=(const Close & ai) {
	static_cast<void>(ai);
	return (*this);
}