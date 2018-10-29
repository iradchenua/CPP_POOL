#include <iostream> 
#include <fstream>
#include <streambuf>
#include <deque>
#include <vector>
#include <string>

#ifndef IINSTRUCTION_HPP
#define IINSTRUCTION_HPP

class IInstruction {
	public:
		virtual void execute(std::vector<char>::iterator & it) = 0;
		virtual ~IInstruction() {};
};

#endif