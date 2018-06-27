#ifndef INCLUDE_MARS_LISTENER_TEXT_CLOCKPRINTER_H_
#define INCLUDE_MARS_LISTENER_TEXT_CLOCKPRINTER_H_

#include <stack>
#include <iostream>
#include <time.h>
#include "mars/core/TestListener.h"

struct ClockPrinter : TestListener {
  ClockPrinter(std::ostream& out = std::cout);

  void startTestRun(const Test&) override;
  void endTestRun(const Test&) override;

  void startTestCase(const Test&) override;
  void endTestCase(const Test&) override;

private:
  struct TestInfo;
  struct Scoped;

  void collect(const timeval&);
  TestInfo& top() const;
  void pop();

private:
  std::ostream& out;
  timeval total;

  using TestStack = std::stack<TestInfo*>;
  TestStack tests;
};

#endif
