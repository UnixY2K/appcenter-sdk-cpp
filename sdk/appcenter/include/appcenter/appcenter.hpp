#pragma once
#include <appcenter/private/exportAPI.hpp>
#include <appcenter/service/services.hpp>
#include <string>

namespace appcenter {

extern "C" {

/**
 * @brief Configure the SDK with an app secret.
 * This may be called only once per application process lifetime.
 * 
 * @param appSecret A unique and secret key used to identify the application.
 */
appcenterAPI void configure(std::string appSecret);
/**
 * @brief Check whether SDK has already been configured.
 * 
 * @return bool true if configured, false otherwise.
 */
appcenterAPI bool isConfigured();
/**
 * @brief Configure the SDK with the list of services to start with an app secret parameter.
 * This may be called only once per application process lifetime.
 * @param application Your application object.
 * @param appSecret A unique and secret key used to identify the application.
 * @param services List of services to use.
 */
appcenterAPI void start(std::string appSecret, Services_t services);
/**
 * @brief Start services. This may be called only once per service per application process lifetime.
 * 
 * @param services List of services to use.
 */
appcenterAPI void startServices(Services_t services);
}

} // namespace appcenter