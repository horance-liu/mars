#ifndef INCLUDE_MARS_CORE_ASSERTIONFAILEDERROR_H_
#define INCLUDE_MARS_CORE_ASSERTIONFAILEDERROR_H_

#include <exception>
#include <string>

struct AssertionFailedError : std::exception {
  AssertionFailedError(const std::string& src, const std::string& msg);
  ~AssertionFailedError() noexcept = default;

  AssertionFailedError(const AssertionFailedError&) noexcept = default;
  AssertionFailedError& operator=(const AssertionFailedError&) noexcept = default;

  const char* what() const noexcept override;

private:
  std::string msg;
};

#endif
