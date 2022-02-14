#pragma once
#include <chrono>
#include <ctime>
#include <string>
#include <string_view>

namespace appcenter::util::date {
using date_timestamp = std::chrono::system_clock::time_point;
class Date {
	date_timestamp timestamp;

  public:
	static constexpr std::string_view default_format = "%Y-%m-%d %H:%M:%S";
	Date() = delete;
	explicit Date(const std::time_t timestamp);
	explicit Date(const date_timestamp& timePoint);
	Date(const Date &other) = default;
	Date(Date &&other) noexcept = default;

	date_timestamp getTimestamp() const;
	std::time_t getTimeT() const;

	std::string to_string(const std::string_view format = default_format) const;
	static Date now();


	Date &operator=(const std::time_t timestamp);
	Date &operator=(const date_timestamp& timePoint);
	Date &operator=(const Date &other) = default;
	Date &operator=(Date &&other) noexcept = default;
};
} // namespace appcenter::util::date