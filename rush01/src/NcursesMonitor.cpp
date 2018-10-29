#include "NcursesMonitor.hpp"

#define ESC 27
#define BORDER 3
#define INFO 4
#define PARAM_NAME 5
#define HEADER 6
#define LOW 7
#define MIDLE 8
#define HIGH 9

void	initColorPair(int pairId, int color) {
	init_pair(pairId, color, COLOR_BLACK);
}

void	ncursesStaffInit(void) {
	initscr();
	noecho();
	cbreak();
	nodelay(stdscr, TRUE);
	keypad(stdscr, TRUE);
	curs_set(0);
	start_color();
}

void NcursesMonitor::_getTermSize() {
	if (is_term_resized(this->_h, this->_w)) {
		this->_getMaxTermSize();
	}
}

void NcursesMonitor::_getMaxTermSize() {
	int termH;
	int termW;

	getmaxyx(stdscr, termH, termW);
	this->_h = termH - 1;
	this->_w = termW - 1;
}

NcursesMonitor::NcursesMonitor(void) {

	ncursesStaffInit();

	initColorPair(BORDER, COLOR_YELLOW);
	initColorPair(INFO, COLOR_GREEN);
	initColorPair(PARAM_NAME, COLOR_RED);
    initColorPair(HEADER, COLOR_MAGENTA);
    initColorPair(LOW, COLOR_BLUE);
    initColorPair(MIDLE, COLOR_YELLOW);
    initColorPair(HIGH, COLOR_RED);

    this->_module1 = true;
    this->_module2 = true;
    this->_module3 = true;
    this->_module4 = true;

	this->_getMaxTermSize();

	this->_hToShow = 0;

	this->_borderTopDownModel = '-';
	this->_borderLeftRightModel = '|';
}

NcursesMonitor::~NcursesMonitor() {
	endwin();
}

void 	NcursesMonitor::_drawBottom(int height) const {
	attron(COLOR_PAIR(BORDER));
    for (int w = 1; w <	 this->_w; w++){
        mvaddch(height, w, this->_borderTopDownModel);
    }	
    attron(COLOR_PAIR(INFO));
}

void	NcursesMonitor::_drawBorder(void) const{
	attron(COLOR_PAIR(BORDER));

    for (int h = 0; h < this->_h; h++){
    	mvaddch(h, 0, this->_borderLeftRightModel);
		mvaddch(h, this->_w, this->_borderLeftRightModel);
    }

    for (int w = 0; w <= this->_w; w++){
        mvaddch(0, w, this->_borderTopDownModel);
    }
    this->_drawBottom(this->_h);
    mvaddch(0, this->_w, '+');
    mvaddch(this->_h, this->_w, '+');
    mvaddch(this->_h, 0, '+');
    mvaddch(0, 0, '+');
}
 
void NcursesMonitor::_putPiece(std::string piece, int offset) {
	if (offset + static_cast<int>(piece.size()) - 1 <= this->_w - 1)
		mvaddstr(this->_hToShow, offset, piece.c_str());
	else {
		if (this->_w - offset - 1 < static_cast<int>(piece.size())) {
			mvaddstr(this->_hToShow, offset, piece.substr(0, this->_w - offset - 1).c_str());
			this->_hToShow++;
			
			if (this->_w - offset - 1 > 0) {
				this->_putPiece(piece.substr(this->_w - offset - 1), 1);
			}

		}
	}
}

void NcursesMonitor::_putPercent(double percent, int offset) {
	int size = ((this->_w - offset - 1) * percent / 100);
	int midle =	(this->_w - offset) / 3;
	int high = 2 * midle;

	attron(COLOR_PAIR(LOW));
	for (int i = 0; i < size; i++) {
		if (i > high)
			attron(COLOR_PAIR(HIGH));
		else if (i > midle)
			attron(COLOR_PAIR(MIDLE));
		mvaddch(this->_hToShow, offset + i, '|');	
	}
}

void NcursesMonitor::_putInfo(std::string const & info, std::string paramName) {
	this->_hToShow++;
	attron(COLOR_PAIR(PARAM_NAME));
	this->_putPiece(paramName, 1);
	attron(COLOR_PAIR(INFO));
	this->_putPiece(info, 1 + paramName.size());

};

void NcursesMonitor::_putHeader(std::string name) {
	this->_hToShow++;

	attron(COLOR_PAIR(HEADER));
	this->_putPiece(name, (this->_w) / 2 - 4);
	attron(COLOR_PAIR(HEADER));
}

void NcursesMonitor::_showModule1() {
	this->_putHeader("HOST INFO");
	this->_putInfo(this->_hostModule.getHostname(), "host name: ");
	this->_putInfo(this->_hostModule.getUsername(), "user name: ");
	this->_putInfo(this->_hostModule.getKernelVersion(), "kernel version: ");
	this->_putInfo(this->_hostModule.getOsVersion(), "os version: ");
	this->_putInfo(this->_hostModule.getDateTime(), "date: ");

}

void NcursesMonitor::_showModule2() {
	this->_putHeader("HARD INFO");
	this->_putInfo(this->_hardwareModule.getCpuName(), "cpu name: ");
	this->_putInfo(this->_hardwareModule.getCpuCoresString(), "cores: ");
	this->_putInfo(this->_hardwareModule.getCpuFreqString() + " Hz", "freq: ");
	this->_hardwareModule.getInfo();
	this->_putInfo(this->_hardwareModule.getUsageUserString() + "%", "user usage: ");
	int offset = this->_hardwareModule.getUsageUserString().size() + 15;
	this->_putPercent(this->_hardwareModule.getCpuUsage()[0], offset);
	this->_putInfo(this->_hardwareModule.getUsageSystemString() + "%", "system usage: ");
	offset = this->_hardwareModule.getUsageSystemString().size() + 15;
	this->_putPercent(this->_hardwareModule.getCpuUsage()[1], offset);

	this->_putInfo(this->_hardwareModule.getUsageIdleString() + "%", "idle usage: ");
	offset = this->_hardwareModule.getUsageIdleString().size() + 15;
	this->_putPercent(this->_hardwareModule.getCpuUsage()[2], offset);

	this->_putInfo(this->_hardwareModule.getRamSizeMBString() + " MB", "RAM: ");

	this->_putInfo(this->_hardwareModule.getRamUsedMBString() + " MB", "USED RAM: ");

	offset = this->_hardwareModule.getRamUsedMBString().size() + 15;
	
	double percent = (static_cast<double>(this->_hardwareModule.getRamUsedSize()) / static_cast<double>(this->_hardwareModule.getRamSize())) * 100;

	this->_putPercent(percent, offset); 


	this->_putInfo(this->_hardwareModule.getRamFreeMBString() + " MB", "FREE RAM: ");
	offset = this->_hardwareModule.getRamUsedMBString().size() + 15;
	percent = (static_cast<double>(this->_hardwareModule.getRamFreeSize()) / static_cast<double>(this->_hardwareModule.getRamSize())) * 100;
	this->_putPercent(percent, offset); 
	
}

void NcursesMonitor::_showModule3() {
	this->_putHeader("NETWORK INFO");
	this->_networkModule.refreshStat();
	this->_putInfo(this->_networkModule.getDownloadSpeedString() + " Kb/s", "download speed: ");
	this->_putInfo(this->_networkModule.getUploadSpeedString() + " Kb/s", "upload speed: ");
	this->_putInfo(this->_networkModule.getDownloadedMBytesString() + " Mb", "total downloaded: ");
	this->_putInfo(this->_networkModule.getUploadedMBytesString() + " Mb", "total uploaded: ");
}

void NcursesMonitor::_showModule4() {
	this->_putHeader("CAT");
	this->_putInfo("                            | \\", " ");
    this->_putInfo("                            | |", " ");
    this->_putInfo("                            | |", " ");
    this->_putInfo("       |\\                   | |", " ");
    this->_putInfo("      /, ~\\                / /", " ");
    this->_putInfo("     X     `-.....-------./ /", " ");
    this->_putInfo("      ~-. ~  ~              |", " ");
    this->_putInfo("         \\             /    |", " ");
    this->_putInfo("          \\  /_     ___\\   /", " ");
    this->_putInfo("          | /\\ ~~~~~   \\ |", " ");
    this->_putInfo("          | | \\        || |", " ");
    this->_putInfo("          | |\\ \\       || )", " ");
    this->_putInfo("         (_/ (_/      ((_/", " ");
}	

void NcursesMonitor::show() {
	int key;

	while ((key = getch()) != ESC) {
		erase();
		if (key == '1')
			this->_module1 = !this->_module1;
		if (key == '2')
			this->_module2 = !this->_module2;
		if (key == '3')
			this->_module3 = !this->_module3;
		if (key == '4')
			this->_module4 = !this->_module4;
		this->_tick();
		refresh();
		this->_getTermSize();
	}
}

void NcursesMonitor::_tick(void) {
	this->_drawBorder();
	attron(COLOR_PAIR(INFO));
	if (this->_module1) {
		this->_showModule1();
		this->_hToShow++;
		this->_drawBottom(this->_hToShow);
	}
    
    if (this->_module2) {
		this->_showModule2();
		this->_hToShow++;
	    this->_drawBottom(this->_hToShow);
	}

	if (this->_module3) {
	    this->_showModule3();
	    this->_hToShow++;
	    this->_drawBottom(this->_hToShow);
	}
	if(this->_module4) {
    	this->_showModule4();
	}
	this->_hToShow = 0;
}


NcursesMonitor & NcursesMonitor::operator=(NcursesMonitor const & NcursesMonitor) {
	static_cast<void>(NcursesMonitor);
	return (*this);
}

NcursesMonitor::NcursesMonitor(NcursesMonitor const & NcursesMonitor) {
	static_cast<void>(NcursesMonitor);
}