#include <gtest/gtest.h>
#include <mars/listener/text/TextProgress.h>

#include "mars/core/TestCase.h"
#include "mars/core/TestResult.h"
#include "mars/core/TestSuite.h"
#include "mars/except/AssertionError.h"
#include "mars/listener/text/ColorfulPrinter.h"
#include "mars/listener/text/ListAllPrinter.h"

namespace {
  struct TextPrinterSpec : testing::Test {
  protected:
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

TEST_F(TextPrinterSpec, print_colorful_test_report) {
  ColorfulPrinter printer;
  result.addListener(&printer);

  TestSuite suite("suite");
  suite.add(new AssertionFailedTest("failed test"));
  suite.add(new TestCase("succ 2"));
  suite.add(new TestCase("succ 3"));

  result.runRootTest(suite);
}

TEST_F(TextPrinterSpec, list_all_tests) {
  ListAllPrinter printer;
  result.addListener(&printer);

  TestSuite suite("suite");
  suite.add(new AssertionFailedTest("failed test"));
  suite.add(new TestCase("succ 2"));
  suite.add(new TestCase("succ 3"));

  result.runRootTest(suite);
}

TEST_F(TextPrinterSpec, print_simple_test_progress) {
  TextProgress progress;
  result.addListener(&progress);

  TestSuite suite("suite");
  suite.add(new AssertionFailedTest("failed test"));
  suite.add(new TestCase("succ 2"));
  suite.add(new TestCase("succ 3"));

  result.runRootTest(suite);
}
