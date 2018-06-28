#include "mars/listener/util/TimeVal.h"
#include <sstream>
#include <sys/time.h>

TimeVal::TimeVal() {
  reset();
}

void TimeVal::reset() {
  tv_sec  = 0;
  tv_usec = 0;
}

void TimeVal::now() {
  gettimeofday(this, 0);
}

TimeVal& TimeVal::operator+=(const TimeVal& rhs) {
  tv_sec  += rhs.tv_sec;
  tv_usec += rhs.tv_usec;
  return *this;
}

TimeVal& TimeVal::operator-=(const TimeVal& start) {
  while (tv_usec < start.tv_usec) {
    tv_usec += 1000000;
    tv_sec--;
  }

  tv_usec -= start.tv_usec;
  tv_sec  -= start.tv_sec;

  return *this;
}

std::string TimeVal::toString() const {
  std::stringstream ss;

  if (tv_sec > 0) {
    ss << tv_sec << " s ";
  }
  ss << tv_usec << " us";

  return ss.str();
}
