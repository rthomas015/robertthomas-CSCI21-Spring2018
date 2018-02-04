/*
 * Name        : lab_4_unit_test.cpp
 * Author      : Luke Sathrum
 * Description : Unit test to test Lab #4 Functionality
 * Sources     :
 */
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "lab_4.h"

TEST_CASE("MakeString()") {
  SECTION("MakeString(\"Temperature\", 42.6, ':')") {
    CHECK(MakeString("Temperature", 42.6, ':') == "Temperature : 42.6");
  }

  SECTION("MakeString(\"\", 75, ',')") {
    CHECK(MakeString("", 75, ',') == " , 75");
  }

  SECTION("MakeString(\"Total\", 100.05, '=')") {
    CHECK(MakeString("Total", 100.05, '=') == "Total = 100.05");
  }
}

TEST_CASE("StringToChar()") {
  SECTION("StringToChar(\"\")") {
    CHECK(StringToChar("") == '\0');
  }

  SECTION("StringToChar(\"yn\")") {
    CHECK(StringToChar("yn") == '\0');
  }

  SECTION("StringToChar(\"X\")") {
    CHECK(StringToChar("X") == 'X');
  }
}

TEST_CASE("StringToInt()") {
  SECTION("StringToInt(\"42\")") {
    CHECK(StringToInt("42") == 42);
  }

  SECTION("StringToInt(\"hello\")") {
    CHECK(StringToInt("hello") == 0);
  }

  SECTION("StringToInt(\"\")") {
    CHECK(StringToInt("") == 0);
  }
}

TEST_CASE("StringToDouble()") {
  SECTION("StringToDouble(\"\")") {
    CHECK(StringToDouble("") == 0);
  }

  SECTION("StringToDouble(\"3.14\")") {
    CHECK(StringToDouble("3.14") == 3.14);
  }

  SECTION("StringToDouble(\"hello\")") {
    CHECK(StringToDouble("hello") == 0);
  }
}

TEST_CASE("StringToBool()") {
  SECTION("StringToBool(\"\")") {
    CHECK(StringToBool("") == false);
  }

  SECTION("StringToBool(\"TrUe\")") {
    CHECK(StringToBool("TrUe") == true);
  }

  SECTION("StringToBool(\"FALSE\")") {
    CHECK(StringToBool("FALSE") == false);
  }
}
