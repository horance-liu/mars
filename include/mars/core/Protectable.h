#ifndef INCLUDE_MARS_CORE_PROTECTABLE_H_
#define INCLUDE_MARS_CORE_PROTECTABLE_H_

struct TestFunctor;

struct Protectable {
  virtual ~Protectable() {}
  virtual bool protect(const TestFunctor& f, const char* where) = 0;
};

#endif
