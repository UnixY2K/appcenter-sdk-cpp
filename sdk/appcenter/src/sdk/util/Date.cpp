#include <appcenter/sdk/util/Date.hpp>
#include <chrono>
#include <string_view>
#define HAS_UNCAUGHT_EXCEPTIONS 1
#include <date/date.h>

namespace appcenter::util::date {
Date::Date(const time_t timestamp)
    : timestamp(std::chrono::system_clock::from_time_t(timestamp)) {}
Date::Date(const date_timestamp &timePoint) : timestamp(timePoint) {}

date_timestamp Date::getTimestamp() const { return timestamp; }
time_t Date::getTimeT() const {
	return std::chrono::system_clock::to_time_t(timestamp);
}

std::string Date::to_string(const std::string_view format) const {
	return ::date::format(std::string(format), timestamp);
}

Date Date::now() {
	auto now = std::chrono::floor<std::chrono::milliseconds>(
	    std::chrono::system_clock::now());
	return Date(now);
}

Date &Date::operator=(const time_t timestamp) {
	this->timestamp = std::chrono::system_clock::from_time_t(timestamp);
	return *this;
}
Date &Date::operator=(const date_timestamp &timePoint) {
	this->timestamp = timePoint;
	return *this;
}

} // namespace appcenter::util::date