#ifndef INCLUDE_MARS_LISTENER_TEXT_LISTALLPRINTER_H_
#define INCLUDE_MARS_LISTENER_TEXT_LISTALLPRINTER_H_

#include <iostream>
#include "mars/core/TestListener.h"

struct ListAllPrinter : TestListener {
  explicit ListAllPrinter(std::ostream& = std::cout);

private:
  void startTestSuite(const Test&) override;
  void startTestCase(const Test&) override;

private:
  std::ostream& out;
};

#endif
