#include "AInstruction.hpp"
#include "IInstruction.hpp"

#ifndef SHOW_HPP
#define SHOW_HPP

class Show : public AInstruction {
	public:
		Show();

		virtual ~Show();

		virtual void execute(std::vector<char>::iterator & it);
	private:
		Show(Show const & ai);
		Show const & operator=(const Show & ai);
};

#endif