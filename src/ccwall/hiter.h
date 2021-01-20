// A wrapper to hide the underlying iterator implementation
#pragma once
#include "ccwall/pimpl.h"

namespace ccwall {

  // The simplest case: uni-directional non-random-access read-only iterator
  template <typename Derived, typename T>
  class HiddenIter {
  public:
    HiddenIter();
    HiddenIter(const void* pItr); // type-erased constructor
    virtual ~HiddenIter();

    using value_type = T;
    bool operator==(const HiddenIter& rhs) const;
    bool operator!=(const HiddenIter& rhs) const;
    HiddenIter& operator++();
    const value_type& operator*() const;
    const value_type* operator->() const;
  protected:
    class Impl; PImpl<Impl> pimpl;
  }; // end class HiddenIter

}
