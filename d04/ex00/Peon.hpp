#include "Victim.hpp"

#ifndef PEON_HPP
#define PEON_HPP

class Peon : public Victim {
	public:
		Peon(std::string const & name);
		~Peon(void);

		std::string getName(void) const;
		
		void	getPolymorphed(void) const;
	private:
		Peon(Peon const & s);
		Peon(void);
		Peon & operator=(Peon const & rhs);
		
		const std::string _name;
};

#endif