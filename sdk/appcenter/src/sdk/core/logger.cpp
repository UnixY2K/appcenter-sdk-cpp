#include <appcenter/sdk/core/logger.hpp>
#include <appcenter/sdk/util/Date.hpp>
#include <fmt/core.h>
#include <fmt/format.h>
#include <iostream>
#include <ostream>
#include <string_view>

namespace appcenter::sdk::core::logging {
std::ostream &Logger::getLogger() { return *m_logger; }

void Logger::setLogger(std::ostream &logger) { m_logger = &logger; }

LogLevel Logger::getLogLevel() { return m_logLevel; }

void Logger::setLogLevel(LogLevel level) { m_logLevel = level; }

void Logger::devel(const std::string_view tag, const std::string_view message) {
	log(LogLevel::Devel, tag, message);
}

void Logger::verbose(const std::string_view tag,
                     const std::string_view message) {
	log(LogLevel::Verbose, tag, message);
}

void Logger::debug(const std::string_view tag, const std::string_view message) {
	log(LogLevel::Debug, tag, message);
}

void Logger::info(const std::string_view tag, const std::string_view message) {
	log(LogLevel::Info, tag, message);
}

void Logger::warn(const std::string_view tag, const std::string_view message) {
	log(LogLevel::Warn, tag, message);
}

void Logger::error(const std::string_view tag, const std::string_view message) {
	log(LogLevel::Error, tag, message);
}

void Logger::assert(const std::string_view tag,
                    const std::string_view message) {
	log(LogLevel::Assert, tag, message);
}

void Logger::log(const LogLevel level, const std::string_view tag,
                 const std::string_view message) {
	if (level >= m_logLevel) {
		std::string logMessage = fmt::format(
		    log_format,
		    fmt::arg("timestamp",
		             util::date::Date::now().to_string()),          // timestamp
		    fmt::arg("level", std::string(getLogLevelName(level))), // level
		    fmt::arg("tag", tag),                                   // tag
		    fmt::arg("message", message)                            // message
		);
		if (m_logger) {
			// TODO: implement a propper logger interface
			*m_logger << logMessage;
		} else {
			// by default all logs are written to stdout
			std::cout << logMessage;
		}
	}
}

void Logger::setLogFormat(const std::string_view format) {
	log_format = format;
}

const std::string_view Logger::getLogFormat() const { return log_format; }

} // namespace appcenter::sdk::core::logging
