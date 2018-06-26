#ifndef INCLUDE_MARS_CORE_BARETESTCASE_H_
#define INCLUDE_MARS_CORE_BARETESTCASE_H_

struct Test;
struct Protectable;

struct BareTestCase {
  virtual ~BareTestCase() {}

  virtual const Test& get() const = 0;
  virtual void runBare(Protectable&) = 0;
};

#endif
