#include "mars/listener/collector/ClockPrinter.h"
#include "mars/listener/util/Timer.h"

struct ClockPrinter::TestInfo {
  TestInfo() {
    timer.start();
  }

  TimeVal elapsed() const {
    return timer.elapsed();
  }

private:
  Timer timer;
};

std::string ClockPrinter::elapsed() const {
  return elapsedTime.toString();
}

std::string ClockPrinter::total() const {
  return totalTime.toString();
}

void ClockPrinter::startTestRun(const Test&) {
  totalTime.reset();
}

void ClockPrinter::startTestCase(const Test&) {
  stack.push(new TestInfo);
  elapsedTime.reset();
}

void ClockPrinter::endTestCase(const Test& test) {
  totalTime += stack.top().elapsed();
  stack.pop();
}
