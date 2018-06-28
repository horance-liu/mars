#ifndef INCLUDE_MARS_UTIL_SCOPEDEXIT_H_
#define INCLUDE_MARS_UTIL_SCOPEDEXIT_H_

class ScopedExit {
  using Handle  = void*;
  using Deleter = void(*)();
  using Wrapper = void(*)(Deleter*, Handle*);

  Wrapper wrapper;
  Deleter deleter;
  Handle handle;

public:
  template<typename T, typename D>
  ScopedExit(T handle, D deleter)
      : deleter(reinterpret_cast<Deleter>(+deleter))
      , handle(reinterpret_cast<Handle>(handle)) {
    static_assert(sizeof(T) <= sizeof(void*), "handle too big to store");
    wrapper = [](Deleter* deleter, Handle* handle) {
      auto d = (*reinterpret_cast<D*>(deleter));
      auto h = (*reinterpret_cast<T*>(handle));
      d(h);
    };
  }

  ~ScopedExit() {
    wrapper(&deleter, &handle);
  }
};

#endif
