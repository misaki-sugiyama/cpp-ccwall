#include "int.sub.h"
#include "ccwall/registry-inl.h"

template <>
class ccwall::HiddenIterBi<ccwall::Registry<RegInt, int>::Iter, const std::string>::Impl : public ccwall::HiddenIterImpl<ccwall::Registry<RegInt, int>::Iter, std::set<std::string>::iterator> {
  using HiddenIterImpl::HiddenIterImpl;
};
template struct ccwall::HiddenIterBi<ccwall::Registry<RegInt, int>::Iter, const std::string>;

template <>
class ccwall::HiddenIterBi<ccwall::Registry<RegInt, int>::IterRev, const std::string>::Impl : public ccwall::HiddenIterImpl<ccwall::Registry<RegInt, int>::IterRev, std::set<std::string>::reverse_iterator> {
  using HiddenIterImpl::HiddenIterImpl;
};
template struct ccwall::HiddenIterBi<ccwall::Registry<RegInt, int>::IterRev, const std::string>;

template <>
struct ccwall::Registry<RegInt, int>::Impl : public ::ccwall::RegistryImpl<RegInt, int> {
  using RegistryImpl::RegistryImpl;
};
template struct ccwall::Registry<RegInt, int>;
