#include "mars/core/TestCase.h"
#include "mars/core/TestResult.h"
#include "mars/core/internal/Protectable.h"
#include "mars/core/internal/TestFunctor.h"

TestCase::TestCase(const std::string& name) : name(name) {
}

const std::string& TestCase::getName() const {
  return name;
}

int TestCase::countTestCases() const {
  return 1;
}

void TestCase::run(TestResult& result) {
  result.runTestCase(*this);
}

const Test& TestCase::get() const {
  return *this;
}

struct TestCase::Functor : TestFunctor {
  using Method = void(TestCase::*)();

  Functor(TestCase& self, Method method)
    : self(self), method(method) {
  }

private:
  const std::string& getTestName() const override {
    return self.getName();
  }

  bool operator()() const override {
    (self.*method)();
    return true;
  }

private:
  TestCase& self;
  Method method;
};

#define PROTECT(method) \
    p.protect(Functor(*this, &TestCase::method), " in the "#method)

void TestCase::runBare(Protectable& p) {
  if (PROTECT(setUp)) {
    PROTECT(runTest);
  }
  PROTECT(tearDown);
}
