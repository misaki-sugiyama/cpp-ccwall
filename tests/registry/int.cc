// A simple int registry
#include "int.sub.h"
#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_string.hpp>
using Catch::Matchers::Equals;

SCENARIO("Int registry", "[reg]") {
  RegInt reg;

  GIVEN("Nothing inside") {
    THEN("There should really be nothing inside") {
      REQUIRE(reg.size() == 0);
      REQUIRE(!reg.has(""));
    }
  }

  GIVEN("Something to register") {
    reg.add("name1", 15);
    reg.add("name2", 30, "desc2");
    THEN("It can register and exist") {
      REQUIRE(reg.size() == 2);
      REQUIRE(reg.has("name1"));
      REQUIRE(reg.has("name2"));
      REQUIRE(!reg.has("name3"));
    }

    THEN("It can be queried") {
      REQUIRE(reg.get("name1") == 15);
      REQUIRE(reg.get("name2") == 30);
      REQUIRE_THROWS_AS(
          reg.get("name3"),
          ::std::out_of_range
          );
    }
  }

}
