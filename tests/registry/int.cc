// A simple int registry
#include "int.sub.h"
#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_string.hpp>
using Catch::Matchers::Equals;

#include <vector>

SCENARIO("Int registry", "[reg]") {

  RegInt reg;

  GIVEN("Nothing inside") {
    THEN("There should really be nothing inside") {
      REQUIRE(reg.size() == 0);
      REQUIRE(!reg.has(""));
    }
  }

  GIVEN("Something to register") {
    reg.add("name2", 30, "desc2");
    reg.add("name1", 15);
    THEN("It can register and exist") {
      REQUIRE(reg.size() == 2);
      REQUIRE(reg.has("name1"));
      REQUIRE(reg.has("name2"));
      REQUIRE(!reg.has("name3"));
    }

    THEN("The stored object can be queried") {
      REQUIRE(reg.get("name1") == 15);
      REQUIRE(reg.get("name2") == 30);
      REQUIRE_THROWS_AS(
          reg.get("name3"),
          ::std::out_of_range
          );
      REQUIRE_THROWS_AS(
          reg.get(""),
          ::std::out_of_range
          );
    }

    THEN("The description can be queried") {
      REQUIRE_THAT(reg.getDesc("name1"), Equals(""));
      REQUIRE_THAT(reg.getDesc("name2"), Equals("desc2"));
      REQUIRE_THROWS_AS(
          reg.getDesc("name3"),
          ::std::out_of_range
          );
      REQUIRE_THROWS_AS(
          reg.getDesc(""),
          ::std::out_of_range
          );
    }

    THEN("Iterators can be used to go through the registry") {
      auto itrBegin {reg.begin()}, itrEnd {reg.end()};
      REQUIRE_THAT(*itrBegin, Equals("name1"));
      REQUIRE(itrBegin != itrEnd);
      ++itrBegin;
      REQUIRE_THAT(*itrBegin, Equals("name2"));
      REQUIRE(itrBegin != itrEnd);
      ++itrBegin;
      REQUIRE(itrBegin == itrEnd);
    }

    THEN("Reverse iterators can be used to go through the registry") {
      auto itrBegin {reg.rbegin()}, itrEnd {reg.rend()};
      REQUIRE_THAT(*itrBegin, Equals("name2"));
      REQUIRE(itrBegin != itrEnd);
      ++itrBegin;
      REQUIRE_THAT(*itrBegin, Equals("name1"));
      REQUIRE(itrBegin != itrEnd);
      ++itrBegin;
      REQUIRE(itrBegin == itrEnd);
    }

    THEN("Range-based for is supported") {
      std::vector<std::string> aAnswer {"name1", "name2"};
      auto itrAnswer {aAnswer.begin()};
      for (const auto& s : reg) {
        REQUIRE(itrAnswer != aAnswer.end());
        REQUIRE_THAT(s, Equals(*itrAnswer++));
      }
      REQUIRE(itrAnswer == aAnswer.end());
    }
  }

} // End normal scenario

SCENARIO("Weird but valid usage: empty name", "[reg]") {

  RegInt reg;

  GIVEN("Something with empty name") {
    reg.add("", -15);
    THEN("The content is okay") {
      REQUIRE(reg.size() == 1);
      REQUIRE(reg.has(""));
      REQUIRE(reg.get("") == -15);
      REQUIRE_THAT(reg.getDesc(""), Equals(""));
    }
  }

} // End empty name

SCENARIO("Weird but valid usage: utf-8 name", "[reg]") {

  RegInt reg;

  GIVEN("Something with unicode name") {
    reg.add("テスト", -30, "説明");
    THEN("The content is okay") {
      REQUIRE(reg.size() == 1);
      REQUIRE(reg.has("テスト"));
      REQUIRE(reg.get("テスト") == -30);
      REQUIRE_THAT(reg.getDesc("テスト"), Equals("説明"));
    }
  }

}
