#include <string>
#include <iostream>
#include <fstream>

#ifndef LOGGER_HPP
#define LOGGER_HPP

typedef struct 	s_logTo t_logTo;

class Logger
{
	public:
		void		log(std::string const & dest, std::string const & message);
		Logger(std::string const & filename);
	private:
		static std::string			_getTimestamp( void );
		void						logToConsole(std::string const & string);
		void						logToFile(std::string const & string);
		std::string 				makeLogEntry(std::string const & message);
		
		std::string _filename;
		static 	t_logTo _logTo[];

};

typedef struct 	s_logTo
{
	std::string dest;	
	void	(Logger::*logTo)(std::string const &);
}				t_logTo;

#endif