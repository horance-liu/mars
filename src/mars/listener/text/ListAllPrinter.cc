#include "mars/listener/text/ListAllPrinter.h"
#include "mars/core/Test.h"

ListAllPrinter::ListAllPrinter(std::ostream& out) : out(out) {
}

void ListAllPrinter::startTestSuite(const Test& test) {
  if (test.getName() != "All Tests") {
    out << test.getName() << ":" << std::endl;
  }
}

namespace {
  std::string shortName(const std::string& name) {
    auto pos = name.find_first_of("::");
    return pos != std::string::npos ? name.substr(pos + 2) : name;
  }
}

void ListAllPrinter::startTestCase(const Test& test) {
  out << "  " << shortName(test.getName()) << std::endl;
}
