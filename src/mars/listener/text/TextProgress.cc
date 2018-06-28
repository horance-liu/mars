#include "mars/listener/text/TextProgress.h"
#include "mars/except/TestFailure.h"

TextProgress::TextProgress(std::ostream& out) : out(out) {
}

void TextProgress::startTestCase(const Test&) {
  out << '.';
}

void TextProgress::addFailure(const TestFailure& failure) {
  out << (failure.isFailure() ? 'F' : 'E');
}

void TextProgress::endTestRun(const Test&) {
  out << std::endl;
  out.flush();
}
