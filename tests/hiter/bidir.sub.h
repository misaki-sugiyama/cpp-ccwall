#pragma once
#include "ccwall/hiter.h"

#include <utility>

class IterVecInt : public ::ccwall::HiddenIterBi<IterVecInt, int> {
public:
  using HiddenIterBi::HiddenIterBi;
};
