#include <gtest/gtest.h>

#include "mars/core/TestCase.h"
#include "mars/core/TestResult.h"
#include "mars/core/TestSuite.h"
#include "mars/except/AssertionError.h"
#include "mars/listener/text/ColorfulPrinter.h"

namespace {
  struct ColorfulPrinterSpec : testing::Test {
  private:
    void SetUp() override {
      result.addListener(&printer);
    }

  protected:
    ColorfulPrinter printer;
    TestResult result;
  };

  namespace {
    struct AssertionFailedTest : TestCase {
      using TestCase::TestCase;

      void runTest() override {
        throw AssertionError("test.cpp:57", "expected value == 2, but got 3");
      }
    };
  }
}

TEST_F(ColorfulPrinterSpec, print_colorful_test_report) {
  TestSuite suite("suite");
  suite.add(new AssertionFailedTest("failed test"));
  suite.add(new TestCase("succ 2"));
  suite.add(new TestCase("succ 3"));

  result.runRootTest(suite);
}


