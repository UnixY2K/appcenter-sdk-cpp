#pragma once

namespace appcenter {
namespace sdk::service {
class Service;
}
namespace service {
// only Service can inherit from this class
class IService {
  protected:
	IService() = default;

  public:
	/**
	 * @brief Return the service instance.
	 *
	 * @return sdk::service::Service* the unique service instance.
	 */
	virtual sdk::service::Service *getService() const = 0;

  public:
	virtual ~IService() = 0;
};
inline IService::~IService() = default;
} // namespace service
} // namespace appcenter
