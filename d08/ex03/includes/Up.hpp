#include "AInstruction.hpp"
#include "IInstruction.hpp"

#ifndef UP_HPP
#define UP_HPP

class Up : public AInstruction {
	public:
		Up();

		virtual ~Up();

		virtual void execute(std::vector<char>::iterator & it);
	private:
		Up(Up const & ai);
		Up const & operator=(const Up & ai);
};

#endif