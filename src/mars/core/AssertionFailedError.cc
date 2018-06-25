#include "mars/core/AssertionFailedError.h"

AssertionFailedError::AssertionFailedError
  (const std::string& src, const std::string& msg) : msg(src + msg) {
}

const char* AssertionFailedError::what() const noexcept {
  return msg.c_str();
}
