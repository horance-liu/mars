#ifndef INCLUDE_MARS_LISTENER_TEXT_CLOCKPRINTER_H_
#define INCLUDE_MARS_LISTENER_TEXT_CLOCKPRINTER_H_

#include "mars/core/TestListener.h"
#include "mars/listener/util/TestStack.h"
#include "mars/listener/util/TimeVal.h"

struct ClockPrinter : TestListener {
  std::string elapsed() const;
  std::string total() const;

  void startTestRun(const Test&) override;
  void startTestCase(const Test&) override;
  void endTestCase(const Test&) override;

private:
  TimeVal elapsedTime;
  TimeVal totalTime;

  struct TestInfo;
  TestStack<TestInfo> stack;
};

#endif
