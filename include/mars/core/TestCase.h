#ifndef UUID_A5E84C94_CA28_4032_8014_2762BCE2D88F
#define UUID_A5E84C94_CA28_4032_8014_2762BCE2D88F

#include "mars/core/Test.h"
#include "mars/core/internal/BareTestCase.h"

struct TestCase : Test, private BareTestCase {
  using Test::Test;

private:
  int countTestCases() const override;
  void run(TestResult&) override;

private:
  const Test& get() const override;
  void runBare(TestProtector&) override;

private:
  virtual void setUp() {}
  virtual void runTest() {}
  virtual void tearDown() {}

private:
  struct Functor;
};

#endif
