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
				throw logic_error("EMPTY QUEUE");
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
				throw logic_error("EMPTY QUEUE");
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
				throw logic_error("EMPTY QUEUE");
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
			waitingLine = queue<string>();
		}

		/*
		 * Get the number of customer currently in line.
		 * @return the number of customers currently in line
		 */
		uint32_t NightClubLine::getNumCustomers () {
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
			if (!ifile.is_open()) {
				ifile.close();
	        	return false;
    		}
			while (!ifile.eof()) {
				getline(ifile,place_holder);
				processCommand(place_holder);
			}
			
			ifile.close();
			
			return true;
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
			if (cmd.size() > 0 ) {
				if ((cmd.at(0) == 'A' || cmd.at(0) == 'a') && cmd.size() > 3) {
					string temp_string = cmd.substr(2,cmd.size()-1);
					waitingLine.push(temp_string);
				}
				else if (cmd.at(0) == 'C' || cmd.at(0) == 'c') {
					clearLine();
				}
				else if (cmd.at(0) == 'R' || cmd.at(0) == 'r') {
					waitingLine.pop();
				}
				else {
					return false;
				}
			}
			else {
				return false;
			}
			return true;
		}
