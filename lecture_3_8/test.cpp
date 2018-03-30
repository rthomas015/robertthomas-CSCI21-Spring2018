/*
 * Name        : lab_17_unit_test.cpp
 * Author      : Luke Sathrum
 * Description : Unit test to test Lab #17 Functionality
 */
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

// For NULL
#include <cstddef>
#include "node.h"
// To test for correct header guards
#include "node.h"

/*
TEST_CASE("Default Constructor") {
  Node node, node2;
  Node* p_node2 = &node2;
  SECTION("Accessor for Contents") {
    CHECK(node.contents() == "");
  }


  SECTION("Accessor for Next Node") {
    CHECK(node.next_node() == NULL);
  }


  SECTION("Mutator for Contents") {
    node.set_contents("Susie");
    CHECK(node.contents() == "Susie");
  }

  SECTION("Mutator for Next Node") {
    node.set_next_node(&node2);
    CHECK(node.next_node() == p_node2);
  }
}

TEST_CASE("Overloaded Constructor") {
  Node node("Jane"), node2;
  Node* p_node2 = &node2;
  SECTION("Accessor for Contents") {
    CHECK(node.contents() == "Jane");
  }

  SECTION("Accessor for Next Node") {
    CHECK(node.next_node() == NULL);
  }

  SECTION("Mutator for Contents") {
    node.set_contents("Susie");
    CHECK(node.contents() == "Susie");
  }

  SECTION("Mutator for Next Node") {
    node.set_next_node(&node2);
    CHECK(node.next_node() == p_node2);
  }
}

TEST_CASE("Testing Pointers") {
  Node* node = new Node("Jane");
  Node* node2 = new Node();
  node->set_next_node(node2);
  node2->set_next_node(node);
  // node and node2 now connect each to the other -- not something you should
  // ever do outside of a testing situation
  SECTION("Node 1 Points to Node 2") {
    CHECK(node->next_node() == node2);
  }

  SECTION("Node 2 Points to Node 1") {
    CHECK(node2->next_node() == node);
  }

  SECTION("Node 1 Points to NULL") {
    node->set_next_node(NULL);
    CHECK(node->next_node() == NULL);
  }

  SECTION("Node 2 Points to NULL") {
    node2->set_next_node(NULL);
    CHECK(node2->next_node() == NULL);
  }
}
*/


TEST_CASE ("Test Stack") {
  //Node* head = NULL;
  //Node head;
  stack testStack; //doesn't work, stack class not defined

/*  
	SECTION ("Start of Stack") {
		CHECK (testStack.size() == 0);
		CHECK (testStack.print() == "");
		testStack.push();            //add something
		CHECK (head==Next_Node); //test head is pointing
		CHECK (testStack.size() == 1);
		CHECK (testStack.print() == "Contents of the Stack");
		testStack.push();          //add another item
		CHECK (testStack.size() == 2);
		testStack.pop();
		CHECK (testStack.size() == 1);
	}
	
	SECTION ("Middle") {
		CHECK (head.size(head) == NULL);
		//O.pop() //do something 
		//CHECK (head==Null); //test something
	}
	
	SECTION ("End") {
		CHECK (head.size(head) == NULL);
		//O.pop() //do something 
		//CHECK (head==Null); //test something
	}
*/
}

