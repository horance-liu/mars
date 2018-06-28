#ifndef INCLUDE_MARS_CORE_BARETESTCASE_H_
#define INCLUDE_MARS_CORE_BARETESTCASE_H_

struct Test;
struct TestProtector;

struct BareTestCase {
  virtual ~BareTestCase() {}

  virtual const Test& get() const = 0;
  virtual void runBare(TestProtector&) = 0;
};

#endif
