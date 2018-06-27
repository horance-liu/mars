#include "mars/listener/collector/FailureLister.h"

void FailureLister::addFailure(const TestFailure& listener) {
  failures.push_back(&listener);
}
