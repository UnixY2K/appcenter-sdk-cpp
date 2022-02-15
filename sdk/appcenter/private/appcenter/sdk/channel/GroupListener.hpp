#pragma once
#include <appcenter/sdk/ingestion/models/log.hpp>
#include <exception>

namespace appcenter::sdk::channel {
/**
 * Channel group listener specification.
 */
class GroupListener {
  public:
	/**
	 * Called before processing a log.
	 *
	 * @param log The log that will be delivered.
	 */
	void onBeforeSending(ingestion::model::Log log);

	/**
	 * Called when the log is delivered successfully.
	 *
	 * @param log The log that is delivered.
	 */
	void onSuccess(ingestion::model::Log log);

	/**
	 * Called when the log is not delivered successfully.
	 *
	 * @param log The log that is not delivered.
	 * @param e   The exception for failure.
	 */
	void onFailure(ingestion::model::Log log, std::exception e);
};
} // namespace appcenter::sdk::channel