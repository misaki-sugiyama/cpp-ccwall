#include "cpmv.sub.h"
#include "ccwall/pimpl-inl.h"

#include <vector>

class TestCpMv::Impl {
private:
  std::vector<int> m_vec;
public:
  // No destructor/copy/move, copy and move can be automatically generated
  Impl(int a) {
    m_vec.push_back(a);
  }

  int* getPtr() {
    return &m_vec[0];
  }
};

TestCpMv::TestCpMv() : pimpl(0) {}
TestCpMv::TestCpMv(int a) : pimpl(a) {}

TestCpMv::~TestCpMv() = default;
TestCpMv::TestCpMv(TestCpMv&& rhs) noexcept = default;
TestCpMv& TestCpMv::operator=(TestCpMv&& rhs) noexcept = default;
TestCpMv::TestCpMv(const TestCpMv& rhs) = default;
TestCpMv& TestCpMv::operator=(const TestCpMv& rhs) = default;

int* TestCpMv::getPtr() {
  return pimpl->getPtr();
}

template class ::ccwall::PImpl<TestCpMv::Impl>;
