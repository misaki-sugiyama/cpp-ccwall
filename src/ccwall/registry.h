// A general-purpose registry utility class with name, description and some type
#pragma once
#include "ccwall/hiter.h"
#include "ccwall/pimpl.h"

#include "CorradeStlForwardString.h"
#include <cstddef> // for size_t

namespace ccwall {

  // Basically a 3-element append-only container
  template <class Derived, typename T>
  struct Registry {
    void add(const std::string& name, const T& obj, const std::string& desc = "");
    bool has(const std::string& name);
    size_t size();

    const T& get(const std::string& name);
    const std::string& getDesc(const std::string& name);

    struct Iter : public HiddenIterBi<Iter, const std::string> {
      using HiddenIterBi<Iter, const std::string>::HiddenIterBi;
    };
    Iter begin() const;
    Iter end() const;
    struct IterRev : public HiddenIterBi<IterRev, const std::string> {
      using HiddenIterBi<IterRev, const std::string>::HiddenIterBi;
    };
    IterRev rbegin() const;
    IterRev rend() const;

    Registry();
    ~Registry();
    Registry(Registry&& rhs) noexcept;
    Registry& operator=(Registry&& rhs) noexcept;
    // No copy for registry class
    Registry(const Registry& rhs) = delete;
    Registry& operator=(const Registry& rhs) = delete;
  private:
    class Impl; PImpl<Impl> pimpl;
  }; // end Registry class


}
