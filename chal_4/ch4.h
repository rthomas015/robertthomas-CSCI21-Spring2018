#ifndef ch4_h
#define ch4_h

/**********************************************/
/***** Programming Challenge 4       SPEC *****/
/**********************************************/

#include <fstream>
#include <queue>
#include <string>
#include <stdexcept>

using namespace std;

class NightClubLine {
	private:
		queue<string> waitingLine;
		
	public:

		void addCustomer (string customerName);
		string getFirstCustomer () throw(logic_error);
		string getLastCustomer () throw(logic_error);
		
		string removeFirstCustomer () throw(logic_error);
		void clearLine ();
		
		uint32_t getNumCustomers ();

		bool isEmpty ();
		
		bool processFile (string filename);


		bool processCommand (string cmd);


};

#endif