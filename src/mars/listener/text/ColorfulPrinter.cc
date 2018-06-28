#include "mars/listener/text/ColorfulPrinter.h"
#include "mars/listener/util/Color.h"
#include "mars/core/Test.h"
#include "mars/except/TestFailure.h"

struct ColorfulPrinter::Writer {
  Writer(ColorfulPrinter& self) : self(self) {
  }

  void writeOnStartTestRun(const Test& test) const {
    onTestRun(test);
  }

  void writeOnEndTestRun(const Test& test) const {
    onTestRun(test);
    onFinished(test);
  }

  void writeOnStartTestSuite(const Test& test) const {
    self.out << std::endl;
    onSuite(test);
  }

  void writeOnEndTestSuite(const Test& test) const {
    onSuite(test);
    self.out << std::endl;
  }

  void writeOnStartTestCase(const Test& test) const {
    green(self.out) << "[ RUN      ] ";
    white(self.out) << test.getName() << std::endl;
  }

  void writeOnEndTestCase(const Test& test) const {
    self.lastFailed ? onTestCaseFail() : onTestCaseSucc();
    white(self.out) << test.getName()
                    << "(" << self.clock.elapsed() << ")"
                    << std::endl;
  }

  void writeOnAddFailure(const TestFailure& fail) const {
    self.out << fail.getExceptionMsg() << std::endl;
  }

private:
  void onSuite(const Test& test) const {
    if (test.getName() == "All Tests")
      return;

    green(self.out) << "[----------] ";
    white(self.out) << test.countTestCases()
                    << " tests from "
                    << test.getName()
                    << std::endl;
  }

  void onTestRun(const Test& test) const {
    green(self.out) << "[==========] ";
    white(self.out) << test.countTestCases()
                    << " test cases."
                    << std::endl;
  }

  void onTestCaseSucc() const {
    green(self.out) << "[       OK ] ";
  }

  void onTestCaseFail() const {
    red(self.out) << "[  FAILED  ] ";
  }

  void onFinished(const Test& test) const {
    collectOnFinished();
    listFailures();
  }

  std::ostream& title(std::ostream& out) const {
    return self.status.successful() ? red(out) : green(out);
  }

  void collectOnFinished() const {
    title(self.out) << "[  TOTAL   ] ";
    white(self.out) << "PASS: "    << self.collector.passCount()  << "  "
                    << "FAILURE: " << self.collector.failCount()  << "  "
                    << "ERROR: "   << self.collector.errorCount() << "  "
                    << "TIME: "    << self.clock.total()
                    << std::endl;
  }

  void listFailures() const {
    if (self.status.successful())
      return;

    red(self.out)   << "[  FAILED  ] ";
    white(self.out) << self.collector.failTotal()
                    << " tests, listed below:\n";

    self.lister.foreachFailures([&](auto& failure) {
      red(self.out)   << titleFor(failure);
      white(self.out) << failure.getTestName() << std::endl;
    });
  }

  static const char* titleFor(const TestFailure& err) {
    return err.isFailure() ? "[  FAILURE ] " : "[  ERROR   ] ";
  }

private:
  ColorfulPrinter& self;
};

ColorfulPrinter::ColorfulPrinter(std::ostream& out)
  : lastFailed(false), out(out), writer(new Writer(*this)) {
}

ColorfulPrinter::~ColorfulPrinter() {
  delete writer;
}

void ColorfulPrinter::startTestRun(const Test& test) {
  clock.startTestRun(test);
  writer->writeOnStartTestRun(test);
}

void ColorfulPrinter::endTestRun(const Test& test) {
  writer->writeOnEndTestRun(test);
}

void ColorfulPrinter::startTestCase(const Test& test) {
  lastFailed = false;
  collector.startTestCase(test);
  clock.startTestCase(test);

  writer->writeOnStartTestCase(test);
}

void ColorfulPrinter::endTestCase(const Test& test) {
  collector.endTestCase(test);
  clock.endTestCase(test);

  writer->writeOnEndTestCase(test);
}

void ColorfulPrinter::startTestSuite(const Test& test) {
  writer->writeOnStartTestSuite(test);
}

void ColorfulPrinter::endTestSuite(const Test& test) {
  writer->writeOnEndTestSuite(test);
}

void ColorfulPrinter::addFailure(const TestFailure& fail) {
  lastFailed = true;
  status.addFailure(fail);
  collector.addFailure(fail);
  lister.addFailure(fail);

  writer->writeOnAddFailure(fail);
}
