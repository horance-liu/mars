#include "mars/listener/text/ColorfulPrinter.h"
#include "mars/listener/util/Color.h"
#include "mars/core/Test.h"
#include "mars/core/TestResult.h"
#include "mars/except/TestFailure.h"
#include "mars/listener/util/TestInfo.h"
#include <sstream>

ColorfulPrinter::ColorfulPrinter(std::ostream& out)
  : out(out), lastFailed(false) {
}

void ColorfulPrinter::startTestRun(const Test& test) {
  clock.startTestRun(test);

  out << GREEN << "[==========] " << WHITE << "Running "
      << test.countTestCases() << " test cases." << std::endl;
}

namespace {
  std::string format(const timeval& elapsed) {
    std::stringstream ss;

    if (elapsed.tv_sec > 0)
      ss << elapsed.tv_sec << " s ";

    ss << elapsed.tv_usec << " us";

    return ss.str();
  }

  const char* titleFor(const TestFailure& failure) {
    return failure.isFailure() ? "[  FAILURE ] " : "[  ERROR   ] ";
  }
}

void ColorfulPrinter::listFailures() const {
  if (status.successful())
    return;

  out << RED << "[  FAILED  ] " << WHITE << collector.failTotal()
      << " tests, listed below:\n";

  lister.foreachFailures([&](auto& failure) {
    out << RED   << titleFor(failure)
        << WHITE << failure.getTestName()
        << std::endl;
  });
}

void ColorfulPrinter::endTestRun(const Test& test) {
  clock.endTestRun(test);

  out << GREEN << "[==========] " << WHITE << test.countTestCases()
      << " test cases ran." << std::endl;

  status.successful() ? out << GREEN : out << RED;

  out << "[  TOTAL   ] " << WHITE << "PASS: " << collector.passCount() << "  "
      << "FAILURE: " << collector.failCount() << "  " << "ERROR: " << collector.errorCount() << "  "
      << "TIME: " << format(total) << std::endl;

  listFailures();
}

void ColorfulPrinter::startTestCase(const Test& test) {
  collector.startTestCase(test);
  clock.startTestCase(test);

  lastFailed = false;
  out << GREEN << "[ RUN      ] " << WHITE << test.getName() << std::endl;
}

inline void ColorfulPrinter::onTestSucc() {
  out << GREEN << "[       OK ] ";
}

inline void ColorfulPrinter::onTestFail() {
  out << RED << "[  FAILED  ] ";
}

void ColorfulPrinter::endTestCase(const Test& test) {
  collector.endTestCase(test);

  lastFailed ? onTestFail() : onTestSucc();
  out << WHITE;

  clock.endTestCase(test);
}

void ColorfulPrinter::onSuite(const Test& test, const std::string& nl) {
  if (test.getName() == "All Tests")
    return;

  out << GREEN << nl << "[----------] " << WHITE << test.countTestCases()
      << " tests from " << test.getName() << std::endl;
}

void ColorfulPrinter::startTestSuite(const Test& test) {
  onSuite(test, "\n");
}

void ColorfulPrinter::endTestSuite(const Test& test) {
  onSuite(test, "");
}

void ColorfulPrinter::addFailure(const TestFailure& fail) {
  status.addFailure(fail);
  collector.addFailure(fail);
  lister.addFailure(fail);

  lastFailed = true;
  out << fail.getExceptionMsg() << std::endl;
}
