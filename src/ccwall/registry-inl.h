// A general-purpose registry utility class with name, description and some type
#pragma once
#include "ccwall/registry.h"
#include "ccwall/hiter-inl.h"
#include "ccwall/pimpl-inl.h"

#include <map>
#include <string>
#include <stdexcept>

namespace ccwall {

  template <typename DerivedOuter, typename T>
  struct RegistryImpl {
    std::map<std::string, std::string, std::less<>> mDesc;
    std::map<std::string, T, std::less<>> mObj;
  };

  template <class Derived, typename T>
  Registry<Derived, T>::Registry() = default;
  template <class Derived, typename T>
  Registry<Derived, T>::~Registry() = default;
  template <class Derived, typename T>
  Registry<Derived, T>::Registry(Registry&& rhs) noexcept = default;
  template <class Derived, typename T>
  Registry<Derived, T>& Registry<Derived, T>::operator=(Registry&& rhs) noexcept = default;

  template <class Derived, typename T>
  void Registry<Derived, T>::add(const std::string& name, const T& obj, const std::string& desc) {
    if (!has(name)) {
      pimpl->mObj.emplace(name, obj);
      pimpl->mDesc.emplace(name, desc);
    } else {
      throw std::invalid_argument(name);
    }
  }

  template <class Derived, typename T>
  bool Registry<Derived, T>::has(const std::string& name) {
    return pimpl->mObj.count(name) > 0;
  }

  template <class Derived, typename T>
  size_t Registry<Derived, T>::size() {
    return pimpl->mObj.size();
  }

  template <class Derived, typename T>
  const T& Registry<Derived, T>::get(const std::string& name) {
    return pimpl->mObj.at(name);
  }

}
