#include "AInstruction.hpp"

AInstruction::AInstruction() {

}

AInstruction::AInstruction(AInstruction const & ai) {
	static_cast<void>(ai);
}

bool AInstruction::isBreacket() {
	return (false);
}

AInstruction const & AInstruction::operator=(AInstruction const & ai) {
	static_cast<void>(ai);
	return (*this);
}

AInstruction::~AInstruction() {

}

bool AInstruction::isThisInstr(char const & instr) {
	return (this->_symbol == instr);
}
