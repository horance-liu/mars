#include "mars/core/TestSuite.h"
#include "mars/core/TestResult.h"

void TestSuite::add(Test* test) {
  tests.push_back(test);
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

void TestSuite::run(TestResult& result) {
  foreach([&result](Test* test) {
    test->run(result);
  });
}