#ifndef INCLUDE_MARS_CORE_TESTFAILUREOP_H_
#define INCLUDE_MARS_CORE_TESTFAILUREOP_H_

struct TestFailure;

struct TestFailureOp {
  virtual ~TestFailureOp() {}

  virtual void operator()(TestFailure*) const = 0;
};

#endif
