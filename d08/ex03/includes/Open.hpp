#include "AInstruction.hpp"
#include "IInstruction.hpp"
#include "IOpenCloseInstruction.hpp"

#ifndef OPEN_HPP
#define OPEN_HPP

class Open : public AInstruction, public IOpenCloseInstruction {
	public:
		Open();

		virtual ~Open();

		
		virtual void execute(std::vector<char>::iterator & it, int & breackets, std::deque<AInstruction *>::iterator & jt, std::deque<AInstruction *>::iterator const & end);
		virtual void execute(std::vector<char>::iterator & it);

		virtual bool isBreacket();
	private:
		Open(Open const & ai);
		Open const & operator=(const Open & ai);
};

#endif