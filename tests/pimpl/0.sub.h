#pragma once
#include "ccwall/pimpl.h"

class Test0 {
private:
  class Impl;
  ccwall::PImpl<Impl> pimpl;
public:
  Test0();
  ~Test0();
  int run();
};
