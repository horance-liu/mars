#ifndef UUID_A5E84C94_CA28_4032_8014_2762BCE2D88F
#define UUID_A5E84C94_CA28_4032_8014_2762BCE2D88F

#include "mars/core/Test.h"

struct TestCase : Test {

  void runBare();

private:
  void run(TestResult& result) override;

private:
  virtual void setUp() {}
  virtual void runTest() {}
  virtual void tearDown() {}
};

#endif
