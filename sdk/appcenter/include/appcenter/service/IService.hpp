#pragma once

namespace appcenter {
namespace service {
// only Service can inherit from this class
class IService {
  protected:
	IService() = default;

  public:
	virtual ~IService() = 0;
};
inline IService::~IService() = default;
} // namespace service
} // namespace appcenter
