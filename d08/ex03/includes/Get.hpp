#include "AInstruction.hpp"
#include "IInstruction.hpp"

#ifndef GET_HPP
#define GET_HPP

class Get : public AInstruction {
	public:
		Get();

		virtual ~Get();

		virtual void execute(std::vector<char>::iterator & it);
	private:
		Get(Get const & ai);
		Get const & operator=(const Get & ai);
};

#endif