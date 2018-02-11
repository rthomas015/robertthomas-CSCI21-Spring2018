/**********************************************/
/***** Programming Project 1    UNIT TEST *****/
/**********************************************/

#include <cstdint>
#include <string>
#include <vector>
using std::string;
using std::vector;

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

/*
 * Count the alphabetic and numeric/digit characters in a string.
 * @param theString string to be processed
 * @param alpha will contain the count of alphabetic characters
 *              in theString (may be 0)
 * @param num will contain the count of numeric/digit characters
 *              in theString (may be 0)
 */
void countCharacters (string theString, uint32_t& alpha, uint32_t& num) {

}

/*
 * Create a string where every other character is uppercase/lowercase 
 * (the first character will be uppercase). For example, if the argument 
 * is "hello" the function returns "HeLlO".
 * @param theString string to be processed
 * @return a copy of theString where every other character is 
 *         uppercase/lowercase; empty string argument returns empty string
 */
string upAndDown (string theString) {
	return string("");
}

/*
 * Count the number of words (separated by spaces) in a string. Assumes 
 * the string argument has been scrubbed of sequences of spaces (e.g., two 
 * back-to-back space characters).
 * @param theString string to be processed
 * @return a count of the number of words (separated by spaces) in the 
 *         argument; returns 0 on empty string
 */
uint32_t countWords (string theString) {
	return 0;
}

/*
 * Compute the average of all values in a vector.
 * @param values a vector containing the int32_t values to be averaged
 * @return the average of all values in the vector
 */
int32_t computeAverage (vector<int32_t> values) {
	return 0;
}

/*
 * Identify the smallest/minimum value in a vector of int32_t values.
 * @param values a vector containing the int32_t values to be processed
 * @return the smallest/minimum value in the vector
 */
int32_t findMinValue (vector<int32_t> values) {
	return 0;
}

/*
 * Identify the largest/maximum value in a vector of int32_t values.
 * @param values a vector containing the int32_t values to be processed
 * @return the largest/maximum value in the vector
 */
int32_t findMaxValue (vector<int32_t> values) {
	return 0;
}

/*
 * Unit test. Do not alter.
 */
TEST_CASE("function implementations") {

	SECTION("countCharacters") {

		uint32_t n1=0, n2=0;
	
		countCharacters("", n1, n2);
		CHECK(n1 == 0);
		CHECK(n2 == 0);

		countCharacters("hello", n1, n2);
		CHECK(n1 == 5);
		CHECK(n2 == 0);
		
		countCharacters("12345", n1, n2);
		CHECK(n1 == 0);
		CHECK(n2 == 5);

		countCharacters("hello 12345", n1, n2);
		CHECK(n1 == 5);
		CHECK(n2 == 5);

		countCharacters("&,.", n1, n2);
		CHECK(n1 == 0);
		CHECK(n2 == 0);
	}

	SECTION("upAndDown") {

		string s;

		CHECK(upAndDown("hello") == "HeLlO");
		CHECK(upAndDown("HeLlO") == "HeLlO");
		CHECK(upAndDown("hElLo") == "HeLlO");
		CHECK(upAndDown("") == "");
		CHECK(upAndDown("a") == "A");
	}

	SECTION("countWords") {
	
		CHECK(countWords("") == 0);
		CHECK(countWords("hello") == 1);
		CHECK(countWords("hello,world") == 1);
		CHECK(countWords("hello world") == 2);
		CHECK(countWords("hello, world") == 2);
	}

	SECTION("computeAverage") {

		vector<int32_t> values = {10, 20, 30};
	
		CHECK(computeAverage(values) == 20);
		
		values[0] = 0, values[1] = 0, values[2] = 0;
		CHECK(computeAverage(values) == 0);

		values[0] = 5, values[1] = 7, values[2] = 11;
		CHECK(computeAverage(values) == 7);
		
		values[0] = -10, values[1] = -20, values[2] = -30;
		CHECK(computeAverage(values) == -20);
		
		values[0] = -5, values[1] = 0, values[2] = 5;
		CHECK(computeAverage(values) == 0);
	}

	SECTION("findMinValue") {

		vector<int32_t> values = {-1, 0, 1};
		CHECK(findMinValue(values) == -1);
		
		values[0] = -3, values[1] = -2, values[2] = -1;
		CHECK(findMinValue(values) == -3);
		
		values[0] = 0, values[1] = 1, values[2] = 2;
		CHECK(findMinValue(values) == 0);
		
		values[0] = 1, values[1] = 1, values[2] = 1;
		CHECK(findMinValue(values) == 1);
		
		values[0] = INT32_MAX, values[1] = INT32_MAX, values[2] = INT32_MAX;
		CHECK(findMinValue(values) == INT32_MAX);
	}

	SECTION("findMaxValue") {

		vector<int32_t> values = {-1, 0, 1};
		CHECK(findMaxValue(values) == 1);
		
		values[0] = -3, values[1] = -2, values[2] = -1;
		CHECK(findMaxValue(values) == -1);
		
		values[0] = 0, values[1] = 1, values[2] = 2;
		CHECK(findMaxValue(values) == 2);
		
		values[0] = 1, values[1] = 1, values[2] = 1;
		CHECK(findMaxValue(values) == 1);
		
		values[0] = INT32_MIN, values[1] = INT32_MIN, values[2] = INT32_MIN;
		CHECK(findMaxValue(values) == INT32_MIN);
	}
}
