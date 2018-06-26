#include <gtest/gtest.h>
#include "mars/core/TestCase.h"
#include "mars/core/TestSuite.h"
#include "mars/core/TestResult.h"

namespace {
  struct TestSuiteSpec : testing::Test {
    TestSuiteSpec() : collector(result) {
    }

    void run(::Test& test) {
      test.run(result);
    }

  protected:
    TestResult result;
    TestCollector& collector;
  };
}

TEST_F(TestSuiteSpec, run_multi_test_cases_using_test_suite) {
  TestSuite suite;
  suite.add(new TestCase);
  suite.add(new TestCase);

  run(suite);

  ASSERT_EQ(2, collector.runCount());
}

TEST_F(TestSuiteSpec, package_test_suite_into_another_test_suite) {
  auto inner = new TestSuite;
  inner->add(new TestCase);

  TestSuite outter;
  outter.add(new TestCase);
  outter.add(inner);

  run(outter);

  ASSERT_EQ(2, collector.runCount());
}
