//
// Created by Robert on 14.10.18.
//


#include "NetworkInfoModule.hpp"

NetworkInfoModule::NetworkInfoModule() {
	getInfo();
}

NetworkInfoModule::~NetworkInfoModule() {

}

NetworkInfoModule::NetworkInfoModule(const NetworkInfoModule &src) {
	*this = src;
}

NetworkInfoModule &NetworkInfoModule::operator=(const NetworkInfoModule &src) {
	if (this != &src) {
		this->_uploadedBytes          = src._uploadedBytes;
		this->_downloadedBytes        = src._downloadedBytes;
		this->_uploadedMBytes         = src._uploadedMBytes;
		this->_downloadedMBytes       = src._downloadedMBytes;
		this->_uploadSpeed            = src._uploadSpeed;
		this->_downloadSpeed          = src._downloadSpeed;
		this->_uploadSpeedMb          = src._uploadSpeedMb;
		this->_downloadSpeedMb        = src._downloadSpeedMb;
		this->_uploadedMBytesString   = src._uploadedMBytesString;
		this->_downloadedMBytesString = src._downloadedMBytesString;
	}
	return *this;
}

void NetworkInfoModule::getInfo() {
	int                mib[] = {CTL_NET, PF_ROUTE, 0, 0, NET_RT_IFLIST2, 0};
	std::ostringstream strm;

	size_t len;
	char   *buf, *limit, *next;
	//check len
	sysctl(mib, 6, NULL, &len, NULL, 0);
	//make buffer
	buf = (char *)malloc(len);
	sysctl(mib, 6, buf, &len, NULL, 0);
	limit             = buf + len;
	//reset old
	_downloadedBytes  = 0;
	_uploadedBytes    = 0;
	for (next         = buf; next < limit;) {
		struct if_msghdr *ifm = reinterpret_cast<struct if_msghdr *>(next);
		next += ifm->ifm_msglen;
		if (ifm->ifm_type == RTM_IFINFO2) {
			struct if_msghdr2
				*if2m = reinterpret_cast<struct if_msghdr2 *>(ifm);
			_downloadedBytes += if2m->ifm_data.ifi_ibytes;
			_uploadedBytes += if2m->ifm_data.ifi_obytes;
		}
	}
	//convert to MB
	_downloadedMBytes = _downloadedBytes / 1024 / 1024;
	_uploadedMBytes   = _uploadedBytes / 1024 / 1024;

	strm << _downloadedMBytes;
	_downloadedMBytesString = strm.str();
	strm.str(std::string());

	strm << _uploadedMBytes;
	_uploadedMBytesString = strm.str();
	strm.str(std::string());

	free(buf);
}

void NetworkInfoModule::refreshStat() {
	getInfo();
	uint64_t sd = getDownloadedBytes();
	uint64_t su = getUploadedBytes();
	sleep(1);
	getInfo();
	uint64_t ed = getDownloadedBytes();
	uint64_t eu = getUploadedBytes();

	_downloadSpeed   = ((ed - sd) / 1000.0);
	_uploadSpeed     = ((eu - su) / 1000.0);
	_downloadSpeedMb = _downloadSpeed / 1000.0;
	_uploadSpeedMb   = _uploadSpeed / 1000.0;

	std::ostringstream strm;

	strm << _downloadSpeed;
	_downloadSpeedString = strm.str();
	strm.str(std::string());
	if (_downloadSpeedString.size() > 5) {
		_downloadSpeedString.erase(5, 5);
	}

	strm << _uploadSpeed;
	_uploadSpeedString = strm.str();
	strm.str(std::string());
	if (_uploadSpeedString.size() > 5) {
		_uploadSpeedString.erase(5, 5);
	}
}

std::string const & NetworkInfoModule::getDownloadSpeedString() const {
	return _downloadSpeedString;
}
std::string const & NetworkInfoModule::getUploadSpeedString() const {
	return _uploadSpeedString;
}

uint64_t NetworkInfoModule::getUploadedBytes() const {
	return _uploadedBytes;
}

uint64_t NetworkInfoModule::getDownloadedBytes() const {
	return _downloadedBytes;
}

double NetworkInfoModule::getUploadedMBytes() const {
	return _uploadedMBytes;
}

double NetworkInfoModule::getDownloadedMBytes() const {
	return _downloadedMBytes;
}

const std::string &NetworkInfoModule::getUploadedMBytesString() const {
	return _uploadedMBytesString;
}

const std::string &NetworkInfoModule::getDownloadedMBytesString() const {
	return _downloadedMBytesString;
}

double NetworkInfoModule::getDownloadSpeed() {
	return _downloadSpeed;
}

double NetworkInfoModule::getUploadSpeed() {
	return _uploadSpeed;
}

double NetworkInfoModule::getDownloadSpeedMb() {
	return _downloadSpeedMb;
}

double NetworkInfoModule::getUploadSpeedMb() {
	return _uploadSpeedMb;
}