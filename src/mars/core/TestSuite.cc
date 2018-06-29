#include "mars/core/TestSuite.h"
#include "mars/core/TestResult.h"

template <typename F>
inline void TestSuite::foreach(F f) const {
  for (auto test : tests) {
    f(test);
  }
}

TestSuite::~TestSuite() {
  foreach([](Test* test) {
    delete test;
  });
}

void TestSuite::add(Test* test) {
  tests.push_back(test);
}

int TestSuite::countTestCases() const {
  auto num = 0;
  foreach([&num](Test* test) {
    num += test->countTestCases();
  });
  return num;
}

void TestSuite::run(TestResult& result) {
  result.runTestSuite(*this);
}

const Test& TestSuite::get() const {
  return *this;
}

void TestSuite::runBare(TestResult& result) {
  foreach([&result](Test* test) {
    test->run(result);
  });
}
