#ifndef INCLUDE_MARS_LISTENER_COLLECTOR_FAILURELISTER_H_
#define INCLUDE_MARS_LISTENER_COLLECTOR_FAILURELISTER_H_

#include <vector>
#include "mars/core/TestListener.h"

struct TestFailure;

struct FailureLister : TestListener {
  template <typename F>
  void foreachFailures(F f) const {
    for (auto failure : failures) {
      f(*failure);
    }
  }

  void addFailure(const TestFailure&) override;

private:
  std::vector<const TestFailure*> failures;
};

#endif
