#pragma once
#include <appcenter/private/exportAPI.hpp>
#include <cstddef>
#include <cstdint>
#include <initializer_list>
#include <limits>
#include <stdexcept>

// memory allocation utilities
namespace appcenter::api::memory {
extern "C" {
// array with fixed size (32-bit length)
typedef struct {
	// int 32 unsigned
	std::size_t length;
	void **data;
} Array_t;

// allocates an array of void*
appcenterAPI Array_t *APPCENTER_API_UTIL_ALLOCATE_ARRAY(size_t length);
appcenterAPI void APPCENTER_API_UTIL_DEALLOCATE_ARRAY(Array_t *array);
}

// initializer list Array_t
template <typename T> Array_t *makeArray(std::initializer_list<T> list) {
	if (list.size() > std::numeric_limits<std::uint32_t>::max()) {
		throw std::runtime_error("Array too large");
	}
	Array_t *array = APPCENTER_API_UTIL_ALLOCATE_ARRAY(list.size());
	std::size_t i = 0;
	for (auto &item : list) {
		array->data[i++] = &item;
	}
	return array;
}

} // namespace appcenter::api::memory