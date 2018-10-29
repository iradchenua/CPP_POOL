//
// Created by Robert on 14.10.18.
//


#include "HardwareInfoModule.hpp"

HardwareInfoModule::HardwareInfoModule() {
	getInfo();

	//Processor name
	char   buf[128];
	size_t len = sizeof(buf);
	sysctlbyname("machdep.cpu.brand_string", &buf, &len, NULL, 0);
	_cpuName = std::string(buf);

	// number of cores
	len = sizeof(_cpuCores);
	sysctlbyname("hw.physicalcpu", &_cpuCores, &len, NULL, 0);
	std::ostringstream strm;

	strm << _cpuCores;
	_cpuCoresString = strm.str();
	strm.str(std::string());
	//size of RAM
	len = sizeof(_ramSize);
	sysctlbyname("hw.memsize", &_ramSize, &len, NULL, 0);
	_ramSizeMB = (_ramSize >> 20);
}

HardwareInfoModule::~HardwareInfoModule() {
}

//CPU Frequency vendor code
static uint64_t rdtsc(void) {
	uint32_t ret0[2];
	__asm__ __volatile__("rdtsc" : "=a"(ret0[0]), "=d"(ret0[1]));
	return ((uint64_t)ret0[1] << 32) | ret0[0];
}

static void getData(CPUUsage &data) {
	mach_msg_type_name_t      count;
	host_cpu_load_info_data_t cpuLoadInfo = {};
	count = HOST_CPU_LOAD_INFO_COUNT;
	host_statistics(mach_host_self(), HOST_CPU_LOAD_INFO,
					reinterpret_cast<host_info_t>(&cpuLoadInfo), &count);
	data.user   = cpuLoadInfo.cpu_ticks[CPU_STATE_USER];
	data.system = cpuLoadInfo.cpu_ticks[CPU_STATE_SYSTEM];
	data.idle   = cpuLoadInfo.cpu_ticks[CPU_STATE_IDLE];
}

void HardwareInfoModule::getInfo() {
//==========================================================================
	//							GET CPU USAGE, FREQ (refreshable)
	//==========================================================================
	CPUUsage           one    = {};
	CPUUsage           two    = {};
	CPUUsage           result = {};
	std::ostringstream strm;
	//Calculate usage and frequency by 1 sec
	getData(one);
	uint64_t s = rdtsc();
	sleep(1);
	uint64_t e = rdtsc();
	getData(two);

	result.user   = two.user - one.user;
	result.system = two.system - one.system;
	result.idle   = two.idle - one.idle;

	_cpuFreq = ((e - s) / 1000000000.0);
	strm << _cpuFreq;
	_cpuFreqString = strm.str();
	strm.str(std::string());
	if (_cpuFreqString.size() > 4) {
		_cpuFreqString.erase(4, 5);
	}

	uint64_t total = result.user + result.system + result.idle;

	double onePercent = total / 100.0f;

	_cpuUsage[0] = static_cast<double >(result.user) / onePercent;
	_cpuUsage[1] = static_cast<double >(result.system) / onePercent;
	_cpuUsage[2] = static_cast<double >(result.idle) / onePercent;

	strm << _cpuUsage[0];
	_usageUserString = strm.str();
	strm.str(std::string());
	if (_usageUserString.size() > 4) {
		_usageUserString.erase(4, 5);
	}

	strm << _cpuUsage[1];
	_usageSystemString = strm.str();
	strm.str(std::string());
	if (_usageSystemString.size() > 4) {
		_usageSystemString.erase(4, 5);
	}

	strm << _cpuUsage[2];
	_usageIdleString                = strm.str();
	strm.str(std::string());
	if (_usageIdleString.size() > 4) {
		_usageIdleString.erase(4, 5);
	}
	//==========================================================================
	//							GET RAM USAGE
	//==========================================================================
	vm_size_t              page_size;
	mach_port_t            mach_port;
	mach_msg_type_number_t count;
	vm_statistics64_data_t vm_stats = {};

	mach_port = mach_host_self();
	count     = sizeof(vm_stats) / sizeof(natural_t);
	host_page_size(mach_port, &page_size);
	host_statistics64(mach_port, HOST_VM_INFO,
					  reinterpret_cast<host_info64_t>(&vm_stats), &count);
	_ramUsedSize   = ((vm_stats.active_count + vm_stats.inactive_count
		+ vm_stats.wire_count) * page_size);
	_ramFreeSize   = _ramSize - _ramUsedSize;
	_ramUsedSizeMB = (_ramUsedSize >> 20);
	_ramFreeSizeMB = (_ramFreeSize >> 20);

	strm << _ramSizeMB;
	_ramSizeMBString = strm.str();	
	strm.str(std::string());

	strm << _ramUsedSizeMB;
	_ramUsedSizeMBString = strm.str();	
	strm.str(std::string());

	strm << _ramFreeSizeMB;
	_ramFreeSizeMBString = strm.str();	
	strm.str(std::string());
}

HardwareInfoModule::HardwareInfoModule(const HardwareInfoModule &src) {
	*this = src;
}

HardwareInfoModule &HardwareInfoModule::operator=(const HardwareInfoModule &src) {
	if (this != &src) {
		this->_ramSize           = src._ramSize;
		this->_ramSizeMB         = src._ramSizeMB;
		this->_ramFreeSize       = src._ramFreeSize;
		this->_ramFreeSizeMB     = src._ramFreeSizeMB;
		this->_ramUsedSize       = src._ramUsedSize;
		this->_ramUsedSizeMB     = src._ramUsedSizeMB;
		this->_cpuCores          = src._cpuCores;
		this->_cpuName           = src._cpuName;
		this->_cpuFreqString     = src._cpuFreqString;
		this->_usageIdleString   = src._usageIdleString;
		this->_usageSystemString = src._usageSystemString;
		this->_usageUserString   = src._usageUserString;
		this->_cpuFreq           = src._cpuFreq;
	}
	return *this;
}

const double *HardwareInfoModule::getCpuUsage() const {
	return _cpuUsage;
}

double HardwareInfoModule::getCpuFreq() const {
	return _cpuFreq;
}

const std::string &HardwareInfoModule::getCpuFreqString() const {
	return _cpuFreqString;
}

const std::string &HardwareInfoModule::getCpuName() const {
	return _cpuName;
}

int HardwareInfoModule::getCpuCores() const {
	return _cpuCores;
}

std::string const & HardwareInfoModule::getCpuCoresString() const {
	return _cpuCoresString;
}

uint64_t HardwareInfoModule::getRamSize() const {
	return _ramSize;
}

const std::string & HardwareInfoModule::getRamSizeMBString() const {
	return _ramSizeMBString;
}

const std::string & HardwareInfoModule::getRamUsedMBString() const {
	return _ramUsedSizeMBString;
}

const std::string & HardwareInfoModule::getRamFreeMBString() const {
	return _ramFreeSizeMBString;
}

uint64_t HardwareInfoModule::getRamSizeMB() const {
	return _ramSizeMB;
}

uint64_t HardwareInfoModule::getRamUsedSize() const {
	return _ramUsedSize;
}

uint64_t HardwareInfoModule::getRamUsedSizeMB() const {
	return _ramUsedSizeMB;
}

uint64_t HardwareInfoModule::getRamFreeSize() const {
	return _ramFreeSize;
}

uint64_t HardwareInfoModule::getRamFreeSizeMB() const {
	return _ramFreeSizeMB;
}

const std::string &HardwareInfoModule::getUsageUserString() const {
	return _usageUserString;
}

const std::string &HardwareInfoModule::getUsageSystemString() const {
	return _usageSystemString;
}

const std::string &HardwareInfoModule::getUsageIdleString() const {
	return _usageIdleString;
}

