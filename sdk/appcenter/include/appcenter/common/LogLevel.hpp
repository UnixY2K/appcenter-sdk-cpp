#pragma once

namespace appcenter {
namespace common {
// Log Level threshold for logs emmited by the SDK.
enum class LogLevel {
	// SDK emits all possible level of logs.
	Verbose,
	// SDK emits debug, info, warn, error and assert logs.
	Debug,
	// SDK emits info, warn, error and assert logs.
	Info,
	// SDK emits warn, error, and assert logs.
	Warn,
	// SDK emits error and assert logs.
	Error,
	// Only assert logs are emmited by the SDK.
	Assert,
	// No log is emitted by SDK.
	None
};
} // namespace common
} // namespace appcenter
