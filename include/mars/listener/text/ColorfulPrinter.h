#ifndef HC1529C5B_742D_4014_BBBF_7533B3E13905
#define HC1529C5B_742D_4014_BBBF_7533B3E13905

#include <iostream>
#include "mars/listener/collector/FailureLister.h"
#include "mars/listener/collector/TestCollector.h"
#include "mars/listener/collector/TestStatus.h"
#include "mars/listener/collector/ClockPrinter.h"

struct TestInfo;

struct ColorfulPrinter : TestListener {
  ColorfulPrinter(std::ostream& = std::cout);
  ~ColorfulPrinter();

private:
  void startTestRun(const Test&) override;
  void endTestRun(const Test&) override;

  void startTestSuite(const Test&) override;
  void endTestSuite(const Test&) override;

  void startTestCase(const Test&) override;
  void endTestCase(const Test&) override;

  void addFailure(const TestFailure&) override;

private:
  bool lastFailed;
  std::ostream& out;

  struct Writer;
  Writer* writer;

  TestStatus status;
  TestCollector collector;
  FailureLister lister;
  ClockPrinter clock;
};

#endif
