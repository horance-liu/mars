#ifndef INCLUDE_MARS_LISTENER_TESTRESULTCOLLECTOR_H_
#define INCLUDE_MARS_LISTENER_TESTRESULTCOLLECTOR_H_

#include <vector>
#include "mars/core/TestListener.h"

struct TestCollector : TestListener {
  TestCollector();

  int runCount() const;
  int passCount() const;
  int failCount() const;
  int errorCount() const;
  int failTotal() const;

  void startTestCase(const Test&) override;
  void addFailure(const TestFailure&) override;
  void endTestCase(const Test&) override;

private:
  int numOfRuns;
  int numOfPassed;
  int numOfFailure;
  int numOfError;
  bool lastFailed;
};

#endif
