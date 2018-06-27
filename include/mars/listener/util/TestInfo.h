#ifndef INCLUDE_MARS_LISTENER_UTIL_TESTINFO_H_
#define INCLUDE_MARS_LISTENER_UTIL_TESTINFO_H_

#include <memory>
#include "mars/listener/util/Timer.h"

struct TestInfo {
  TestInfo();

  void onFailure();
  void onError();

  bool isSucc() const;
  bool isFailure() const;
  bool isError() const;
  timeval elapsedTime();

private:
  bool succ;
  bool failure;
  bool error;
  Timer timer;
};

#endif
