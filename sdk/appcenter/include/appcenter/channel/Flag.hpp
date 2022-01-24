#pragma once
#include <cstdint>

namespace appcenter::channel {
enum class Flag : std::uint8_t {
	NORMAL = 0x01,
	CRITICAL = 0x02,
	DEFAULT = NORMAL,
	PERSISTENCE_MASK = 0xFF
};
}