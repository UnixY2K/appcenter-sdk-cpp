#pragma once

#include <appcenter/http/httpResponse.hpp>

namespace appcenter {
namespace http {
/**
 * @brief the callback used for client side asynchronous operations.
 *
 */
class ServiceCallback {
  public:
	/**
	 * @brief Implement this method to handle successfull REST call results.
	 *
	 */
	virtual void onCallSucceeded(HttpResponse response) = 0;

	/**
	 * @brief Implement this method to handle failed REST call results.
	 *
	 * @param error the exception throw from the pipeline.
	 */
	virtual void onCallFailed(std::exception_ptr error) = 0;

	virtual ~ServiceCallback() = 0;
};
} // namespace http
} // namespace appcenter