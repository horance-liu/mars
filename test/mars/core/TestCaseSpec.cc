#include <gtest/gtest.h>
#include "mars/core/TestCase.h"

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
}

TEST(AdditionTest, sum_of_two_integers) {
  AdditionTest test;
  test.run();
}
