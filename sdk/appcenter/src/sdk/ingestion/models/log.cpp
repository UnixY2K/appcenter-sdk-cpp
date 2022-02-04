#include "appcenter/sdk/ingestion/device.hpp"
#include <appcenter/sdk/ingestion/models/log.hpp>
#include <appcenter/util/Date.hpp>
#include <string_view>

namespace appcenter::sdk::ingestion::model {
const util::Date &Log::getTimestamp() const { return timestamp; }
void Log::setTimestamp(const util::Date &timestamp) {
	this->timestamp = timestamp;
}
const libUUID::UUID &Log::getSid() const { return sid; }
void Log::setSid(const libUUID::UUID &sid) { this->sid = sid; }
const std::string_view Log::getDistributionGroupId() const {
	return distributionGroupId;
}
void Log::setDistributionGroupId(const std::string &distributionGroupId) {
	this->distributionGroupId = distributionGroupId;
}
const std::string_view Log::getUserId() const { return userID; }
void Log::setUserId(const std::string &userID) { this->userID = userID; }
const Device &Log::getDevice() const { return device; }
void Log::setDevice(const Device &device) { this->device = device; }

} // namespace appcenter::sdk::ingestion::model