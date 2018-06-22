#ifndef UUID_18819C28_B404_45A7_BCB9_E2A39A447ECF
#define UUID_18819C28_B404_45A7_BCB9_E2A39A447ECF

#include <vector>
#include "mars/core/Test.h"

struct TestSuite : Test {
  ~TestSuite();

  void add(Test* test);

private:
  void run(TestResult& result) override;

private:
  template <typename F>
  void foreach(F f);

private:
  std::vector<Test*> tests;
};

#endif
