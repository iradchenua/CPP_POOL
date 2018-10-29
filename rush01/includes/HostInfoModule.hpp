//
// Created by Robert on 14.10.18.
//

#ifndef HOSTINFOMODULE_HPP
#define HOSTINFOMODULE_HPP

#include "IMonitorModule.hpp"
#include <iomanip>
#include <sstream>
#include <unistd.h>

class HostInfoModule : public IMonitorModule {
	public:
		HostInfoModule();
		virtual ~HostInfoModule();
		const std::string &getDateTime();  //refreshable
		const std::string &getHostname() const;
		const std::string &getUsername() const;
		const std::string &getKernelVersion() const;
		const std::string &getOsVersion() const;
	private:
		HostInfoModule(const HostInfoModule &src);
		HostInfoModule &operator=(const HostInfoModule &src);
		void getInfo();
		//Variables
		std::string _dateTime;
		std::string _hostname;
		std::string _username;
		std::string _kernelVersion;
		std::string _osVersion;
};

#endif
