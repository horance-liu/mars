#ifndef INCLUDE_MARS_CORE_TESTCOLLECTOR_H_
#define INCLUDE_MARS_CORE_TESTCOLLECTOR_H_

struct Test;
struct BareTestCase;
struct BareTestSuite;
struct TestFailureOp;

struct TestCollector {
  virtual ~TestCollector() {}

  bool wasSuccessful() const {
    return failureCount() == 0 && errorCount() == 0;
  }

  virtual int runCount() const = 0;
  virtual int failureCount() const = 0;
  virtual int errorCount() const = 0;
  virtual void listFailures(const TestFailureOp&) const = 0;

  virtual void runRootTest(Test&) = 0;
  virtual void runTestCase(BareTestCase&) = 0;
  virtual void runTestSuite(BareTestSuite&) = 0;
};

#endif
