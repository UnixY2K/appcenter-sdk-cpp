#include "appcenter/common/AppCenterLog.hpp"
#include <appcenter/core/logger.hpp>
#include <iostream>
#include <ostream>

namespace appcenter::core::logging {
std::ostream &Logger::getLogger() { return *m_logger; }

void Logger::setLogger(std::ostream &logger) { m_logger = &logger; }

LogLevel Logger::getLogLevel() { return m_logLevel; }

void Logger::setLogLevel(LogLevel level) { m_logLevel = level; }

const std::string &Logger::getLogTag() { return m_logTag; }

void Logger::setLogTag(std::string logTag) { m_logTag = logTag; }

void Logger::verbose(std::string tag, std::string message) {
	log(LogLevel::Verbose, tag, message);
}

void Logger::debug(std::string tag, std::string message) {
	log(LogLevel::Debug, tag, message);
}

void Logger::info(std::string tag, std::string message) {
	log(LogLevel::Info, tag, message);
}

void Logger::warn(std::string tag, std::string message) {
	log(LogLevel::Warn, tag, message);
}

void Logger::error(std::string tag, std::string message) {
	log(LogLevel::Error, tag, message);
}

void Logger::assert(std::string tag, std::string message) {
	log(LogLevel::Assert, tag, message);
}

void Logger::log(LogLevel level, std::string tag, std::string message) {
	if (level >= m_logLevel) {
		if (m_logger) {
			// TODO: implement a propper logger interface
			*m_logger << getMessageWithTag(tag, message);
		} else {
			// by default all logs are written to stdout
			std::cout << getMessageWithTag(tag, message) << "\n";
		}
	}
}
} // namespace appcenter::core::logging