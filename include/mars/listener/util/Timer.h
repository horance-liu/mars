#ifndef INCLUDE_MARS_LISTENER_UTIL_TIMER_H_
#define INCLUDE_MARS_LISTENER_UTIL_TIMER_H_

#include <sys/time.h>

struct Timer {
  void start();
  timeval elapsed() const;

private:
  timeval startTime;
};

#endif
