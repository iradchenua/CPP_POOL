#include <iostream>
#include <string>

#ifndef PONY_HPP
# define PONY_HPP

class Pony {
	public: 
		Pony(std::string color, std::string name, std::string loc);
		~Pony(void);
		void		greeting(void);
		std::string getName(void);
		std::string getColor(void);
	private:
		std::string _loc;
		std::string _color;
		std::string _name;		
};

#endif