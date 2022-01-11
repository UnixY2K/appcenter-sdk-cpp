#pragma once
#include <string>

namespace appcenter {
namespace log {
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
void Verbose(std::string tag, std::string message);

/**
 * @brief Writes a log at the LogLevel.Debug level.
 * @note To track events, use Analytics.TrackEvent
 * @param tag Log tag.
 * @param message Message.
 */
void Info(std::string tag, std::string message);

/**
 * @brief Writes a log at the LogLevel.Info level.
 * @note To track events, use Analytics.TrackEvent
 * @param tag Log tag.
 * @param message Message.
 */
void Info(std::string tag, std::string message);

/**
 * @brief Writes a log at the LogLevel.Warn level.
 * @note To track events, use Analytics.TrackEvent
 * @param tag Log tag.
 * @param message Message.
 */
void Warn(std::string tag, std::string message);

/**
 * @brief Writes a log at the LogLevel.Error level.
 * @note To track events, use Analytics.TrackEvent
 * @param tag Log tag.
 * @param message Message.
 */
void Error(std::string tag, std::string message);

/**
 * @brief Writes a log at the LogLevel.Assert level.
 * @note To track events, use Analytics.TrackEvent
 * @param tag Log tag.
 * @param message Message.
 */
void Assert(std::string tag, std::string message);

} // namespace log
} // namespace appcenter