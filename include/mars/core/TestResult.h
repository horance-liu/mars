#ifndef INCLUDE_MARS_CORE_TESTRESULT_H_
#define INCLUDE_MARS_CORE_TESTRESULT_H_

#include <vector>
#include <string>

#include "mars/core/TestCollector.h"
#include "mars/core/Protectable.h"

struct Test;
struct BareTestCase;
struct BareTestSuite;
struct TestFailure;
struct TestListener;

struct TestResult : TestCollector, private Protectable {
  TestResult(TestListener* = nullptr);
  ~TestResult();

private:
  int runCount() const override;
  int failureCount() const override;
  int errorCount() const override;
  void listFailures(const TestFailureOp&) const override;

  void runRootTest(Test&) override;
  void runTestCase(BareTestCase&) override;
  void runTestSuite(BareTestSuite&) override;

private:
  bool protect(const TestFunctor& f, const char* where) override;

private:
  void addFailure(TestFailure*);

  template <typename F>
  void foreachFailures(F f) const;

private:
  int runTests;
  TestListener& listener;
  std::vector<TestFailure*> failures;
};

#endif
