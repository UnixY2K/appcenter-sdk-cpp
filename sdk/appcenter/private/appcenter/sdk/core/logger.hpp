#pragma once
#include <appcenter/util/mixin/singleton.hpp>
#include <iosfwd>
#include <string>

namespace appcenter::sdk::core::logging {
// Log Level threshold for logs emmited by the SDK.
enum class LogLevel {
	// SDK emits all possible level of logs.
	Verbose,
	// SDK emits debug, info, warn, error and assert logs.
	Debug,
	// SDK emits info, warn, error and assert logs.
	Info,
	// SDK emits warn, error, and assert logs. (default for debug)
	Warn,
	// SDK emits error and assert logs.
	Error,
	// Only assert logs are emmited by the SDK.  (default for release)
	Assert,
	// No log is emitted by SDK.
	None
};

class Logger : public util::mixin::Singleton<Logger> {
  public:
	/**
	 * @brief Get the internal logger by the SDK
	 * @details All logs emitted by the SDK are forwarded to the internal
	 * logger.
	 * @return The internal logger
	 */
	std::ostream &getLogger();

	/**
	 * @brief Set the internal logger to be used by the SDK
	 * @details All logs emitted by the SDK are forwarded to the internal
	 * logger.
	 * @param logger The new internal logger
	 */
	void setLogger(std::ostream &logger);

	/**
	 * @brief Get the Log Level used by the SDK
	 * @details The SDK will only log logs with a level equal or higher than
	 *
	 * @return the actual Log Level used by the SDK
	 */
	LogLevel getLogLevel();

	/**
	 * @brief Set the Log Level used by the SDK
	 * @details The SDK will only log logs with a level equal or higher than
	 *
	 * @param level The new Log Level used by the SDK
	 */
	void setLogLevel(LogLevel level);

	/**
	 * @brief Get the Log Tag for this SDK.
	 * @details All logs emmited at the SDK level will contain this tag.
	 * @return const std::string&
	 */
	const std::string &getLogTag();
	/**
	 * @brief Set the Log Tag object.
	 * @details All logs emmited at the SDK level will contain this tag.
	 * @param logTag
	 */
	void setLogTag(std::string logTag);

	/**
	 * @brief Writes a log at the LogLevel.Verbose level.
	 * @note To track events, use Analytics.TrackEvent
	 * @param tag Log tag.
	 * @param message Message.
	 */
	void verbose(std::string tag, std::string message);

	/**
	 * @brief Writes a log at the LogLevel.Debug level.
	 * @note To track events, use Analytics.TrackEvent
	 * @param tag Log tag.
	 * @param message Message.
	 */
	void debug(std::string tag, std::string message);

	/**
	 * @brief Writes a log at the LogLevel.Info level.
	 * @note To track events, use Analytics.TrackEvent
	 * @param tag Log tag.
	 * @param message Message.
	 */
	void info(std::string tag, std::string message);

	/**
	 * @brief Writes a log at the LogLevel.Warn level.
	 * @note To track events, use Analytics.TrackEvent
	 * @param tag Log tag.
	 * @param message Message.
	 */
	void warn(std::string tag, std::string message);

	/**
	 * @brief Writes a log at the LogLevel.Error level.
	 * @note To track events, use Analytics.TrackEvent
	 * @param tag Log tag.
	 * @param message Message.
	 */
	void error(std::string tag, std::string message);

	/**
	 * @brief Writes a log at the LogLevel.Assert level.
	 * @note To track events, use Analytics.TrackEvent
	 * @param tag Log tag.
	 * @param message Message.
	 */
	void assert(std::string tag, std::string message);

  private:
	void log(LogLevel level, std::string tag, std::string message);
	const std::string getMessageWithTag(std::string tag, std::string message);

	std::ostream *m_logger = nullptr;
	std::string m_logTag = "AppCenter";
    LogLevel m_logLevel = LogLevel::Assert;
};
} // namespace appcenter::core::logging