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
#include "doubly.h"


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


//Testing the List
TEST_CASE ("Test Generic List Stuff") {
  doubly testList;

  SECTION ("Start of List: Initial") {
    CHECK (testList.size() == 0);
    CHECK (testList.print() == "");
  }
  
    testList.push("Jane"); //add a student
    
  SECTION ("Start of List: Add student") {
    CHECK (testList.size() == 1);
    CHECK (testList.print() == "Jane ");
  } 
  
    testList.push("Janet");
    testList.push("Steve");
    
  SECTION ("Start of List: Add More students") {
    CHECK (testList.size() == 3);
    CHECK (testList.print() == "Jane Janet Steve ");
    CHECK (testList.peek() == "Steve");
  }
    
    testList.pop();
    
  SECTION ("Middle of List: Delete a Student") {
    CHECK (testList.size() == 2);
    CHECK (testList.print() == "Jane Janet ");
    CHECK (testList.peek() == "Janet");
  }
  
    testList.pop();

  SECTION ("End of List: Pop Head") {
    CHECK (testList.size() == 1);
    CHECK (testList.print() == "Jane ");
    CHECK (testList.peek() == "Jane");
  }
    
    testList.pop();
    testList.pop();
    testList.pop();
    
  SECTION ("Popping too many times") {
    CHECK (testList.size() == 0);
    CHECK (testList.print() == "");
  }
} 

TEST_CASE ("Test Double Linked List Things") {
  doubly testList;

  SECTION ("Start of List: Initial") {
    CHECK (testList.size() == 0);
    CHECK (testList.print() == "");
  }
  
    testList.push("Jane"); //add a student
    
  SECTION ("Start of List: Add student") {
    CHECK (testList.size() == 1);
    CHECK (testList.print() == "Jane ");
  } 
  
    testList.push("Janet");
    testList.push("Steve");
    
  SECTION ("Start of List: Add More students") {
    CHECK (testList.size() == 3);
    CHECK (testList.print() == "Jane Janet Steve ");
    CHECK (testList.peek() == "Steve");
  }
    
  bool tr_check = testList.insert(1,"Joe");
  
  SECTION ("Inserting") {
    CHECK (tr_check);
    CHECK (testList.size() == 4);
    CHECK (testList.print() == "Jane Joe Janet Steve ");
    CHECK (testList.peek() == "Steve");
  }
  
  tr_check = testList.insert(1,"James");
  
  SECTION ("Inserting") {
    CHECK (tr_check);
    CHECK (testList.size() == 5);
    CHECK (testList.print() == "Jane James Joe Janet Steve ");
    CHECK (testList.peek() == "Steve");
  }
  
  tr_check = testList.insert(1,"Kyle");
  
  SECTION ("Insert another") {
    CHECK (tr_check);
    CHECK (testList.size() == 6);
    CHECK (testList.print() == "Jane Kyle James Joe Janet Steve ");
    CHECK (testList.peek() == "Steve");
  }
  
  tr_check = testList.insert(0,"Burt");
  
  SECTION ("Insert at head") {
    CHECK (tr_check);
    CHECK (testList.size() == 7);
    CHECK (testList.print() == "Burt Jane Kyle James Joe Janet Steve ");
    CHECK (testList.peek() == "Steve");
  }
  
  tr_check = testList.remove("Burt");
  
  SECTION ("Remove head") {
    CHECK (tr_check);
    CHECK (testList.size() == 6);
    CHECK (testList.print() == "Jane Kyle James Joe Janet Steve ");
    CHECK (testList.peek() == "Steve");
  }
  
  tr_check = testList.remove("Joe");
  
  SECTION ("Remove middle") {
    CHECK (tr_check);
    CHECK (testList.size() == 5);
    CHECK (testList.print() == "Jane Kyle James Janet Steve ");
    CHECK (testList.peek() == "Steve");
  }
  
  tr_check = testList.remove("Steve");
  
  SECTION ("Remove end") {
    CHECK (tr_check);
    CHECK (testList.size() == 4);
    CHECK (testList.print() == "Jane Kyle James Janet ");
    CHECK (testList.peek() == "Janet");
  }
  
  testList.pop();
  testList.pop();
  testList.pop();
  tr_check = testList.remove("JaneDoe");
  
  SECTION ("Remove information that doesn't exist") {
    CHECK (!tr_check);
    CHECK (testList.size() == 1);
    CHECK (testList.print() == "Jane ");
    CHECK (testList.peek() == "Jane");
  }
  
  tr_check = testList.remove("Jane");
  
  SECTION ("Remove one and only item from list") {
    CHECK (tr_check);
    CHECK (testList.size() == 0);
    CHECK (testList.print() == "");
    CHECK (testList.peek() == "");
  }
}