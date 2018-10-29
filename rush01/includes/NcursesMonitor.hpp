#include <ncurses.h>

#include "IMonitorDisplay.hpp"

#ifndef NCURSES_MONITOR_CLASS_HPP
#define NCURSES_MONITOR_CLASS_HPP

class NcursesMonitor : public IMonitorDisplay {
	public:
		NcursesMonitor(void);

		virtual ~NcursesMonitor(void);

		void 		show(void);

	private:
		bool _module1;
		bool _module2;
		bool _module3;
		bool _module4;
		
		NcursesMonitor(NcursesMonitor const & NcursesMonitor);

		NcursesMonitor & operator=(NcursesMonitor const & NcursesMonitor);

		void 	_tick(void);
		void 	_putPiece(std::string piece, int offset);
		void	_putHeader(std::string name);
		void 	_drawBottom(int height) const;

		void 	_putPercent(double percent, int offset);

		void	_getTermSize();
		void	_getMaxTermSize();

		void 	_showModule1();
		void 	_showModule2();
		void 	_showModule3();
		void 	_showModule4();


		void	_drawBorder(void) const;
		void 	_putInfo(std::string const & info, std::string paramName);

		char 			_borderTopDownModel;
		char 			_borderLeftRightModel;	
		int 			_w;
		int 			_h;
		int 			_hToShow;

		HostInfoModule _hostModule;
		HardwareInfoModule _hardwareModule;
		NetworkInfoModule _networkModule;
};

#endif

