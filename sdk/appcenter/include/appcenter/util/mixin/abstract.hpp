#pragma once

namespace appcenter::util::mixin {
// abstract class template mixin
template <typename T> class Abstract {
  protected:
	Abstract() = default;

  public:
	virtual ~Abstract() = default;
};
} // namespace appcenter::util::mixin