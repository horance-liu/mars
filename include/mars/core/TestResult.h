#ifndef INCLUDE_MARS_CORE_TESTRESULT_H_
#define INCLUDE_MARS_CORE_TESTRESULT_H_

struct TestResult {
  TestResult();

  int runCount() const;
  void run();

private:
  int runTests;
};

#endif
