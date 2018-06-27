#include "mars/core/TestResult.h"
#include "mars/core/Test.h"
#include "mars/except/AssertionError.h"
#include "mars/except/TestFailure.h"
#include "mars/core/internal/BareTestCase.h"
#include "mars/core/internal/BareTestSuite.h"
#include "mars/core/internal/TestFunctor.h"

TestResult::~TestResult() {
  for (auto f : failures) {
    delete f;
  }
}

void TestResult::addListener(TestListener* listener) {
  listeners.push_back(listener);
}


#define BOARDCAST(action) for (auto listener : listeners) listener->action

void TestResult::runRootTest(Test& test) {
  BOARDCAST(startTestRun(test));
  test.run(*this);
  BOARDCAST(endTestRun(test));
}

void TestResult::runTestCase(BareTestCase& test) {
  BOARDCAST(startTestCase(test.get()));
  test.runBare(*this);
  BOARDCAST(endTestCase(test.get()));
}

void TestResult::runTestSuite(BareTestSuite& test) {
  BOARDCAST(startTestSuite(test.get()));
  test.runBare(*this);
  BOARDCAST(startTestSuite(test.get()));
}

void TestResult::addFailure(TestFailure* f) {
  failures.push_back(f);
  BOARDCAST(addFailure(*f));
}

namespace {
  TestFailure* failure(
      const TestFunctor& f,
      const char* why,
      const char* where,
      const char* what) {
    return new TestFailure
      (f.getTestName(), std::string(why) + where + what, true);
  }

  TestFailure* error(
      const TestFunctor& f,
      const char* why,
      const char* where,
      const char* what) {
    return new TestFailure
      (f.getTestName(), std::string(why) + where + what, false);
  }
}

bool TestResult::protect(const TestFunctor& f, const char* where) {
  try {
    return f();
  } catch (const AssertionError& e) {
    addFailure(failure(f, "assertion fail", where, e.what()));
  } catch (const std::exception& e) {
    addFailure(error(f, "uncaught std::exception", where, e.what()));
  } catch (...) {
    addFailure(error(f, "uncaught unknown exception", where, ""));
  }
  return false;
}
