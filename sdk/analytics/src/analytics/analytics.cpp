#include <appcenter/sdk/analytics/analytics.hpp>
#include <appcenter/sdk/appcenter.hpp>
#include <appcenter/sdk/constants.hpp>

namespace appcenter::sdk::analytics {
const bool Analytics::isInstanceEnabled() const {
	// TODO: Implement
	return false;
}
void Analytics::setInstanceEnabled(const bool enabled) {
	// TODO: Implement
}
const bool Analytics::isAppSecretRequired() const {
	// TODO: Implement
	return true;
}
const std::string_view Analytics::getServiceName() const {
	// TODO: Implement
	return appcenter::sdk::constants::undefined_value;
}
void Analytics::onStarting() {
	// TODO: Implement
}
void Analytics::onStarted(channel::Channel &channel,
                          const std::string_view appSecret,
                          const std::string_view transmissionTargetToken) {
	// TODO: Implement
	getLogger().verbose(log_tag, "onStarted");
}
void Analytics::onConfigurationUpdated(
    const std::string_view appSecret,
    const std::string_view transmissionTargetToken) {
	// TODO: Implement
}

core::logging::Logger &Analytics::getLogger() {
	AppCenter &appCenter = AppCenter::getInstance();
	return appCenter.getLogger();
}

} // namespace appcenter::sdk::analytics