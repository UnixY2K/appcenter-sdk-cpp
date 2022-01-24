#pragma once
#include <ctime>

namespace appcenter {
namespace util {
class Date {
	// TODO: implement a propper Date class, meanwhile we use a timestamp (std::time_t)
	time_t timestamp;
};
} // namespace util
} // namespace appcenter