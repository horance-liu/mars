#include "mars/core/TestResult.h"
#include "mars/core/BareTestCase.h"
#include "mars/core/BareTestSuite.h"
#include "mars/core/Test.h"
#include "mars/core/TestFunctor.h"
#include "mars/core/TestListener.h"
#include "mars/except/TestFailure.h"
#include "mars/except/TestFailureOp.h"
#include "mars/except/AssertionError.h"

namespace {
  TestListener& ref(TestListener* listener) {
    return listener != nullptr ? *listener : TestListener::none();
  }
}

TestResult::TestResult(TestListener* listener)
  : runTests(0), listener(ref(listener)) {
}

void TestResult::listFailures(const TestFailureOp& op) const {
  for (auto f : failures) {
    op(f);
  }
}

template <typename F>
void TestResult::foreachFailures(F f) const {
  struct Op : TestFailureOp {
    explicit Op(F f) : f(f) {}

  private:
    void operator()(TestFailure* failure) const override {
      f(failure);
    }

  private:
    F f;
  } op(f);

  listFailures(op);
}

TestResult::~TestResult() {
  foreachFailures([](auto f){
    delete f;
  });
}

int TestResult::runCount() const {
  return runTests;
}

void TestResult::runRootTest(Test& test) {
  listener.startTestRun(test, *this);
  test.run(*this);
  listener.endTestRun(test, *this);
}

void TestResult::runTestCase(BareTestCase& test) {
  runTests++;
  listener.startTestCase(test.get());
  test.runBare(*this);
  listener.endTestCase(test.get());
}

void TestResult::runTestSuite(BareTestSuite& test) {
  listener.startTestSuite(test.get());
  test.runBare(*this);
  listener.startTestSuite(test.get());
}

void TestResult::addFailure(TestFailure* f) {
  failures.push_back(f);
}

int TestResult::failureCount() const {
  auto num = 0;
  foreachFailures([&num](auto f) {
    if (f->isFailure()) num++;
  });
  return num;
}

int TestResult::errorCount() const {
  auto num = 0;
  foreachFailures([&num](auto f) {
    if (!f->isFailure()) num++;
  });
  return num;
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
