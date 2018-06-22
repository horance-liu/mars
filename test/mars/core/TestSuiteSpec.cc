#include <gtest/gtest.h>
#include "mars/core/TestCase.h"
#include "mars/core/TestSuite.h"

namespace {
  static int num = 0;

  struct AdditionTest : TestCase {
  private:
    void runTest() override {
      num++;
      ASSERT_EQ(20, base + 10);
    }

  private:
    int base = 10;
  };

  struct SubtractionTest : TestCase {
  private:
    void runTest() override {
      num++;
      ASSERT_EQ(0, base - 10);
    }

  private:
    int base = 10;
  };

  void run(Test& test) {
    test.run();
  }

  struct TestSuiteSpec : testing::Test {
  private:
    void SetUp() override {
      num = 0;
    }
  };
}

TEST_F(TestSuiteSpec, run_multi_test_cases_using_test_suite) {
  TestSuite suite;
  suite.add(new AdditionTest);
  suite.add(new SubtractionTest);

  run(suite);

  ASSERT_EQ(2, num);
}

TEST_F(TestSuiteSpec, package_test_suite_into_another_test_suite) {
  TestSuite *inner = new TestSuite;
  inner->add(new AdditionTest);

  TestSuite outter;
  outter.add(new SubtractionTest);
  outter.add(inner);

  run(outter);

  ASSERT_EQ(2, num);
}
