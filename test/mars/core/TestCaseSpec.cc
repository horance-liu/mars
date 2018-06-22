#include <gtest/gtest.h>
#include "mars/core/TestCase.h"

namespace {
  struct AdditionTest : TestCase {
    void run() override {
      ASSERT_EQ(2, 1 + 1);
    }
  };

  void run(TestCase& test) {
    test.run();
  }
}

TEST(AdditionTest, sum_of_two_integers) {
  AdditionTest test;
  run(test);
}
