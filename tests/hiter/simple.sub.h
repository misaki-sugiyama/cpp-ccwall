#pragma once
#include "ccwall/hiter.h"

#include <utility>

class IterSListInt : public ::ccwall::HiddenIter<IterSListInt, int> {
public:
  using HiddenIter::HiddenIter;
};

class IterMapIntBool : public ::ccwall::HiddenIter<IterMapIntBool, std::pair<const int, bool>> {
public:
  using HiddenIter::HiddenIter;
};
