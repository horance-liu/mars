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
}

TEST_F(ColorfulPrinterSpec, print_colorful_test_report) {
  TestSuite suite("suite");
  suite.add(new TestCase("1"));
  suite.add(new TestCase("2"));
  suite.add(new TestCase("3"));

  result.runRootTest(suite);
}
