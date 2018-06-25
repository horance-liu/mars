#include <gtest/gtest.h>
#include "mars/core/TestCase.h"
#include "mars/core/TestResult.h"
#include "mars/core/AssertionFailedError.h"

namespace {
  struct TestCaseSpec : testing::Test {
  protected:
    void run(::Test& test) {
      test.run(result);
    }

  protected:
    TestResult result;
  };

}

namespace {
  struct SimpleTest : TestCase {
    bool wasSetUp = false;
    bool wasRun = false;
    bool wasTearDown = false;

  private:
    void setUp() override {
      wasSetUp = true;
    }

    void runTest() override {
      wasRun = true;
    }

    void tearDown() override {
      wasTearDown = true;
    }
  };
}

TEST_F(TestCaseSpec, make_sure_test_case_can_run_normally) {
  SimpleTest test;
  run(test);

  ASSERT_TRUE(test.wasSetUp);
  ASSERT_TRUE(test.wasRun);
  ASSERT_TRUE(test.wasTearDown);
  ASSERT_EQ(1, result.runCount());
}

namespace {
  struct FailedTest : TestCase {
    bool wasSetUp = false;

  private:
    void runTest() override {
      throw AssertionFailedError("test.cpp:12", "expected value == 2, but got 3");
    }
  };
}

TEST_F(TestCaseSpec, test_case_assert_failed_and_throw_assertion_failed_error) {
  FailedTest test;
  run(test);

  ASSERT_EQ(1, result.failureCount());
}
