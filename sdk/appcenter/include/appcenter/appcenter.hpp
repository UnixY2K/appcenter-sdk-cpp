#pragma once
#include <appcenter/private/exportAPI.hpp>
#include <string>


namespace appcenter {
enum class Services_t {
	// analytics
	analytics = 1 << 0,
	// crash
	crash = 1 << 1,
	// distribution
	distribute = 1 << 2
};

// binary and operator for Services_t

inline constexpr bool operator&(Services_t lhs, Services_t rhs) {
	return static_cast<int>(lhs) & static_cast<int>(rhs);
}
inline constexpr Services_t operator|(Services_t lhs, Services_t rhs) {
	return Services_t(static_cast<int>(lhs) | static_cast<int>(rhs));
}

extern "C" {
appcenterAPI void start(std::string appSecret, Services_t services);
}

} // namespace appcenter
