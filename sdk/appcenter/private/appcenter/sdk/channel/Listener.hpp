#pragma once
#include <appcenter/sdk/channel/GroupListener.hpp>
#include <string>

namespace appcenter::sdk::channel {
/**
 * Channel global listener specification.
 */
class Listener {
  public:
	/**
	 * Called whenever a new group is added.
	 *
	 * @param groupName     group name.
	 * @param groupListener group listener.
	 */
	void onGroupAdded(std::string groupName, GroupListener groupListener,
	                  long batchTimeInterval);

	/**
	 * Called whenever a new group is removed.
	 *
	 * @param groupName group name.
	 */
	void onGroupRemoved(std::string groupName);

	/**
	 * Called whenever a log is being prepared.
	 * This is used to alter some log properties if needed.
	 * The channel might alter log furthermore between this event and the
	 * next one: {@link #shouldFilter}.
	 *
	 * @param log       log being enqueued.
	 * @param groupName group of the log.
	 */
	void onPreparingLog(ingestion::model::Log log, std::string groupName);

	/**
	 * Called after a log has been fully prepared and properties are now
	 * final.
	 *
	 * @param log       prepared log.
	 * @param groupName group of the log.
	 * @param flags     log flags.
	 */
	void onPreparedLog(ingestion::model::Log log, std::string groupName,
	                   int flags);

	/**
	 * Called after a log has been fully prepared and properties are now
	 * final. The specified log can be filtered out by listeners if at least
	 * one of them returns true.
	 *
	 * @param log log to filter out.
	 * @return true to filter out the log, false to let it being stored and
	 * sent by the channel.
	 */
	bool shouldFilter(ingestion::model::Log log);

	/**
	 * Called after channel state has changed.
	 *
	 * @param isEnabled new channel state.
	 */
	void onGloballyEnabled(bool isEnabled);

	/**
	 * Called when a group is cleared.
	 *
	 * @param groupName The group name.
	 */
	void onClear(std::string groupName);

	/**
	 * Called when a group is paused.
	 *
	 * @param groupName   The group name.
	 * @param targetToken The target token is paused, or null when the
	 * entire group is paused.
	 */
	void onPaused(std::string groupName, std::string targetToken);

	/**
	 * Called when a group is resumed.
	 *
	 * @param groupName   The group name.
	 * @param targetToken The target token is resumed, or null when the
	 * entire group is resumed.
	 */
	void onResumed(std::string groupName, std::string targetToken);
};
} // namespace appcenter::sdk::channel