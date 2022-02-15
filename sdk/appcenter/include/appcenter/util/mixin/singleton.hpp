#pragma once

namespace appcenter::util::mixin {
// singleton mixin template class
template <class T> class Singleton {
  protected:
	Singleton() = default;

  public:
	Singleton(const Singleton &) = delete;
	Singleton &operator=(const Singleton &) = delete;
	Singleton(Singleton &&) = delete;
	Singleton &operator=(Singleton &&) = delete;
	static T &getInstance() {
		static T instance;
		return instance;
	}
};
} // namespace appcenter::util::mixin