//
// Created by Robert on 14.10.18.
//


#include "HostInfoModule.hpp"
#include <fstream>

HostInfoModule::HostInfoModule() {
	getInfo();
}

HostInfoModule::~HostInfoModule() {

}

HostInfoModule::HostInfoModule(const HostInfoModule &src) {
	*this = src;
}

HostInfoModule &HostInfoModule::operator=(const HostInfoModule &src) {
	if (this != &src) {
		this->_osVersion     = src._osVersion;
		this->_kernelVersion = src._kernelVersion;
		this->_hostname      = src._hostname;
		this->_dateTime      = src._dateTime;
		this->_username      = src._username;
	}
	return *this;
}

void HostInfoModule::getInfo() {
	//Hostname
	char   buf[128];
	int    name[2] = {CTL_KERN, KERN_HOSTNAME};
	size_t len     = sizeof(buf);
	sysctl(name, 2, &buf, &len, NULL, 0);
	_hostname = std::string(buf);

	//Username
	_username     = std::string(getlogin());

	//Kernel version
	char buf2[128];
	int  name2[2] = {CTL_KERN, KERN_VERSION};
	len = sizeof(buf2);
	sysctl(name2, 2, &buf2, &len, NULL, 0);
	_kernelVersion = std::string(buf2);

	//OSVersion
	char buf3[128];
	len = sizeof(buf3);
	sysctlbyname("kern.osproductversion", &buf3, &len, NULL, 0);
	system("sw_vers | sed -n 2p | cut -f2 > file");
	std::ifstream infile("file");
	std::string line;
	std::getline(infile, line);
	_osVersion = line;
	system("rm file");
}

const std::string &HostInfoModule::getDateTime() {
	//Date/Time
	std::time_t       t = std::time(nullptr);
	std::stringstream stringbBuf;
	stringbBuf << std::put_time(std::localtime(&t), "%d.%m.%Y %H:%M:%S");
	this->_dateTime = stringbBuf.str();
	return _dateTime;
}

const std::string &HostInfoModule::getHostname() const {
	return _hostname;
}

const std::string &HostInfoModule::getUsername() const {
	return _username;
}

const std::string &HostInfoModule::getKernelVersion() const {
	return _kernelVersion;
}

const std::string &HostInfoModule::getOsVersion() const {
	return _osVersion;
}
