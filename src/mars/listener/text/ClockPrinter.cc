#include <mars/util/ScopedExit.h>
#include "mars/listener/text/ClockPrinter.h"
#include "mars/listener/util/Timer.h"
#include "mars/core/Test.h"
#include <sstream>

ClockPrinter::ClockPrinter(std::ostream& out) : out(out) {
}

namespace {
  std::string format(const timeval& elapsed) {
    std::stringstream ss;

    if (elapsed.tv_sec > 0)
      ss << elapsed.tv_sec << " s ";

    ss << elapsed.tv_usec << " us";

    return ss.str();
  }

  std::string toString(const timeval& elapsed) {
    return std::string("(") + format(elapsed) + ")";
  }
}

void ClockPrinter::startTestRun(const Test&) {
  total.tv_sec  = 0;
  total.tv_usec = 0;
}

void ClockPrinter::endTestRun(const Test&) {
  out << "TIME: " << format(total) << std::endl;
}

struct ClockPrinter::TestInfo {
  TestInfo() {
    timer.start();
  }

  timeval elapsed() const {
    return timer.elapsed();
  }

private:
  Timer timer;
};

void ClockPrinter::startTestCase(const Test&) {
  tests.push(new TestInfo);
}

inline void ClockPrinter::collect(const timeval& elapsed) {
  total.tv_sec  += elapsed.tv_sec;
  total.tv_usec += elapsed.tv_usec;
}

inline ClockPrinter::TestInfo& ClockPrinter::top() const {
  return *tests.top();
}

inline void ClockPrinter::pop() {
  auto top = tests.top();
  tests.pop();
  delete top;
}

void ClockPrinter::endTestCase(const Test& test) {
  SCOPED_EXIT([this](){
    pop();
  });

  auto elapsed = top().elapsed();
  out << test.getName() << toString(elapsed) << std::endl;
  collect(elapsed);
}
