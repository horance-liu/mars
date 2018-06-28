#include "mars/listener/util/Timer.h"

void Timer::start() {
  begin.now();
}

TimeVal Timer::elapsed() const {
  TimeVal end;
  end.now();
  return end -= begin;
}
