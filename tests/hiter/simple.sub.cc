#include "simple.sub.h"
#include "ccwall/hiter-inl.h"

#include <forward_list>
#include <map>

template <>
class ccwall::HiddenIter<IterSListInt, int>::Impl : public ::ccwall::HiddenIterImpl<IterSListInt, std::forward_list<int>::iterator> {
  using HiddenIterImpl::HiddenIterImpl;
};
template class ::ccwall::HiddenIter<IterSListInt, int>;

template <>
class ccwall::HiddenIter<IterMapIntBool, std::pair<const int, bool>>::Impl : public ::ccwall::HiddenIterImpl<IterMapIntBool, std::map<int, bool>::iterator> {
  using HiddenIterImpl::HiddenIterImpl;
};
template class ::ccwall::HiddenIter<IterMapIntBool, std::pair<const int, bool>>;
