#ifndef INCLUDE_MARS_CORE_BARETESTSUITE_H_
#define INCLUDE_MARS_CORE_BARETESTSUITE_H_

struct TestResult;

struct BareTestSuite {
  virtual ~BareTestSuite() {}

  virtual const Test& get() const = 0;
  virtual void runBare(TestResult&) = 0;
};

#endif
