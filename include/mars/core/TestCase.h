#ifndef UUID_A5E84C94_CA28_4032_8014_2762BCE2D88F
#define UUID_A5E84C94_CA28_4032_8014_2762BCE2D88F

#include <string>

#include "mars/core/BareTestCase.h"
#include "mars/core/Test.h"

struct TestFailure;

struct TestCase : Test, private BareTestCase {
  TestCase(const std::string& name = "");

private:
  const std::string& getName() const override;
  void run(TestCollector&) override;

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
