#pragma once

namespace appcenter::core::logging {
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
}