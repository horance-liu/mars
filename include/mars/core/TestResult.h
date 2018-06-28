#ifndef INCLUDE_MARS_CORE_TESTRESULT_H_
#define INCLUDE_MARS_CORE_TESTRESULT_H_

#include <vector>
#include "mars/core/internal/TestProtector.h"
#include "mars/core/TestListener.h"

struct Test;
struct BareTestCase;
struct BareTestSuite;
struct TestFailure;

struct TestResult : private TestProtector {
  ~TestResult();

  void addListener(TestListener*);

  void runRootTest(Test&);
  void runTestCase(BareTestCase&);
  void runTestSuite(BareTestSuite&);

private:
  bool protect(const TestFunctor& f, const char* where) override;

private:
  void addFailure(TestFailure*);

private:
  std::vector<TestListener*> listeners;
  std::vector<TestFailure*> failures;
};

#endif
