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
#include "stack.h"


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


//Testing the Stack
TEST_CASE ("Test Stack: Start") {
  stack testStack;
  
  SECTION ("Start of Stack: Initial") {
    CHECK (testStack.size() == 0);
    CHECK (testStack.print() == "");
  }
  
    testStack.push("Jane"); //add a student
    
  SECTION ("Start of Stack: Add student") {
    CHECK (testStack.size() == 1);
    CHECK (testStack.print() == "Jane ");
  } 
  
    testStack.push("Janet");
    
  SECTION ("Start of Stack: Add More students") {
    CHECK (testStack.size() == 2);
    CHECK (testStack.print() == "Jane Janet ");
    CHECK (testStack.peek() == "Janet");
  }
  
    testStack.pop();
    
  SECTION ("Start of Stack: Delete a Student") {
    CHECK (testStack.size() == 1);
    CHECK (testStack.print() == "Jane ");
    CHECK (testStack.peek() == "Jane");
  }
  
    testStack.pop();
    
  SECTION ("Start of Stack: Pop Head") {
    CHECK (testStack.size() == 0);
    CHECK (testStack.print() == "");
  }
}

TEST_CASE ("Test Stack: Middle") {
    stack testStack;
    
      testStack.push("Jane");
  	  testStack.push("Billy");
  	  testStack.push("Steve");
  	  testStack.push("Brandon");
  	  testStack.push("Curtis");
  	  
  	SECTION ("Middle of Stack") {
  	  CHECK (testStack.size() == 5);
      CHECK (testStack.print() == "Jane Billy Steve Brandon Curtis ");
      CHECK (testStack.peek() == "Curtis");
  	}
  	
	  testStack.pop();
  	  testStack.pop();
  	  testStack.pop();
	
	SECTION ("Middle of Stack") {
  	  CHECK (testStack.size() == 2);
      CHECK (testStack.print() == "Jane Billy ");
      CHECK (testStack.peek() == "Billy");
  	}
  	    
  	 testStack.pop();
  	 testStack.pop();
  	  
  	SECTION ("Middle of Stack - Clear Rest of Stack") {
  	  CHECK (testStack.size() == 0);
      CHECK (testStack.print() == "");
  	}
}


TEST_CASE ("Test Stack: End") {
  stack testStack;
  testStack.push("Jane");
  testStack.push("Billy");
  testStack.pop();
  testStack.pop();
  
  SECTION ("End of Stack") {
	  CHECK (testStack.size() == 0);
      CHECK (testStack.print() == "");
  }
  
  testStack.pop();
  testStack.pop();
  testStack.pop();
  
  SECTION ("End of Stack: Too many Pops") {
      CHECK (testStack.size() == 0);
      CHECK (testStack.print() == "");
  }
  
}