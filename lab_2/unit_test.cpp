/*
 * Name        : lab_2_unit_test.cpp
 * Author      : Luke Sathrum
 * Description : Unit test to test Lab #2 Functionality
 * Sources     :
 */
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "Lab2.h"

TEST_CASE("Make Change") {
  int quarters = -1, nickels = -1, dimes = -1, pennies = -1;
  SECTION("Change of $0.00") {
    MakeChange(0, quarters, dimes, nickels, pennies);
    CHECK(quarters == 0);
    CHECK(dimes == 0);
    CHECK(nickels == 0);
    CHECK(pennies == 0);
  }

  SECTION("Change of $0.41") {
    MakeChange(41, quarters, dimes, nickels, pennies);
    CHECK(quarters == 1);
    CHECK(dimes == 1);
    CHECK(nickels == 1);
    CHECK(pennies == 1);
  }

  SECTION("Change of $0.99") {
    MakeChange(99, quarters, dimes, nickels, pennies);
    CHECK(quarters == 3);
    CHECK(dimes == 2);
    CHECK(nickels == 0);
    CHECK(pennies == 4);
  }
}

TEST_CASE("Launch Human Cannonball") {
  double x_distance;
  double scale = 0.01;

  SECTION("LaunchHumanCannonball(25.0, 45.0)") {
    x_distance = LaunchHumanCannonball(25.0, 45.0);
    x_distance = static_cast<int>(x_distance / scale) * scale;
    CHECK(x_distance <= 63.9);
    CHECK(x_distance >= 63.5);
  }

  SECTION("LaunchHumanCannonball(40.0, 60.0)") {
    x_distance = LaunchHumanCannonball(40.0, 60.0);
    x_distance = static_cast<int>(x_distance / scale) * scale;
    CHECK(x_distance <= 141.5);
    CHECK(x_distance >= 141.1);
  }

  SECTION("LaunchHumanCannonball(10.0, 30.0)") {
    x_distance = LaunchHumanCannonball(10.0, 30.0);
    x_distance = static_cast<int>(x_distance / scale) * scale;
    CHECK(x_distance <= 9.0);
    CHECK(x_distance >= 8.6);
  }

  SECTION("LaunchHumanCannonball(10.0, 90.0)") {
    x_distance = LaunchHumanCannonball(10.0, 90.0);
    x_distance = static_cast<int>(x_distance / scale) * scale;
    CHECK(x_distance <= 0.2);
    CHECK(x_distance >= -0.2);
  }
}