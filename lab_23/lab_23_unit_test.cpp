/*
 * Name        : lab_23_unit_test.cpp
 * Author      : Luke Sathrum
 * Description : Unit test to test Lab #23 Functionality
 */
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

// For NULL
#include <cstddef>
#include "bst_node.h"
// To test for correct header guards
#include "bst_node.h"

TEST_CASE("Default Constructor") {
  const BSTNode const_node;
  BSTNode node;
  BSTNode* p_node = &node;
  

  SECTION("Contents const Accessor") {
    CHECK(const_node.contents() == 0);
  }

  SECTION("Contents Accessor (Editable)") {
    //node.contents() = 10;
    node.set_contents(10); // is this what was meant?
    CHECK(node.contents() == 10);
  }


  SECTION("Left Child const Accessor") {
    CHECK(const_node.left_child() == NULL);
  }
  
  SECTION("Left Child Accessor (Editable)") {
    //node.left_child() = &node;
    node.set_left_child(&node);
    CHECK(node.left_child() == p_node);
  }

  SECTION("Right Child const Accessor") {
    CHECK(const_node.right_child() == NULL);
  }

  SECTION("Right Child Accessor (Editable") {
    //node.right_child() = &node;
    node.set_right_child(&node);
    CHECK(node.right_child() == p_node);
  }
}

TEST_CASE("Overloaded Constructor") {
  BSTNode node(99);
  SECTION("Contents Accessor") {
    CHECK(node.contents() == 99);
  }

  SECTION("Left Child Accessor") {
    CHECK(node.left_child() == NULL);
  }

  SECTION("Right Child Accessor") {
    CHECK(node.right_child() == NULL);
  }
}


TEST_CASE("Testing Pointers") {
  BSTNode node1;
  BSTNode node2(99);
  BSTNode node3(-1);
  // node 2 is leftChild, node 3 is rightChild
  node1.set_left_child(&node2);
  node1.set_right_child(&node3);
  SECTION("Left Child Mutator") {
    CHECK(node1.left_child() == &node2);
  }

  SECTION("Right Child Mutator") {
    CHECK(node1.right_child() == &node3);
  }

  // Change the contents of left child via root
  node1.left_child()->set_contents(10);

  SECTION("Contents Mutator") {
    CHECK(node2.contents() == 10);
  }
}
