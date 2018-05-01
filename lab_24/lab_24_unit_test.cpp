/*
 * Name        : lab_24_unit_test.cpp
 * Author      : Luke Sathrum
 * Description : Unit test to test Lab #24 Functionality
 */
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

// For NULL
#include <cstddef>
#include "bs_tree.h"
// To test for correct header guards
#include "bst_node.h"
#include "bst_node.h"
#include "bs_tree.h"

TEST_CASE("Default Constructor for BSTNode") {
  const BSTNode const_node;
  BSTNode node;
  BSTNode* p_node = &node;
  SECTION("Contents const Accessor") {
    CHECK(const_node.contents() == 0);
  }

  SECTION("Contents Accessor (Editable)") {
    node.set_contents(10);
    CHECK(node.contents() == 10);
  }

  SECTION("Left Child const Accessor") {
    CHECK(const_node.left_child() == NULL);
  }

  SECTION("Left Child Accessor (Editable)") {
    node.set_left_child(&node);
    CHECK(node.left_child() == p_node);
  }

  SECTION("Right Child const Accessor") {
    CHECK(const_node.right_child() == NULL);
  }

  SECTION("Right Child Accessor (Editable") {
    node.set_right_child(&node);
    CHECK(node.right_child() == p_node);
  }
}

TEST_CASE("Overloaded Constructor for BSTNode") {
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


TEST_CASE("Testing Pointers for BSTNode") {
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

TEST_CASE("Default Constructor for BSTree") {
  BSTree tree;
  SECTION("Size Accessor") {
    CHECK(tree.size() == 0);
  }

  SECTION("InOrder() on an Empty Tree") {
    CHECK(tree.InOrder() == "");
  }

  SECTION("Clear() on an Empty Tree") {
    tree.Clear();
    CHECK(tree.size() == 0);
    CHECK(tree.InOrder() == "");
  }
}

TEST_CASE("Building a Tree") {
  BSTree tree;
  bool return_bool = false;
  return_bool = tree.Insert(50);
  SECTION("Insert(50) (the root)") {
    CHECK(return_bool == true);
    CHECK(tree.size() == 1);
    CHECK(tree.InOrder() == "50 ");
  }

  return_bool = false;
  return_bool = tree.Insert(20);

  SECTION("Insert(20) (the left child)") {
    CHECK(return_bool == true);
    CHECK(tree.size() == 2);
    CHECK(tree.InOrder() == "20 50 ");
  }

  return_bool = false;
  return_bool = tree.Insert(80);
  SECTION("Insert(80) (the right child)") {
    CHECK(return_bool == true);
    CHECK(tree.size() == 3);
    CHECK(tree.InOrder() == "20 50 80 ");
  }

  return_bool = false;
  return_bool = tree.Insert(30);
  SECTION("Insert(30) (the right child of node 20)") {
    CHECK(return_bool == true);
    CHECK(tree.size() == 4);
    CHECK(tree.InOrder() == "20 30 50 80 ");
  }

  return_bool = false;
  return_bool = tree.Insert(70);
  SECTION("Insert(70) (the left child of node 80)") {
    CHECK(return_bool == true);
    CHECK(tree.size() == 5);
    CHECK(tree.InOrder() == "20 30 50 70 80 ");
  }

  return_bool = false;
  return_bool = tree.Insert(0);
  SECTION("Insert(0) (the left child of node 10)") {
    CHECK(return_bool == true);
    CHECK(tree.size() == 6);
    CHECK(tree.InOrder() == "0 20 30 50 70 80 ");
  }

  return_bool = false;
  return_bool = tree.Insert(100);
  SECTION("Insert(100) (the right child of node 80)") {
    CHECK(return_bool == true);
    CHECK(tree.size() == 7);
    CHECK(tree.InOrder() == "0 20 30 50 70 80 100 ");
  }

  SECTION("Inserting Duplicate Values") {
    CHECK(tree.Insert(50) == false);
    CHECK(tree.Insert(20) == false);
    CHECK(tree.Insert(80) == false);
    CHECK(tree.Insert(30) == false);
    CHECK(tree.Insert(70) == false);
    CHECK(tree.Insert(0) == false);
    CHECK(tree.Insert(100) == false);
    CHECK(tree.size() == 7);
    CHECK(tree.InOrder() == "0 20 30 50 70 80 100 ");
  }

  tree.Clear();
  SECTION("Clear()") {
    CHECK(tree.size() == 0);
    CHECK(tree.InOrder() == "");
  }

  SECTION("Insert() Stress Test") {
    CHECK(tree.Insert(50) == true);
    CHECK(tree.Insert(50) == false);
    CHECK(tree.Insert(25) == true);
    CHECK(tree.Insert(25) == false);
    CHECK(tree.Insert(75) == true);
    CHECK(tree.Insert(75) == false);
    CHECK(tree.Insert(30) == true);
    CHECK(tree.Insert(30) == false);
    CHECK(tree.Insert(29) == true);
    CHECK(tree.Insert(29) == false);
    CHECK(tree.Insert(31) == true);
    CHECK(tree.Insert(31) == false);
    CHECK(tree.Insert(32) == true);
    CHECK(tree.Insert(32) == false);
    CHECK(tree.Insert(33) == true);
    CHECK(tree.Insert(33) == false);
    CHECK(tree.Insert(34) == true);
    CHECK(tree.Insert(34) == false);
    CHECK(tree.size() == 9);
    CHECK(tree.InOrder() == "25 29 30 31 32 33 34 50 75 ");
  }
}
