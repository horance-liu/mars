#ifndef INCLUDE_MARS_CORE_TESTRESULT_H_
#define INCLUDE_MARS_CORE_TESTRESULT_H_

#include <vector>
#include <string>

struct TestResult {
  TestResult();

  void run();

  int runCount() const;
  int failureCount() const;

private:
  int runTests;
  std::vector<std::string> failures;
};

#endif
