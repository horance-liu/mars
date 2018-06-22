#ifndef UUID_A5E84C94_CA28_4032_8014_2762BCE2D88F
#define UUID_A5E84C94_CA28_4032_8014_2762BCE2D88F

struct TestCase {
  virtual ~TestCase() {}
  virtual void run() = 0;
};

#endif
