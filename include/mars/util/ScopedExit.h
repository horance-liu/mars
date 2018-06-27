#ifndef INCLUDE_MARS_UTIL_SCOPEDEXIT_H_
#define INCLUDE_MARS_UTIL_SCOPEDEXIT_H_

#include "mars/util/Symbol.h"

template<typename F>
struct ScopedExit {
  ScopedExit(F f) : f(f) {
  }

  ~ScopedExit() {
    f();
  }

private:
  F f;
};

template<typename F>
inline ScopedExit<F> makeScopedExit(F f) {
  return ScopedExit<F>(f);
}

#define SCOPED_EXIT(code) auto UNIQUE_NAME(scope_exit) = makeScopedExit(code)

#endif
