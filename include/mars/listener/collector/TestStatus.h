#ifndef SRC_MARS_LISTENER_TESTSUCCESSLISTENER_H_
#define SRC_MARS_LISTENER_TESTSUCCESSLISTENER_H_

#include "mars/core/TestListener.h"

struct TestStatus : TestListener {
  TestStatus();

  bool successful() const;

  void addFailure(const TestFailure&) override;

private:
  bool success;
};

#endif
