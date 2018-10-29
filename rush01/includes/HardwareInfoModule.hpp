//
// Created by Robert on 14.10.18.
//

#ifndef HARDWAREINFOMODULE_HPP
#define HARDWAREINFOMODULE_HPP

#include "IMonitorModule.hpp"
#include <mach/mach_types.h>
#include <mach/mach_host.h>
#include <mach/mach.h>

typedef struct {
	unsigned int system;
	unsigned int user;
	unsigned int idle;
	unsigned int nice;
}CPUUsage;

class HardwareInfoModule : public IMonitorModule {
	public:
		HardwareInfoModule();
		virtual ~HardwareInfoModule();
		void getInfo();
		const double *getCpuUsage() const;
		double getCpuFreq() const;
		const std::string &getCpuFreqString() const;
		const std::string &getCpuName() const;
		int getCpuCores() const;
		std::string const & getCpuCoresString() const;
		uint64_t getRamSize() const;
		uint64_t getRamSizeMB() const;
		uint64_t getRamUsedSize() const;
		uint64_t getRamUsedSizeMB() const;
		uint64_t getRamFreeSize() const;
		uint64_t getRamFreeSizeMB() const;

		const std::string & getRamSizeMBString() const;
		const std::string & getRamUsedMBString() const;
		const std::string & getRamFreeMBString() const;

		const std::string &getUsageUserString() const;
		const std::string &getUsageSystemString() const;
		const std::string &getUsageIdleString() const;
	private:
		HardwareInfoModule(const HardwareInfoModule &src);
		HardwareInfoModule &operator=(const HardwareInfoModule &src);
		//Variables
		double      _cpuUsage[3];
		double      _cpuFreq;
		std::string _cpuFreqString;
		std::string _cpuName;
		std::string _cpuCoresString;
		int         _cpuCores;

		uint64_t    _ramSize;
		uint64_t    _ramSizeMB;
		uint64_t    _ramUsedSize;
		uint64_t    _ramUsedSizeMB;
		uint64_t    _ramFreeSize;
		uint64_t    _ramFreeSizeMB;

		std::string    _ramSizeMBString;
		std::string    _ramUsedSizeMBString;
		std::string    _ramFreeSizeMBString;

		std::string _usageUserString;

		std::string _usageSystemString;
		std::string _usageIdleString;
};

#endif
