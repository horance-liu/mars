#ifndef INCLUDE_MARS_CORE_TESTRESULT_H_
#define INCLUDE_MARS_CORE_TESTRESULT_H_

#include <vector>
#include <string>

struct TestFailure;
struct TestFailureOp;

struct TestResult {
  TestResult();
  ~TestResult();

  void run();

  int runCount() const;
  int failureCount() const;
  int errorCount() const;

  void addFailure(TestFailure*);

  template <typename F>
  void listFailures(F f) const {
    for (auto failure : failures) {
      f(failure);
    }
  }

private:
  int runTests;
  std::vector<TestFailure*> failures;
};

#endif
