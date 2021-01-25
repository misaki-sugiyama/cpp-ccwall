#include "bidir.sub.h"
#include "ccwall/hiter-inl.h"

#include <vector>
#include <map>

template <>
class ccwall::HiddenIterBi<IterVecInt, int>::Impl : public ::ccwall::HiddenIterImpl<IterVecInt, std::vector<int>::iterator> {
  using HiddenIterImpl::HiddenIterImpl;
};
template class ::ccwall::HiddenIterBi<IterVecInt, int>;
