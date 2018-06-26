#ifndef UUID_18819C28_B404_45A7_BCB9_E2A39A447ECF
#define UUID_18819C28_B404_45A7_BCB9_E2A39A447ECF

#include <string>
#include <vector>
#include "mars/core/Test.h"
#include "mars/core/BareTestSuite.h"

struct TestSuite : Test, private BareTestSuite {
  explicit TestSuite(const std::string& name = "");
  ~TestSuite();

  void add(Test* test);

private:
  const std::string& getName() const override;
  void run(TestCollector&) override;

private:
  const Test& get() const override;
  void runBare(TestResult&) override;

private:
  template <typename F>
  void foreach(F f) const;

private:
  std::string name;
  std::vector<Test*> tests;
};

#endif
