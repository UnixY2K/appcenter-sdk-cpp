#pragma once

namespace appcenter {
namespace http {
class ServiceCall {
  public:
	// cancel the call if possible.
	virtual void cancel() = 0;
	virtual ~ServiceCall() = 0;
};
} // namespace http
} // namespace appcenter