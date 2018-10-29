//
// Created by Robert on 14.10.18.
//

#ifndef NETWORKINFOMODULE_HPP
#define NETWORKINFOMODULE_HPP

#include "IMonitorModule.hpp"
#include <sys/socket.h>
#include <net/if.h>
#include <net/route.h>
class NetworkInfoModule : public IMonitorModule{
	public:
		NetworkInfoModule();
		virtual ~NetworkInfoModule();

		uint64_t getUploadedBytes() const;
		uint64_t getDownloadedBytes() const;
		double getUploadedMBytes() const;
		double getDownloadedMBytes() const;
		const std::string &getUploadedMBytesString() const;
		const std::string &getDownloadedMBytesString() const;
		double getDownloadSpeed();
		double getUploadSpeed();

		std::string const & getDownloadSpeedString() const;
		std::string const & getUploadSpeedString() const;

		double getDownloadSpeedMb();
		double getUploadSpeedMb();
		void	refreshStat();

	private:		
		NetworkInfoModule(const NetworkInfoModule &src);
		NetworkInfoModule &operator=(const NetworkInfoModule &src);
		void getInfo();
		uint64_t _uploadedBytes;
		uint64_t _downloadedBytes;
		uint64_t _uploadedMBytes;
		uint64_t _downloadedMBytes;
		double _uploadSpeed;
		double _downloadSpeed;

		std::string _uploadSpeedString;
		std::string _downloadSpeedString;

		double _uploadSpeedMb;
		double _downloadSpeedMb;
		std::string _uploadedMBytesString;
		std::string _downloadedMBytesString;
};

#endif
