#include <string>
#include <iostream>

#ifndef SORCERS_HPP
#define SORCERS_HPP

#include "Victim.hpp"

class Sorcerer {
	public:
		Sorcerer(std::string const & name, std::string const & title);
		~Sorcerer(void);

		std::string getName(void) const;
		std::string getTitle(void) const;
		
		void	polymorph(Victim const & v) const;
	private:
		Sorcerer(Sorcerer const & s);
		Sorcerer(void);
		Sorcerer & operator=(Sorcerer const & rhs);

		const std::string _name;
		const std::string _title;
};

std::ostream & operator<<(std::ostream & o, Sorcerer const & s);

#endif