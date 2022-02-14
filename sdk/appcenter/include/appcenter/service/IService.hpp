#pragma once
#include <appcenter/util/mixin/abstract.hpp>

namespace appcenter {
namespace service {
// only Service can inherit from this class
class IService : public util::mixin::Abstract<IService> {};
} // namespace service
} // namespace appcenter
