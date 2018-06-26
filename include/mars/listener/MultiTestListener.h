#ifndef INCLUDE_MARS_CORE_MULTITESTLISTENER_H_
#define INCLUDE_MARS_CORE_MULTITESTLISTENER_H_

#include <vector>
#include "mars/core/TestListener.h"

struct MultiTestListener : TestListener {
private:
  void startTestRun(const Test&, const TestResult&) override;
  void endTestRun(const Test&, const TestResult&) override;

  void startTestSuite(const Test&) override;
  void endTestSuite(const Test&) override;

  void startTestCase(const Test&) override;
  void endTestCase(const Test&) override;

  void addFailure(const TestFailure&) override;

private:
  std::vector<TestListener*> listeners;
};

#endif
