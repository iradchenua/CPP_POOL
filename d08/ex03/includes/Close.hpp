#include "AInstruction.hpp"
#include "IInstruction.hpp"
#include "IOpenCloseInstruction.hpp"

#ifndef CLOSE_HPP
#define CLOSE_HPP

class Close : public AInstruction, public IOpenCloseInstruction  {
	public:
		Close();

		virtual ~Close();

		virtual bool isBreacket();

		virtual void execute(std::vector<char>::iterator & it, int & breackets, std::deque<AInstruction *>::iterator & jt, std::deque<AInstruction *>::iterator const & end);

		virtual void execute(std::vector<char>::iterator & it);
	private:
		Close(Close const & ai);
		Close const & operator=(const Close & ai);
};

#endif