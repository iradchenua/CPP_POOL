#include <iostream> 
#include <fstream>
#include <streambuf>
#include <deque>
#include <vector>
#include <string>

#ifndef I_OPEN_CLOSE_INSTRUCTION_INSTRUCTION_HPP
#define I_OPEN_CLOSE_INSTRUCTION_INSTRUCTION_HPP

class IOpenCloseInstruction {
	public:
		virtual void execute(std::vector<char>::iterator & it, int & breackets, std::deque<AInstruction *>::iterator & jt, \
			
			std::deque<AInstruction *>::iterator const & end) = 0;
		virtual ~IOpenCloseInstruction() {};
};

#endif