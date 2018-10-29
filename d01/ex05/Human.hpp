#include "Brain.hpp"

#ifndef HUMAN_HPP
#define HUMAN_HPP

class Human {
	public:
		Human(void);
		~Human(void);
		Brain 	const & getBrain(void);
		std::string identify(void) const;
	private:
		Brain const _brain;
};

#endif