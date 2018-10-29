#include "AInstruction.hpp"
#include "IInstruction.hpp"

#ifndef DOWN_HPP
#define DOWN_HPP

class Down : public AInstruction {
	public:
		Down();

		virtual ~Down();

		virtual void execute(std::vector<char>::iterator & it);
	private:
		Down(Down const & ai);
		Down const & operator=(const Down & ai);
};

#endif