#pragma once
#include "appcenter/sdk/core/logger.hpp"
#include <appcenter/sdk/service/service.hpp>
#include <appcenter/sdk/core/logger.hpp>
#include <string_view>

namespace appcenter::sdk::analytics {
class Analytics : public service::Service {
  public:
	const bool isInstanceEnabled() const override;
	void setInstanceEnabled(const bool enabled) override;
	const bool isAppSecretRequired() const override;
	const std::string_view getServiceName() const override;
	void onStarting() override;
	void onStarted(channel::Channel &channel, const std::string_view appSecret,
	               const std::string_view transmissionTargetToken) override;
	void onConfigurationUpdated(
	    const std::string_view appSecret,
	    const std::string_view transmissionTargetToken) override;

  private:
	static constexpr std::string_view log_tag{"Analytics"};
	static core::logging::Logger& getLogger();
};
} // namespace appcenter::sdk::analytics
