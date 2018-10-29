#include "Sorcerer.hpp"

#ifndef VICTIM_HPP
#define VICTIM_HPP

class Victim {
	public:
		Victim(std::string const & name);
		~Victim(void);

		std::string getName(void) const;
		
		virtual void	getPolymorphed(void) const;
	private:
		Victim(Victim const & s);
		Victim(void);
		Victim & operator=(Victim const & rhs);
		
		const std::string _name;
};

std::ostream & operator<<(std::ostream & o, Victim const & v);

#endif