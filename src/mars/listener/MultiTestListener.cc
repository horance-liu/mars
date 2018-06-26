#include "mars/listener/MultiTestListener.h"

#define BOARDCAST(action) for (auto listener : listeners) listener->action

void MultiTestListener::startTestRun
  (const Test& test, const TestResult& result) {
  BOARDCAST(startTestRun(test, result));
}

void MultiTestListener::endTestRun
  (const Test& test, const TestResult& result) {
  BOARDCAST(endTestRun(test, result));
}

void MultiTestListener::startTestSuite(const Test& test) {
  BOARDCAST(startTestSuite(test));
}

void MultiTestListener::endTestSuite(const Test& test) {
  BOARDCAST(endTestSuite(test));
}

void MultiTestListener::startTestCase(const Test& test) {
  BOARDCAST(startTestCase(test));
}

void MultiTestListener::endTestCase(const Test& test) {
  BOARDCAST(endTestCase(test));
}

void MultiTestListener::addFailure(const TestFailure& failure) {
  BOARDCAST(addFailure(failure));
}
