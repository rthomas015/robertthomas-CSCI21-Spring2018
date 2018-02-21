/*
 * Programming Challenge 21 - UNIT TEST
 */



/*
 * Programming Challenge 21
 */
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "box.h"
#include <iostream>

using std::ostringstream;


TEST_CASE ("Box<int> class functionality", "[Box]") {
	Box<int> intBox(99);

	CHECK(intBox.getContents() == 99);

	intBox.setContents(42);
	CHECK(intBox.getContents() == 42);

	ostringstream ss;
	ss << intBox;
	CHECK(ss.str() == "42");
}

TEST_CASE ("Box<bool> class functionality", "[Box]") {
	Box<bool> boolBox(false);

	CHECK(boolBox.getContents() == false);

	boolBox.setContents(true);
	CHECK(boolBox.getContents() == true);

	ostringstream ss;
	ss << boolBox;
	CHECK(ss.str() == "1");
}

TEST_CASE ("Box<float> class functionality", "[Box]") {
	Box<float> floatBox(1.23f);

	CHECK(floatBox.getContents() == 1.23f);

	floatBox.setContents(3.21f);
	CHECK(floatBox.getContents() == 3.21f);

	ostringstream ss;
	ss << floatBox;
	CHECK(ss.str() == "3.21");
}

TEST_CASE ("Box<string> class functionality", "[Box]") {
	Box<string> stringBox("hello");

	CHECK(stringBox.getContents() == "hello");

	stringBox.setContents("goodbye");
	CHECK(stringBox.getContents() == "goodbye");

	ostringstream ss;
	ss << stringBox;
	CHECK(ss.str() == "goodbye");
}
