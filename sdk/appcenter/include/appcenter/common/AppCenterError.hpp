#pragma once
#include <cstddef>
#include <exception>
#include <stdexcept>

namespace appcenter {
namespace common {
class AppCenterError : public std::runtime_error {
  public:
	using std::runtime_error::runtime_error;
};
} // namespace common
} // namespace appcenter