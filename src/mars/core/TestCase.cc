#include "mars/core/TestCase.h"
#include "mars/core/TestResult.h"
#include "mars/except/AssertionError.h"
#include "mars/except/TestFailure.h"

TestCase::TestCase(const std::string& name) : name(name) {
}

TestFailure* TestCase::failure(const std::string& msg) {
  return new TestFailure(name, msg, true);
}

TestFailure* TestCase::error(const std::string& msg) {
  return new TestFailure(name, msg, false);
}


void TestCase::runBare(TestResult& result) {
  auto ready = true;
  try {
    setUp();
  } catch (const AssertionError& e) {
    result.addFailure(failure(std::string("assertion fail in setUp\n") + e.what()));
    ready = false;
  } catch (const std::exception& e) {
    result.addFailure(error(std::string("uncaught std::exception in setUp\n") + e.what()));
    ready = false;
  } catch (...) {
    result.addFailure(error(std::string("unknown exception in setUp\n")));
    ready = false;
  }

  if (ready) {
    try {
      runTest();
    } catch (const AssertionError& e) {
      result.addFailure(failure(std::string("assertion fail in runTest\n") + e.what()));
    } catch (const std::exception& e) {
      result.addFailure(error(std::string("uncaught std::exception in runTest\n") + e.what()));
    } catch (...) {
      result.addFailure(error(std::string("unknown exception in runTest\n")));
    }
  }

  try {
    tearDown();
  } catch (const AssertionError& e) {
    result.addFailure(failure(std::string("assertion fail in tearDown\n") + e.what()));
  } catch (const std::exception& e) {
    result.addFailure(error(std::string("uncaught std::exception in tearDown\n") + e.what()));
  } catch (...) {
    result.addFailure(error(std::string("unknown exception in tearDown\n")));
  }
}

void TestCase::run(TestResult& result) {
  result.run();
  runBare(result);
}
