#ifndef INCLUDE_MARS_CORE_TESTFUNCTOR_H_
#define INCLUDE_MARS_CORE_TESTFUNCTOR_H_

#include <string>

struct TestFunctor {
  virtual ~TestFunctor() {}

  virtual const std::string& getTestName() const = 0;
  virtual bool operator()() const = 0;
};

#endif
