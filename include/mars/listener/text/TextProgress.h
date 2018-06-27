#ifndef INCLUDE_MARS_LISTENER_TEXTPROGRESSLISTENER_H_
#define INCLUDE_MARS_LISTENER_TEXTPROGRESSLISTENER_H_

#include <iostream>
#include "mars/core/TestListener.h"

struct TextProgress : TestListener {
  explicit TextProgress(std::ostream& = std::cout);

private:
  void startTestCase(const Test&) override;
  void addFailure(const TestFailure&) override;
  void endTestRun(const Test&) override;

private:
  std::ostream& out;
};

#endif
