#pragma once
#include <appcenter/sdk/appcenter.hpp>
#include <appcenter/sdk/core/logger.hpp>
#include <string_view>

namespace appcenter::sdk::service {
// internal template class for the internal services within the SDK
template <class Service> class InternalService {
  protected:
	InternalService(std::string_view logTag) : logTag(logTag) {}
	const std::string_view logTag;
	static sdk::core::logging::Logger &getLogger() {
		return AppCenter::getInstance().getLogger();
	}
};
} // namespace appcenter::sdk::service