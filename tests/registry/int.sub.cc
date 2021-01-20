#include "int.sub.h"
#include "ccwall/registry-inl.h"

template <>
struct ccwall::Registry<RegInt, int>::Impl : public ::ccwall::RegistryImpl<RegInt, int> {
  using RegistryImpl::RegistryImpl;
};
template struct ccwall::Registry<RegInt, int>;
