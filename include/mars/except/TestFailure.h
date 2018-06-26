#ifndef INCLUDE_MARS_EXCEPT_TESTFAILURE_H_
#define INCLUDE_MARS_EXCEPT_TESTFAILURE_H_

#include <string>

struct TestFailure {
  TestFailure(const std::string& name, const std::string& msg, bool failure);

  const std::string& getTestName() const;
  const std::string& getExceptionMsg() const;
  bool isFailure() const;

private:
  std::string name;
  std::string msg;
  bool failure;
};

#endif
