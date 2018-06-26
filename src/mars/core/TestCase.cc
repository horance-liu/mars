#include "mars/core/TestCase.h"
#include "mars/core/TestResult.h"
#include "mars/core/Protectable.h"
#include "mars/core/TestFunctor.h"

TestCase::TestCase(const std::string& name) : name(name) {
}

const std::string& TestCase::getName() const {
  return name;
}

void TestCase::run(TestCollector& collector) {
  collector.runTestCase(*this);
}

struct TestCase::Functor : TestFunctor {
  using Method = void(TestCase::*)();

  Functor(TestCase& test, Method method)
    : test(test), method(method) {
  }

private:
  const std::string& getTestName() const override {
    return test.getName();
  }

  bool operator()() const override {
    (test.*method)();
    return true;
  }

private:
  TestCase& test;
  Method method;
};

const Test& TestCase::get() const {
  return *this;
}

#define PROTECT(method) \
    p.protect(Functor(*this, &TestCase::method), " in the "#method)

void TestCase::runBare(Protectable& p) {
  if (PROTECT(setUp)) {
    PROTECT(runTest);
  }
  PROTECT(tearDown);
}
