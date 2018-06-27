#include "mars/core/TestSuite.h"
#include "mars/core/TestResult.h"

TestSuite::TestSuite(const std::string& name) : name(name) {
}

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

const std::string& TestSuite::getName() const {
  return name;
}

int TestSuite::countTestCases() const {
  return tests.size();
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
