// A wrapper to hide the underlying iterator implementation
#pragma once
#include "ccwall/hiter.h"
#include "ccwall/pimpl-inl.h"

namespace ccwall {

  template <typename DerivedOuter, typename Itr>
  class HiddenIterImpl {
  private:
    Itr m_it;
  public:
    using value_type = typename Itr::value_type;

    HiddenIterImpl(const void *pItr) : m_it{*static_cast<const Itr*>(pItr)} {}
    HiddenIterImpl() {}
    virtual ~HiddenIterImpl() {}

    bool operator==(const HiddenIterImpl& rhs) const {
      return m_it == rhs.m_it;
    }
    HiddenIterImpl& operator++() {
      ++m_it;
      return *this;
    }
    HiddenIterImpl& operator--() {
      --m_it;
      return *this;
    }
    const value_type& operator*() const {
      return *m_it;
    }
    value_type& operator*() {
      return *m_it;
    }
    const value_type* operator->() const {
      return &(*m_it);
    }
    value_type* operator->() {
      return &(*m_it);
    }
  };

  // === Simple Hidden Iterator ===

  template <class Derived, typename T>
  HiddenIter<Derived, T>::HiddenIter() : pimpl{} {}

  template <class Derived, typename T>
  HiddenIter<Derived, T>::HiddenIter(const void *pItr) : pimpl{pItr} {}

  template <class Derived, typename T>
  HiddenIter<Derived, T>::~HiddenIter() {}

  template <class Derived, typename T>
  bool HiddenIter<Derived, T>::operator==(const HiddenIter& rhs) const {
    return *(static_cast<const Derived&>(*this)).pimpl == *(static_cast<const Derived&>(rhs)).pimpl;
  }

  template <class Derived, typename T>
  bool HiddenIter<Derived, T>::operator!=(const HiddenIter& rhs) const {
    return !(this->operator==(rhs));
  }

  template <class Derived, typename T>
  HiddenIter<Derived, T>& HiddenIter<Derived, T>::operator++() {
    ++(*(static_cast<Derived&>(*this)).pimpl);
    return *this;
  }

  template <class Derived, typename T>
  const typename HiddenIter<Derived,T>::value_type& HiddenIter<Derived,T>::operator*() const {
    return **(static_cast<const Derived&>(*this)).pimpl;
  }

  template <class Derived, typename T>
  const typename HiddenIter<Derived,T>::value_type* HiddenIter<Derived,T>::operator->() const {
    return &**(static_cast<const Derived&>(*this)).pimpl;
  }

  // === Bi-directional things ===

  template <class Derived, typename T>
  HiddenIterBi<Derived, T>::HiddenIterBi() : pimpl{} {}

  template <class Derived, typename T>
  HiddenIterBi<Derived, T>::HiddenIterBi(const void *pItr) : pimpl{pItr} {}

  template <class Derived, typename T>
  HiddenIterBi<Derived, T>::~HiddenIterBi() {}

  template <class Derived, typename T>
  bool HiddenIterBi<Derived, T>::operator==(const HiddenIterBi& rhs) const {
    return *(static_cast<const Derived&>(*this)).pimpl == *(static_cast<const Derived&>(rhs)).pimpl;
  }

  template <class Derived, typename T>
  bool HiddenIterBi<Derived, T>::operator!=(const HiddenIterBi& rhs) const {
    return !(this->operator==(rhs));
  }

  template <class Derived, typename T>
  HiddenIterBi<Derived, T>& HiddenIterBi<Derived, T>::operator++() {
    ++(*(static_cast<Derived&>(*this)).pimpl);
    return *this;
  }

  template <class Derived, typename T>
  HiddenIterBi<Derived, T>& HiddenIterBi<Derived, T>::operator--() {
    --(*(static_cast<Derived&>(*this)).pimpl);
    return *this;
  }

  template <class Derived, typename T>
  const typename HiddenIterBi<Derived,T>::value_type& HiddenIterBi<Derived,T>::operator*() const {
    return **(static_cast<const Derived&>(*this)).pimpl;
  }

  template <class Derived, typename T>
  const typename HiddenIterBi<Derived,T>::value_type* HiddenIterBi<Derived,T>::operator->() const {
    return &**(static_cast<const Derived&>(*this)).pimpl;
  }

}
