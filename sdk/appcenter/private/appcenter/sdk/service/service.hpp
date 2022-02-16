#pragma once
#include <appcenter/sdk/channel/Channel.hpp>
#include <appcenter/service/IService.hpp>
#include <string>
#include <string_view>

namespace appcenter::sdk::service {
/**
 * @brief Service class Interface specification.
 *
 */
class Service : public appcenter::service::IService {
  public:
	/**
	 * @brief check whether service is enabled or not.
	 *
	 * @return true the service is enabled.
	 * @return false the service is disabled.
	 */
	virtual const bool isInstanceEnabled() const = 0;
	/**
	 * @brief enable or disable this service
	 *
	 * @param enabled if the service is enabled.
	 */
	virtual void setInstanceEnabled(const bool enabled) = 0;
	/**
	 * @brief Check if the service requires an app secret.
	 *
	 * @return true if the service requires an app secret.
	 * @return false if the service does not require an app secret.
	 */
	virtual const bool isAppSecretRequired() const = 0;
	/**
	 * @brief Get the name of the service.
	 *
	 * @return the name of the service.
	 */
	virtual const std::string_view getServiceName() const = 0;

	// TODO: implement a thread worker to handle background tasks
	/**
	 * @brief called when the service is starting.
	 *
	 * @note Storage is not accesible until onStart is called, this is called on
	 * the same thread as AppCenter.start() method.
	 *
	 */
	virtual void onStarting() = 0;

	/**
	 * @brief called when the service is started.
	 *
	 * @param channel channel instance.
	 * @param appSecret the app secret.
	 * @param transmissionTargetToken the transmission target token.
	 */
	virtual void onStarted(channel::Channel &channel,
	                       const std::string_view appSecret,
	                       const std::string_view transmissionTargetToken) = 0;

	/**
	 * @brief called when the service is started witouth any secret.
	 *
	 * @note This is called when the app starts the service again, with either
	 * app secret or transmission token.
	 *
	 * @param appSecret
	 * @param transmissionTargetToken
	 */
	virtual void
	onConfigurationUpdated(const std::string_view appSecret,
	                       const std::string_view transmissionTargetToken) = 0;

	/**
	 * @brief virtual destructor.
	 *
	 */
	virtual ~Service() {}
};
} // namespace appcenter::sdk::service