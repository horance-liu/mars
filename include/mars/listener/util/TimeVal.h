#ifndef INCLUDE_MARS_LISTENER_UTIL_TIMEVAL_H_
#define INCLUDE_MARS_LISTENER_UTIL_TIMEVAL_H_

#include <time.h>
#include <string>

struct TimeVal : private timeval {
  TimeVal();

  void reset();
  void now();

  TimeVal& operator+=(const TimeVal&);
  TimeVal& operator-=(const TimeVal&);

  std::string toString() const;
};

#endif
