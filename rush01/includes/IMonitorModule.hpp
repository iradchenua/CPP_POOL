//
// Created by Robert KOVAL on 12.10.2018.
//

#ifndef IMONITORMODULE_HPP
#define IMONITORMODULE_HPP

#include <sys/sysctl.h>
#include <unistd.h>
#include <string>
#include <sstream>
#include <iostream>

class IMonitorModule {
	public:
		virtual ~IMonitorModule(void) {};
		virtual void getInfo() = 0;
};

#endif
