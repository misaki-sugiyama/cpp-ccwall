#pragma once
#include "ccwall/pimpl.h"

class TestCpMv {
private:
  class Impl;
  ccwall::PImpl<Impl> pimpl;
public:
  TestCpMv();
  TestCpMv(int a);

  ~TestCpMv();
  TestCpMv(TestCpMv&& rhs) noexcept;
  TestCpMv& operator=(TestCpMv&& rhs) noexcept;
  TestCpMv(const TestCpMv& rhs);
  TestCpMv& operator=(const TestCpMv& rhs);

  int* getPtr();
};
