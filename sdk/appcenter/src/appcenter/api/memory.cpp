#include <cstddef>
#include <cstdint>
#define appcenterLIBRARY_EXPORT
#include <appcenter/api/memory.hpp>
#include <appcenter/private/exportAPI.hpp>

namespace appcenter::api::memory {
extern "C" {
appcenterAPI Array_t *APPCENTER_API_UTIL_ALLOCATE_ARRAY(size_t length) {
	Array_t *array = new Array_t{length, new void *[length]};
	return array;
}
appcenterAPI void APPCENTER_API_UTIL_DEALLOCATE_ARRAY(Array_t *array) {
	delete[] array->data;
	delete array;
}
}

} // namespace appcenter::api::memory