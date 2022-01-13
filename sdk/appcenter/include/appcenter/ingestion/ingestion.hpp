#pragma once
#include <appcenter/http/serviceCall.hpp>
#include <appcenter/http/serviceCallback.hpp>
#include <appcenter/ingestion/models/logContainer.hpp>
#include <appcenter/util/UUID.hpp>
#include <string>

namespace appcenter {
namespace ingestion {
/**
 * @brief Interface to send logs to the Ingestion service.
 *
 */
class Ingestion {
  public:
	/**
	 * @brief Send logs to the Ingestion service.
	 *
	 * @param appSecret a unique and secret used to identify the application.
	 * @param installId install identifier.
	 * @param logContainer
	 * @param callback
	 * @return appcenter::http::ServiceCall*
	 * @throws std::invalid_argument if callback is null.
	 */
	virtual http::ServiceCall *
	sendAsync(std::string appSecret, util::UUID installId,
	          appcenter::ingestion::model::LogContainer logContainer,
	          appcenter::http::ServiceCallback callback) = 0;

	/**
	 * @brief Update the log URL.
	 *
	 * @param logUrl log URL.
	 */
	virtual void setLogUrl(std::string logUrl) = 0;

	/**
	 * @brief Check whether the ingestion is enabled and able to perform network
	 * call.
	 *
	 * @return true if enabled.
	 * @return false otherwise.
	 */
	virtual bool isEnabled() = 0;

	/**
	 * @brief make the ingestion active again after closing.
	 */
	virtual void reopen() = 0;

	virtual ~Ingestion() = 0;
};
} // namespace ingestion
} // namespace appcenter