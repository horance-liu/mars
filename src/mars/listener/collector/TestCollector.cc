#include "mars/listener/collector/TestCollector.h"
#include "mars/except/TestFailure.h"

TestCollector::TestCollector()
  : numOfRuns(0)
  , numOfPassed(0)
  , numOfFailure(0)
  , numOfError(0)
  , lastFailed(false) {
}

int TestCollector::runCount() const {
  return numOfRuns;
}

int TestCollector::passCount() const {
  return numOfPassed;
}

int TestCollector::failCount() const {
  return numOfFailure;
}

int TestCollector::errorCount() const {
  return numOfError;
}

int TestCollector::failTotal() const {
  return failCount() + errorCount();
}

void TestCollector::addFailure(const TestFailure& failure) {
  lastFailed = true;
  failure.isFailure() ? numOfFailure++ : numOfError++;
}

void TestCollector::startTestCase(const Test&) {
  numOfRuns++;
  lastFailed = false;
}

void TestCollector::endTestCase(const Test& test) {
  if (!lastFailed) numOfPassed++;
}
