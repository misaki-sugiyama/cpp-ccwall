// Test simple version of read-only hidden iterator
#include "simple.sub.h"
#include <catch2/catch_test_macros.hpp>

#include <forward_list>
#include <map>

SCENARIO("Straightforward iterator", "[hiter]") {

  THEN("It should be default-constructable") {
    IterSListInt empty;
  }

  GIVEN("An iterator for forward_list<int>") {
    const std::forward_list<int> s {9,3,7};
    THEN("It simply works") {
      auto itr = s.begin(), itrEnd = s.end();
      IterSListInt b {&itr}, e {&itrEnd};
      for (; itr != itrEnd; ++itr, ++b) {
        REQUIRE(*b == *itr);
        REQUIRE(b != e);
      }
      REQUIRE(b == e);
    }
  }

  GIVEN("An iterator for map<int, bool>") {
    const std::map<int, bool> m {{3,true}, {7,false}};
    THEN("It simply works") {
      auto itr = m.begin(), itrEnd = m.end();
      IterMapIntBool b {&itr}, e {&itrEnd};
      for (; itr != itrEnd; ++itr, ++b) {
        REQUIRE(b->first == itr->first);
        REQUIRE(b->second == itr->second);
        REQUIRE(b != e);
      }
      REQUIRE(b == e);
    }
  }

} // end straightforward scenario

