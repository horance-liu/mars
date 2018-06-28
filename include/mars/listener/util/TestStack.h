#ifndef INCLUDE_MARS_LISTENER_UTIL_TESTSTACK_H_
#define INCLUDE_MARS_LISTENER_UTIL_TESTSTACK_H_

#include <stack>

template <typename TestInfo>
struct TestStack {
  void push(TestInfo* test) {
    tests.push(test);
  }

  void pop() {
    auto top = tests.top();
    tests.pop();
    delete top;
  }

  TestInfo& top() const {
    return *tests.top();
  }

private:
  std::stack<TestInfo*> tests;
};


#endif
