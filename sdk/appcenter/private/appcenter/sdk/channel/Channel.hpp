#pragma once
#include <appcenter/sdk/channel/Flag.hpp>
#include <appcenter/sdk/channel/Listener.hpp>
#include <appcenter/sdk/ingestion/ingestion.hpp>
#include <string>
#include <string_view>

namespace appcenter::sdk::channel {
/**
 * The interface for Channel.
 */
// todo: implement this class
class Channel {
  public:
	/**
	 * Set app secret. Intended usage is to use that only if there was no app
	 * secret at initialization time. The behavior is undefined if trying to
	 * update app secret a second time.
	 *
	 * @param appSecret app secret.
	 */
	void setAppSecret(const std::string_view appSecret);

	/**
	 * Set maximum SQLite database size.
	 *
	 * @param maxStorageSizeInBytes maximum SQLite database size in bytes.
	 * @return true if database size was set, otherwise false.
	 */
	bool setMaxStorageSize(long maxStorageSizeInBytes);

	/**
	 * Add a group for logs to be persisted and sent.
	 *
	 * @param groupName          the name of a group.
	 * @param maxLogsPerBatch    maximum log count per batch.
	 * @param batchTimeInterval  time interval for a next batch.
	 * @param maxParallelBatches maximum number of batches in parallel.
	 * @param ingestion          ingestion for the channel. If null then the
	 * default ingestion will be used.
	 * @param groupListener      a listener for a service.
	 */
	void addGroup(std::string groupName, int maxLogsPerBatch,
	              long batchTimeInterval, int maxParallelBatches,
	              ingestion::Ingestion ingestion, GroupListener groupListener);

	/**
	 * Remove a group for logs.
	 *
	 * @param groupName the name of a group.
	 */
	void removeGroup(std::string groupName);

	/**
	 * Pauses the given group.
	 *
	 * @param groupName   the name of a group.
	 * @param targetToken the target token to pause, or null to pause the entire
	 * group.
	 */
	void pauseGroup(std::string groupName, std::string targetToken);

	/**
	 * Resumes transmission for the given group.
	 *
	 * @param groupName   the name of a group.
	 * @param targetToken the target token to resume, or null to resume the
	 * entire group.
	 */
	void resumeGroup(std::string groupName, std::string targetToken);

	/**
	 * Add log to queue to be persisted and sent.
	 *
	 * @param log       the log to be enqueued.
	 * @param groupName the group to use.
	 * @param flags     the flags for this log.
	 */
	void enqueue(ingestion::model::Log log, std::string groupName, Flag flags);

	/**
	 * Check whether channel is enabled or disabled.
	 *
	 * @return true if channel is enabled, false otherwise.
	 */
	bool isEnabled();

	/**
	 * Enable or disable channel.
	 *
	 * @param enabled true to enable, false to disable.
	 */
	void setEnabled(bool enabled);

	/**
	 * Update log URL.
	 *
	 * @param logUrl log URL.
	 */
	void setLogUrl(std::string logUrl);

	/**
	 * Clear all persisted logs for the given group.
	 *
	 * @param groupName the group name.
	 */
	void clear(std::string groupName);

	/**
	 * Invalidate device cache that this channel may have.
	 */
	void invalidateDeviceCache();

	/**
	 * Add a global listener to the channel.
	 *
	 * @param listener listener to add.
	 */
	void addListener(Listener listener);

	/**
	 * Remove a listener from the channel.
	 *
	 * @param listener listener to remove.
	 */
	void removeListener(Listener listener);

	/**
	 * Suspend channel and wait for a limited period of time for queued logs to
	 * be persisted.
	 */
	void shutdown();

	/**
	 * Set network request allowed. If true check pending logs, suspend sending
	 * logs otherwise.
	 *
	 * @param isAllowed True if network request allowed, false otherwise.
	 */
	void setNetworkRequests(bool isAllowed);
};

} // namespace appcenter::sdk::channel