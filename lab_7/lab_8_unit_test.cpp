/*
 * Name        : lab_8_unit_test.cpp
 * Author      : Luke Sathrum
 * Description : Unit test to test Lab #8 Functionality
 */
#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include "lab_7.h"
map<int, int> counters;
char* global_argv[8];
int global_argc;

int main(int argc, char* const argv[]) {
  if (argc > 1 && argc < 9 && strcmp(argv[1], "teacher") == 0
      && CheckArgs(argc, argv)) {
    // Put argv values into global array
    for (int i = 0; i < argc; i++) {
      global_argv[i] = argv[i];
    }
    global_argc = argc;
    argc = 2;
    strcpy(argv[1], "-s");

    // global setup...
    int result = Catch::Session().run(argc, argv);

    // global clean-up...
    return result;
  } else {
    cout << "\nRun program with the following argument list:\n";
    cout << "\n\t\"teacher 10 20 30 40 50 60\"\n";
    cout << "\nto run the UNIT TEST.\n\n";
  }
}

TEST_CASE("Counting Command Line Arguments") {
  counters[10] = 0, counters[20] = 0, counters[30] = 0, counters[40] = 0,
  counters[50] = 0;
  counters[99] = 0;
  ProcessArguments(global_argc, global_argv);
  SECTION("Counting 10s") {
    CHECK(counters[10] == 1);
  }
  SECTION("Counting 20s") {
    CHECK(counters[20] == 1);
  }
  SECTION("Counting 30s") {
    CHECK(counters[30] == 1);
  }
  SECTION("Counting 40s") {
    CHECK(counters[40] == 1);
  }
  SECTION("Counting 50s") {
    CHECK(counters[50] == 1);
  }
  SECTION("Counting Errors") {
    CHECK(counters[99] == 2);
  }
}

bool CheckArgs(int argc, char* const argv[]) {
  if (argc == 8) {
    // convert the argv[2] to argv[7] contents to integers
    int *temps = new int[6];
    stringstream ss;
    for (int i = 0, j = 2; i < 6; i++, j++) {
      ss.str(argv[j]);
      ss >> temps[i];
      ss.clear();
    }

    // check to see that argv[2] to argv[7] match the expected launch
    // UNIT TEST values
    for (int i = 0, j = 10; i < 6; i++, j += 10) {
      if (temps[i] != j)
        return false;
    }

    delete[] temps;

    return true;
  }
  return false;
}

void OnTen() {
  counters[10]++;
}

void OnTwenty() {
  counters[20]++;
}

void OnThirty() {
  counters[30]++;
}

void OnForty() {
  counters[40]++;
}

void OnFifty() {
  counters[50]++;
}

void OnError() {
  counters[99]++;
}
