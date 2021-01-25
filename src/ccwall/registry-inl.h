// A general-purpose registry utility class with name, description and some type
#pragma once
#include "ccwall/registry.h"
#include "ccwall/hiter-inl.h"
#include "ccwall/pimpl-inl.h"

#include <stdexcept>
#include <string>
#include <set>
#include <unordered_map>

namespace ccwall {

  template <typename DerivedOuter, typename T>
  struct RegistryImpl {
    std::set<std::string> sKey;
    std::unordered_map<std::string, std::pair<std::string, T>> mObj;
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
      pimpl->sKey.emplace(name);
      pimpl->mObj.emplace(name, std::pair(desc, obj));
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
    return pimpl->sKey.size();
  }

  template <class Derived, typename T>
  const T& Registry<Derived, T>::get(const std::string& name) {
    return pimpl->mObj.at(name).second;
  }

  template <class Derived, typename T>
  const std::string& Registry<Derived, T>::getDesc(const std::string& name) {
    return pimpl->mObj.at(name).first;
  }

  template <class Derived, typename T>
  typename Registry<Derived, T>::Iter Registry<Derived, T>::begin() const {
    auto itr = pimpl->sKey.begin();
    return Iter(&itr);
  }

  template <class Derived, typename T>
  typename Registry<Derived, T>::Iter Registry<Derived, T>::end() const {
    auto itr = pimpl->sKey.end();
    return Iter(&itr);
  }

}
