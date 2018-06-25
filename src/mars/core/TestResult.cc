#include "mars/core/TestResult.h"

TestResult::TestResult() : runTests(0) {
}

int TestResult::runCount() const {
  return runTests;
}

void TestResult::run() {
  runTests++;
}

int TestResult::failureCount() const {
  return failures.size();
}
