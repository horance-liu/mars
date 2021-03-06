#ifndef UUID_18819C28_B404_45A7_BCB9_E2A39A447ECF
#define UUID_18819C28_B404_45A7_BCB9_E2A39A447ECF

#include <vector>
#include "mars/core/Test.h"
#include "mars/core/internal/BareTestSuite.h"

struct TestSuite : Test, private BareTestSuite {
  using Test::Test;

  ~TestSuite();

  void add(Test* test);

private:
  int countTestCases() const override;
  void run(TestResult&) override;

private:
  const Test& get() const override;
  void runBare(TestResult&) override;

private:
  template <typename F>
  void foreach(F f) const;

private:
  std::vector<Test*> tests;
};

#endif
