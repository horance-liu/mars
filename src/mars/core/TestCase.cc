#include "mars/core/TestCase.h"

void TestCase::run(TestResult& result) {
  setUp();
  runTest();
  tearDown();
}
