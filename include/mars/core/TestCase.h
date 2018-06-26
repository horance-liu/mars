#ifndef UUID_A5E84C94_CA28_4032_8014_2762BCE2D88F
#define UUID_A5E84C94_CA28_4032_8014_2762BCE2D88F

#include <string>
#include "mars/core/Test.h"

struct TestFailure;

struct TestCase : Test {
  TestCase(const std::string& name = "");

private:
  void run(TestResult& result) override;

private:
  virtual void setUp() {}
  virtual void runTest() {}
  virtual void tearDown() {}

private:
  void runBare(TestResult&);

  TestFailure* failure(const std::string&);
  TestFailure* error(const std::string&);

private:
  std::string name;
};

#endif
