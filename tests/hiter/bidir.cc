// Test simple version of read-only hidden iterator
#include "bidir.sub.h"
#include <catch2/catch_test_macros.hpp>

#include <vector>
#include <map>

SCENARIO("Bidir iterator", "[hiter]") {

  THEN("It should be default-constructable") {
    IterVecInt empty;
  }

  GIVEN("An bidir iterator for vector<int>") {
    const std::vector<int> s {9,3,7};

    auto itr0 = s.begin(), itr = s.begin(), itrEnd = s.end();
    IterVecInt b0 {&itr0}, b {&itr}, e {&itrEnd};
    THEN("It works") {
      for (; itr != itrEnd; ++itr, ++b) {
        REQUIRE(*b == *itr);
        REQUIRE(b != e);
      }
      REQUIRE(b == e);
    }

    THEN("It also works another way around") {
      for (; itr != itrEnd; ++itr, ++b) {}
      do {
        REQUIRE(b != b0);
        --b;
        --itr;
        REQUIRE(*b == *itr);
      } while (itr != itr0);
      REQUIRE(b == b0);
    }
  }

} // end straightforward scenario

