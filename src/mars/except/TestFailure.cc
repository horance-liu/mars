#include "mars/except/TestFailure.h"

TestFailure::TestFailure
  ( const std::string& name, const std::string& msg, bool failure)
  : name(name), msg(msg), failure(failure) {
}

const std::string& TestFailure::getTestName() const {
  return name;
}

const std::string& TestFailure::getExceptionMsg() const {
  return msg;
}

bool TestFailure::isFailure() const {
  return failure;
}
