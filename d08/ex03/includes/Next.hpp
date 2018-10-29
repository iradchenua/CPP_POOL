#include "AInstruction.hpp"
#include "IInstruction.hpp"

#ifndef NEXT_HPP
#define NEXT_HPP

class Next : public AInstruction {
	public:
		Next();

		virtual ~Next();

		virtual void execute(std::vector<char>::iterator & it);
	private:
		Next(Next const & ai);
		Next const & operator=(const Next & ai);
};

#endif