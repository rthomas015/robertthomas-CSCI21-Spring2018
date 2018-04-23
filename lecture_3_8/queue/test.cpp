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
#include "queue.h"


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


//Testing the Queue
TEST_CASE ("Test Queue: Start") {
  Queue testQueue;
  
  SECTION ("Start of Queue: Initial") {
    CHECK (testQueue.size() == 0);
    CHECK (testQueue.print() == "");
  }
  
  testQueue.push("Jane"); //add a student
   
  SECTION ("Start of Queue: Add student") {
    CHECK (testQueue.size() == 1);
    CHECK (testQueue.print() == "Jane ");
  } 

    testQueue.push("Janet");
    
  SECTION ("Start of Queue: Add More students") {
    CHECK (testQueue.size() == 2);
    CHECK (testQueue.print() == "Janet Jane ");
    CHECK (testQueue.peek() == "Jane");
  }
  
    testQueue.pop();
    
  SECTION ("Start of Queue: Delete a Student") {
    CHECK (testQueue.size() == 1);
    CHECK (testQueue.print() == "Janet ");
    CHECK (testQueue.peek() == "Janet");
  }
  
    testQueue.pop();
    
  SECTION ("Start of Queue: Pop Head") {
    CHECK (testQueue.size() == 0);
    CHECK (testQueue.print() == "");
  }

}

TEST_CASE ("Test Queue: Middle") {
    Queue testQueue;
    
      testQueue.push("Jane");
  	  testQueue.push("Billy");
  	  testQueue.push("Steve");
  	  testQueue.push("Brandon");
  	  testQueue.push("Curtis");
  	  
  	SECTION ("Middle of Queue") {
  	  CHECK (testQueue.size() == 5);
      CHECK (testQueue.print() == "Curtis Brandon Steve Billy Jane ");
      CHECK (testQueue.peek() == "Jane");
  	}
  	
	  testQueue.pop();
  	testQueue.pop();
  	testQueue.pop();
	
	SECTION ("Middle of Queue") {
  	  CHECK (testQueue.size() == 2);
      CHECK (testQueue.print() == "Curtis Brandon ");
      CHECK (testQueue.peek() == "Brandon");
  	}
  	    
  	 testQueue.pop();
  	 testQueue.pop();
  	  
  	SECTION ("Middle of Queue - Clear Rest of Queue") {
  	  CHECK (testQueue.size() == 0);
      CHECK (testQueue.print() == "");
  	}
}


TEST_CASE ("Test Queue: End") {
  Queue testQueue;
  testQueue.push("Jane");
  testQueue.push("Billy");
  testQueue.pop();
  testQueue.pop();
  
  SECTION ("End of Queue") {
	  CHECK (testQueue.size() == 0);
    CHECK (testQueue.print() == "");
  }
  
  testQueue.pop();
  testQueue.pop();
  testQueue.pop();
  
  SECTION ("End of Queue: Too many Pops") {
      CHECK (testQueue.size() == 0);
      CHECK (testQueue.print() == "");
  }
  
}
