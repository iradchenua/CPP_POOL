#include "IInstruction.hpp"
#include <stdexcept>

#ifndef AINSTRUCTION_HPP
#define AINSTRUCTION_HPP

class AInstruction : public IInstruction {
	public:
		AInstruction();
		bool isThisInstr(char const & instr);
		
		virtual ~AInstruction();

		virtual bool isBreacket();
	protected:
		char _symbol;
	private:
		AInstruction(AInstruction const & ai);
		AInstruction const & operator=(AInstruction const & ai);
};
#endif