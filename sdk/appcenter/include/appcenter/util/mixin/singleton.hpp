#pragma once

namespace appcenter::util::mixin {
// singleton mixin template class
template <class T> class Singleton {
  protected:
	Singleton() = default;

  public:
	static T &getInstance() {
		static T instance;
		return instance;
	}
};
} // namespace appcenter::util::mixin