#include "mars/listener/util/Timer.h"

namespace {
  timeval subtime(const timeval& end, const timeval& start) {
    timeval tv = end;
    while (tv.tv_usec < start.tv_usec) {
      tv.tv_usec += 1000000;
      tv.tv_sec--;
    }

    tv.tv_usec -= start.tv_usec;
    tv.tv_sec -= start.tv_sec;

    return tv;
  }
}

void Timer::start() {
  gettimeofday(&startTime, 0);
}

timeval Timer::elapsed() const {
  timeval tv;
  gettimeofday(&tv, 0);
  return subtime(tv, startTime);
}
