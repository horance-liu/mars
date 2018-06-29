#ifndef UUID_CBABF60A_A645_46EC_8402_6E559233E074
#define UUID_CBABF60A_A645_46EC_8402_6E559233E074

#include <string>

struct TestResult;

struct Test {
  explicit Test(const std::string& name = "");
  virtual ~Test() {}

  const std::string& getName() const;

  virtual int countTestCases() const = 0;
  virtual void run(TestResult&) = 0;

private:
  std::string name;
};

#endif
