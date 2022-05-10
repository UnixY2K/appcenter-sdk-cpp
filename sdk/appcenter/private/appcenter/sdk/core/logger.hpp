#pragma once
#include <appcenter/core/LogLevel.hpp>
#include <appcenter/util/mixin/singleton.hpp>
#include <cstddef>
#include <iosfwd>
#include <string>
#include <string_view>

namespace appcenter::sdk::core::logging {
// Log Level threshold for logs emmited by the SDK.
using LogLevel = appcenter::core::logging::LogLevel;

constexpr std::string_view log_level_names[] = {
	"DEVEL", "VERBOSE", "DEBUG", "INFO", "WARN", "ERROR", "ASSERT", "NONE"};

constexpr std::string_view getLogLevelName(LogLevel level) {
	// check bounds
	size_t index = static_cast<size_t>(level);
	size_t max = sizeof(log_level_names) / sizeof(log_level_names[0]);
	if (index >= max) {
		index = max - 1;
	}
	return log_level_names[index];
}

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
	 * @brief Writes a log at the LogLevel.Devel level.
	 * @note To track events, use Analytics.TrackEvent
	 * @param tag Log tag.
	 * @param message Message.
	 */
	void devel(const std::string_view tag, const std::string_view message);

	/**
	 * @brief Writes a log at the LogLevel.Verbose level.
	 * @note To track events, use Analytics.TrackEvent
	 * @param tag Log tag.
	 * @param message Message.
	 */
	void verbose(const std::string_view tag, const std::string_view message);

	/**
	 * @brief Writes a log at the LogLevel.Debug level.
	 * @note To track events, use Analytics.TrackEvent
	 * @param tag Log tag.
	 * @param message Message.
	 */
	void debug(const std::string_view tag, const std::string_view message);

	/**
	 * @brief Writes a log at the LogLevel.Info level.
	 * @note To track events, use Analytics.TrackEvent
	 * @param tag Log tag.
	 * @param message Message.
	 */
	void info(const std::string_view tag, const std::string_view message);

	/**
	 * @brief Writes a log at the LogLevel.Warn level.
	 * @note To track events, use Analytics.TrackEvent
	 * @param tag Log tag.
	 * @param message Message.
	 */
	void warn(const std::string_view tag, const std::string_view message);

	/**
	 * @brief Writes a log at the LogLevel.Error level.
	 * @note To track events, use Analytics.TrackEvent
	 * @param tag Log tag.
	 * @param message Message.
	 */
	void error(const std::string_view tag, const std::string_view message);

	/**
	 * @brief Writes a log at the LogLevel.Assert level.
	 * @note To track events, use Analytics.TrackEvent
	 * @param tag Log tag.
	 * @param message Message.
	 */
	void assert(const std::string_view tag, const std::string_view message);

	/**
	 * @brief Set the Log Format output.
	 *
	 * @param format The new Log Format output.
	 */
	void setLogFormat(const std::string_view format);

	/**
	 * @brief Get the Log Format.
	 *
	 * @return const std::string_view the Log Format.
	 */
	const std::string_view getLogFormat() const;

  private:
	std::string log_format = "{timestamp} [{tag}] {level}: {message}\n";
	void log(const LogLevel level, const std::string_view tag,
	         const std::string_view message);

	std::ostream *m_logger = nullptr;
	LogLevel m_logLevel = LogLevel::Assert;
};
} // namespace appcenter::sdk::core::logging