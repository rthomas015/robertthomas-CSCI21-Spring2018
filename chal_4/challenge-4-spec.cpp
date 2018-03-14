/**********************************************/
/***** Programming Challenge 4       SPEC *****/
/**********************************************/

#include <fstream>
#include <queue>
#include <string>
#include <stdexcept>
#include "ch4.h"


using namespace std;

		/*
		 * Add a customer to the waiting line/queue.
		 * @param customerName the name of the customer to add to the line/queue
		 */
		void NightClubLine::addCustomer (string customerName) {
			waitingLine.push(customerName);
		}

		/*
		 * Get the name of the first customer (do not remove from the line).
		 * @return the name of the first customer in line
		 * @throw std::logic_error("EMPTY QUEUE") if line is empty
		 */
		string NightClubLine::getFirstCustomer () throw(logic_error) {
			if (waitingLine.size() == 0 || waitingLine.empty()) {
				logic_error("EMPTY QUEUE");
			}
			else {
				return waitingLine.front();
			}
		}

		/*
		 * Get the name of the last customer.
		 * @return the name of the last customer in line
		 * @throw std::logic_error("EMPTY QUEUE") if line is empty
		 */
		string NightClubLine::getLastCustomer () throw(logic_error) {
			if (waitingLine.size() == 0 || waitingLine.empty()) {
				logic_error("EMPTY QUEUE");
			}
			else {
				return waitingLine.back();
			}
		}

		/*
		 * Remove the first customer in line.
		 * @return the name of the removed customer
		 * @throw std::logic_error("EMPTY QUEUE") if line is empty
		 */
		string NightClubLine::removeFirstCustomer () throw(logic_error) {
			string first_cust = "";
			if (waitingLine.size() == 0 || waitingLine.empty()) {
				logic_error("EMPTY QUEUE");
			}
			else {
				first_cust = waitingLine.front();
				waitingLine.pop();
			}
			return first_cust;
		}

		/* 
		 * Remove all customers from the line.
		 */
		void NightClubLine::clearLine () {
			for (int i=0;i<waitingLine.size();i++) {
				waitingLine.pop();
			}
		}

		/*
		 * Get the number of customer currently in line.
		 * @return the number of customers currently in line
		 */
		int NightClubLine::getNumCustomers () {
			return waitingLine.size();
		}

		/*
		 * Check if the line is empty.
		 * @return true if the line is empty, else false
		 */
		bool NightClubLine::isEmpty () {
			return waitingLine.empty();
		}

		/*
		 * Load the contents of a file into the list. Assumes that the file 
		 * has one word per line. Will NOT clear the current contents of the 
		 * list.
		 * @param filename the name of the file to load
		 * @return true if the file is successfully processed, else false
		 */
		bool NightClubLine::processFile (string filename) {
			ifstream ifile;
			string place_holder = "";
			
			ifile.open(filename.c_str());
			//test for if it correctly opened
			
			
			while (!ifile.eof()) {
				getline(ifile,place_holder);
				waitingLine.push(place_holder);
			}
			
			ifile.close();
		}

		/*
		 * NOTE: This function would normally be private but is left public
		         to expose it for unit testing.
		 *
         * Process a single command and perform the appropriate operation on 
         * the line. If command string is empty, returns false, otherwise execute 
         * the operation.
         *
         * COMMAND      :: COMMAND REQUIREMENT	 :: EXPLANATION
         *
         * A apple		:: minimum 3 characters	 :: addCustomer named "apple" to the line
         * a apple      :: SAME
         * C            :: exactly one character :: clearLine
         * c            :: SAME
         * R            :: exactly one character :: removeFirstCustomer (ignore return value)
         * r            :: SAME
         *
         * @return true if command is recognized and format is valid, else false
		 */
		bool NightClubLine::processCommand (string cmd) {
			if (cmd == "A apple" || cmd == "a apple") {
				waitingLine.push("apple");
			}
			else if (cmd == "C" || cmd == "c") {
				clearLine();
			}
			else if (cmd == "R" || cmd == "r") {
				waitingLine.pop();
			}
			else {
				return false;
			}
		
			return true;
		}
