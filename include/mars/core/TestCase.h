#ifndef UUID_A5E84C94_CA28_4032_8014_2762BCE2D88F
#define UUID_A5E84C94_CA28_4032_8014_2762BCE2D88F

#include "mars/core/Test.h"
#include "mars/core/internal/BareTestCase.h"

struct TestFailure;

struct TestCase : Test, private BareTestCase {
  TestCase(const std::string& name = "");

private:
  const std::string& getName() const override;
  int countTestCases() const override;
  void run(TestResult&) override;

private:
  const Test& get() const override;
  void runBare(Protectable&) override;

private:
  virtual void setUp() {}
  virtual void runTest() {}
  virtual void tearDown() {}

private:
  TestFailure* failure(const std::string&);
  TestFailure* error(const std::string&);

  struct Functor;

private:
  std::string name;
};

#endif
