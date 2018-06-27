#ifndef INCLUDE_MARS_CORE_TESTLISTENER_H_
#define INCLUDE_MARS_CORE_TESTLISTENER_H_

struct Test;
struct TestFailure;

struct TestListener {
  virtual ~TestListener() {}

  virtual void startTestRun(const Test&) {}
  virtual void endTestRun(const Test&) {}

  virtual void startTestSuite(const Test&) {}
  virtual void endTestSuite(const Test&) {}

  virtual void startTestCase(const Test&) {}
  virtual void endTestCase(const Test&) {}

  virtual void addFailure(const TestFailure&) {}

  static TestListener& none();
};



#endif
