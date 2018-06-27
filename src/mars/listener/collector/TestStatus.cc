#include "mars/listener/collector/TestStatus.h"

TestStatus::TestStatus() : success(true) {
}

bool TestStatus::successful() const {
  return success;
}

void TestStatus::addFailure(const TestFailure&) {
  success = false;
}
