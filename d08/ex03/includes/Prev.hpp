#include "AInstruction.hpp"
#include "IInstruction.hpp"

#ifndef PREV_HPP
#define PREV_HPP

class Prev : public AInstruction {
	public:
		Prev();

		virtual ~Prev();

		virtual void execute(std::vector<char>::iterator & it);
	private:
		Prev(Prev const & ai);
		Prev const & operator=(const Prev & ai);
};

#endif