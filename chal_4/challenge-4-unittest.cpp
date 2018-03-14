/**********************************************/
/***** Programming Challenge 4  UNIT TEST *****/
/**********************************************/

#define CATCH_CONFIG_MAIN
#include "ch4.h"
#include "catch.hpp"


/*
 * Unit test. Do not alter.
 */

TEST_CASE("NightClubLine functionality") {

	SECTION("empty queue") {
		NightClubLine ncl;

		CHECK(ncl.isEmpty() == true);
		CHECK(ncl.getNumCustomers() == 0);
		//CHECK_THROWS_AS(ncl.getFirstCustomer(), logic_error);
		//CHECK_THROWS_AS(ncl.getLastCustomer(), logic_error);
		//CHECK_THROWS_AS(ncl.removeFirstCustomer(), logic_error);
	}

	SECTION("command processing") {
		NightClubLine ncl;

		CHECK(ncl.processCommand("A apple") == true);
		CHECK(ncl.processCommand("a apple") == true);
		CHECK(ncl.processCommand("A ") == false);
		CHECK(ncl.processCommand("A") == false);

		CHECK(ncl.processCommand("") == false);
		CHECK(ncl.processCommand("B") == false);
		
		CHECK(ncl.processCommand("c") == true);
		CHECK(ncl.processCommand("C") == true);

		ncl.addCustomer("apple");
		CHECK(ncl.processCommand("r") == true);
		ncl.addCustomer("apple");
		CHECK(ncl.processCommand("R") == true);
	}
	
	SECTION("manually entered operations/data") {
		NightClubLine ncl;

		ncl.addCustomer("apple");
		ncl.addCustomer("banana");
		ncl.addCustomer("cherry");

		CHECK(ncl.isEmpty() == false);
		CHECK(ncl.getNumCustomers() == 3);
		CHECK(ncl.getFirstCustomer() == "apple");
		CHECK(ncl.getLastCustomer() == "cherry");

		CHECK(ncl.removeFirstCustomer() == "apple");
		CHECK(ncl.removeFirstCustomer() == "banana");
		CHECK(ncl.removeFirstCustomer() == "cherry");

		CHECK_THROWS_AS(ncl.getLastCustomer(), logic_error);
		CHECK_THROWS_AS(ncl.removeFirstCustomer(), logic_error);
		CHECK(ncl.isEmpty() == true);
		CHECK(ncl.getNumCustomers() == 0);
	}

	SECTION("file processed operations/data") {
		NightClubLine ncl;

		CHECK(ncl.processFile("does-not-exist.txt") == false);

		CHECK(ncl.processFile("challenge-4-data.txt") == true);

		CHECK(ncl.isEmpty() == false);
		CHECK(ncl.getNumCustomers() == 9);
		CHECK(ncl.getFirstCustomer() == "banana");
		CHECK(ncl.getLastCustomer() == "strawberry");
	}
}