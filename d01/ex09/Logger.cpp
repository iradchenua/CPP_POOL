#include "Logger.hpp"

std::string Logger::makeLogEntry(std::string const & message) {
	return ("[" + Logger::_getTimestamp() + "] " + message + "\n");
}

void		Logger::logToConsole(std::string const & string) {
	std::cout << this->makeLogEntry(string);
}

void		Logger::logToFile(std::string const & string) {
	std::ofstream	file;

	file.open(this->_filename, std::ios::out | std::ios::app);
	if (file.is_open())
		file << makeLogEntry(string);
}

void	Logger::log(std::string const & dest, std::string const & message) {
	for (int i = 0; i < 2; i++)
	{
		if (Logger::_logTo[i].dest == dest)
			(this->*_logTo[i].logTo)(message);
	}
}

std::string	Logger::_getTimestamp( void )
{
	char 		buffer[80];

	struct 		tm *timeinfo;
	std::time_t time_now;
	std::string res;

	std::time(&time_now);
	timeinfo = std::localtime(&time_now);
	std::strftime(buffer, sizeof(buffer), "%Y%d%m_%s", timeinfo);
	buffer[15] = 0;
	res = buffer;
	return (res);
}

Logger::Logger(std::string const & filename) : _filename(filename) {
	return ;
}

t_logTo Logger::_logTo[] = {{"console", &Logger::logToConsole},{"file", &Logger::logToFile}};