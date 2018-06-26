#ifndef INCLUDE_MARS_CORE_ASSERTIONERROR_H_
#define INCLUDE_MARS_CORE_ASSERTIONERROR_H_

#include <exception>
#include <string>

struct AssertionError : std::exception {
  AssertionError(const std::string& src, const std::string& msg);
  ~AssertionError() noexcept = default;

  const char* what() const noexcept;

private:
  std::string msg;
};

#endif
