#include "mars/core/TestListener.h"

TestListener& TestListener::none() {
  static TestListener listener;
  return listener;
}
