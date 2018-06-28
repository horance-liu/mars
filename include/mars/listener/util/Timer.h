#ifndef INCLUDE_MARS_LISTENER_UTIL_TIMER_H_
#define INCLUDE_MARS_LISTENER_UTIL_TIMER_H_

#include "mars/listener/util/TimeVal.h"

struct Timer {
  void start();
  TimeVal elapsed() const;

private:
  TimeVal begin;
};

#endif
