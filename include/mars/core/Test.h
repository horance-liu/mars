#ifndef UUID_CBABF60A_A645_46EC_8402_6E559233E074
#define UUID_CBABF60A_A645_46EC_8402_6E559233E074

struct TestResult;

struct Test {
  virtual ~Test() {}
  virtual void run(TestResult& result) = 0;
};

#endif
