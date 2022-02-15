#pragma once
#include <appcenter/private/exportAPI.hpp>
#include <cstddef>
#include <cstdint>
#include <exception>
#include <initializer_list>
#include <limits>
#include <stdexcept>

// memory allocation utilities
namespace appcenter::api::memory {
extern "C" {
// array with fixed size (32-bit length)
typedef struct {
	// int 32 unsigned
	std::size_t size;
	void **data;
} Array_t;

// allocates an array of void*
appcenterAPI Array_t *APPCENTER_API_UTIL_ALLOCATE_ARRAY(size_t size);
appcenterAPI void APPCENTER_API_UTIL_DEALLOCATE_ARRAY(Array_t *array);
appcenterAPI void APPCENTER_API_DELETE_STRING(const char *str);
}
inline std::string makeString(const char *str) {
	try {
		std::string s(str);
		APPCENTER_API_DELETE_STRING(str);
		return s;
	} catch (std::exception &ex) {
		APPCENTER_API_DELETE_STRING(str);
		throw ex;
	}
}

// initializer list Array_t
template <typename T> Array_t *makeArray(std::initializer_list<T> list) {
	if (list.size() > std::numeric_limits<std::uint32_t>::max()) {
		throw std::runtime_error("Array too large");
	}
	if (list.size() == 0) {
		return nullptr;
	}
	Array_t *array = APPCENTER_API_UTIL_ALLOCATE_ARRAY(list.size());
	std::size_t i = 0;
	for (auto &item : list) {
		// check if the item is a pointer (constexpr)
		if constexpr (std::is_pointer_v<T>) {
			array->data[i++] =
			    const_cast<void *>(static_cast<const void *>(item));
		} else {
			array->data[i++] =
			    const_cast<void *>(static_cast<const void *>(&item));
		}
	}
	return array;
}

} // namespace appcenter::api::memory