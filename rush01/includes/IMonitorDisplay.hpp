#include "HostInfoModule.hpp"
#include "HardwareInfoModule.hpp"
#include "NetworkInfoModule.hpp"

#ifndef I_MONITOR_DISPLAY_HPP
#define I_MONITOR_DISPLAY_HPP

class IMonitorDisplay {
	public:
		virtual ~IMonitorDisplay(void) {};

		virtual void 	_tick(void) = 0;
		virtual void 	show(void) = 0;
		virtual void	_putHeader(std::string name) = 0;

		virtual void	_drawBorder(void) const = 0;
		virtual void 	_drawBottom(int height) const = 0;

		virtual void 	_showModule1() = 0;
		virtual void 	_showModule2() = 0;
		virtual void 	_showModule3() = 0;
		virtual void 	_showModule4() = 0;

		virtual void 	_putInfo(std::string const & info, std::string paramName) = 0;
};

#endif

