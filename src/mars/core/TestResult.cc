#include "mars/core/TestResult.h"
#include "mars/except/TestFailure.h"

TestResult::TestResult() : runTests(0) {
}

TestResult::~TestResult() {
  listFailures([](auto f){
    delete f;
  });
}

int TestResult::runCount() const {
  return runTests;
}

void TestResult::run() {
  runTests++;
}

void TestResult::addFailure(TestFailure* f) {
  failures.push_back(f);
}

int TestResult::failureCount() const {
  auto num = 0;
  listFailures([&num](auto f) {
    if (f->isFailure()) num++;
  });
  return num;
}

int TestResult::errorCount() const {
  auto num = 0;
  listFailures([&num](auto f) {
    if (!f->isFailure()) num++;
  });
  return num;
}

