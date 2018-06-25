#include <gtest/gtest.h>
#include "mars/core/TestCase.h"
#include "mars/core/TestSuite.h"
#include "mars/core/TestResult.h"

namespace {
  struct AdditionTest : TestCase {
  private:
    void runTest() override {
      ASSERT_EQ(20, 10 + 10);
    }
  };

  struct SubtractionTest : TestCase {
  private:
    void runTest() override {
      ASSERT_EQ(0, 10 - 10);
    }
  };

  struct TestSuiteSpec : testing::Test {
    void run(::Test& test) {
      test.run(result);
    }

  protected:
    TestResult result;
  };
}

TEST_F(TestSuiteSpec, run_multi_test_cases_using_test_suite) {
  TestSuite suite;
  suite.add(new AdditionTest);
  suite.add(new SubtractionTest);

  run(suite);

  ASSERT_EQ(2, result.runCount());
}

TEST_F(TestSuiteSpec, package_test_suite_into_another_test_suite) {
  TestSuite *inner = new TestSuite;
  inner->add(new AdditionTest);

  TestSuite outter;
  outter.add(new SubtractionTest);
  outter.add(inner);

  run(outter);

  ASSERT_EQ(2, result.runCount());
}
