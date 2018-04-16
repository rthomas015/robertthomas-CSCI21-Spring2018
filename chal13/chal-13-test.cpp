/**********************************************/
/***** Programming Challenge 13 UNIT TEST *****/
/**********************************************/

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "chal-13-spec.h"

TEST_CASE("recursive functions") {

	SECTION("recursive factorial function") {
		CHECK(factorial(0) == 1);
		CHECK(factorial(1) == 1);
		CHECK(factorial(2) == 2);
		CHECK(factorial(5) == 120);
	}

	SECTION("recursive fibonacci function") {
		CHECK(fibonacci(1) == 1);
		CHECK(fibonacci(2) == 1);
		CHECK(fibonacci(3) == 2);
		CHECK(fibonacci(15) == 610);
	}

	SECTION("recursive wordIsPalindrome function") {
		CHECK(wordIsPalindrome("") == true);
		CHECK(wordIsPalindrome("a") == true);
		CHECK(wordIsPalindrome("sitonapotatopanotis") == true);
		CHECK(wordIsPalindrome("baseball") == false);
	}
}

TEST_CASE("recursive vector to string functions") {
	vector<int32_t> numbers = {5, 10, 15, 20, 25};

	SECTION("recursive vector forwards as string function") {
		CHECK(vectorForwardsAsString(numbers, 0) == "5 10 15 20 25 ");
		CHECK(vectorForwardsAsString(numbers, 3) == "20 25 ");
		CHECK(vectorForwardsAsString(numbers, 5) == "");
	}

	SECTION("recursive vector backwards as string function") {
		CHECK(vectorBackwardsAsString(numbers, 4) == "25 20 15 10 5 ");
	    CHECK(vectorBackwardsAsString(numbers, 1) == "10 5 ");
		CHECK(vectorBackwardsAsString(numbers, -1) == "");
	}  
}
