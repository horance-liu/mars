#include <gtest/gtest.h>
#include "mars/core/TestCase.h"
#include "mars/core/TestResult.h"

namespace {
  struct AdditionTest : TestCase {
  private:
    void setUp() override {
      base = new int(10);
    }

    void runTest() override {
      ASSERT_EQ(20, *base + 10);
    }

    void tearDown() override {
      delete base;
    }

  private:
    int* base = nullptr;
  };

  struct TestCaseSpec : testing::Test {
  protected:
    void run(::Test& test) {
      test.run(result);
    }

  protected:
    TestResult result;
  };

}

TEST_F(TestCaseSpec, sum_of_two_integers) {
  AdditionTest test;
  run(test);

  ASSERT_EQ(1, result.runCount());
}
