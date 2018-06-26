#include <gtest/gtest.h>

#include "mars/core/TestCase.h"
#include "mars/core/TestResult.h"
#include "mars/except/AssertionError.h"

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
  struct AssertionFailedTest : TestCase {
    bool wasTearDown = false;

    void runTest() override {
      throw AssertionError("test.cpp:57", "expected value == 2, but got 3");
    }

    void tearDown() override {
      wasTearDown = true;
    }
  };
}

TEST_F(TestCaseSpec, throw_assertion_error_on_run_test) {
  AssertionFailedTest test;
  run(test);

  ASSERT_TRUE(test.wasTearDown);
  ASSERT_EQ(1, result.failureCount());
  ASSERT_EQ(0, result.errorCount());
}

namespace {
  struct AssertionFailedOnSetUpTest : TestCase {
    bool wasRun = false;

    void setUp() override {
      throw AssertionError("test.cpp:57", "expected value == 2, but got 3");
    }

    void runTest() override {
      wasRun = true;
    }
  };
}

TEST_F(TestCaseSpec, throw_assertion_error_on_setup) {
  AssertionFailedOnSetUpTest test;
  run(test);

  ASSERT_FALSE(test.wasRun);
  ASSERT_EQ(1, result.failureCount());
  ASSERT_EQ(0, result.errorCount());
}

namespace {
  struct AssertionFailedOnTearDownTest : TestCase {
    void tearDown() override {
      throw AssertionError("test.cpp:57", "expected value == 2, but got 3");
    }
  };
}

TEST_F(TestCaseSpec, throw_assertion_error_on_tear_down) {
  AssertionFailedOnTearDownTest test;
  run(test);

  ASSERT_EQ(1, result.failureCount());
  ASSERT_EQ(0, result.errorCount());
}

namespace {
  struct StdExceptionTest : TestCase {
    void runTest() override {
      throw std::exception();
    }
  };
}

TEST_F(TestCaseSpec, throw_std_exception_on_run_test) {
  StdExceptionTest test;
  run(test);

  ASSERT_EQ(0, result.failureCount());
  ASSERT_EQ(1, result.errorCount());
}

namespace {
  struct StdExceptionOnSetUpTest : TestCase {
    void setUp() override {
      throw std::exception();
    }
  };
}

TEST_F(TestCaseSpec, throw_std_exception_on_setup) {
  StdExceptionOnSetUpTest test;
  run(test);

  ASSERT_EQ(0, result.failureCount());
  ASSERT_EQ(1, result.errorCount());
}

namespace {
  struct StdExceptionOnTearDownTest : TestCase {
    void tearDown() override {
      throw std::exception();
    }
  };
}

TEST_F(TestCaseSpec, throw_std_exception_on_tear_down) {
  StdExceptionOnTearDownTest test;
  run(test);

  ASSERT_EQ(0, result.failureCount());
  ASSERT_EQ(1, result.errorCount());
}

namespace {
  struct UnknownExceptionTest : TestCase {
    void runTest() override {
      throw std::out_of_range("overflow");
    }
  };
}

TEST_F(TestCaseSpec, throw_unknown_exception_on_run_test) {
  UnknownExceptionTest test;
  run(test);

  ASSERT_EQ(0, result.failureCount());
  ASSERT_EQ(1, result.errorCount());
}

namespace {
  struct UnknownExceptionOnSetUpTest : TestCase {
    void setUp() override {
      throw std::out_of_range("overflow");
    }
  };
}

TEST_F(TestCaseSpec, throw_unknown_exception_on_setup) {
  UnknownExceptionOnSetUpTest test;
  run(test);

  ASSERT_EQ(0, result.failureCount());
  ASSERT_EQ(1, result.errorCount());
}

namespace {
  struct UnknownExceptionOnTearDownTest : TestCase {
    void tearDown() override {
      throw std::out_of_range("overflow");
    }
  };
}

TEST_F(TestCaseSpec, throw_unknown_exception_on_tear_down) {
  UnknownExceptionOnTearDownTest test;
  run(test);

  ASSERT_EQ(0, result.failureCount());
  ASSERT_EQ(1, result.errorCount());
}
