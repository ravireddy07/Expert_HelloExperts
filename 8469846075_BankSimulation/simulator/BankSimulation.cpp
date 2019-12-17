/*
Program Description: Write a detailed description of WHAT this program does from a user's perspective.
It's extremely imortant that you can provide a detailed and relevant description in this space.

Written By: FirstName LastName

Date Submitted: mm/dd/yyyy

IDE Used: Xcode / Visual Studio Express 2013 / Code::Blocks / ...
*/
// All include statements starting from here
#include <iostream>
#include <string>
#include "Bank.h"

using namespace std;

// Main function
int main() {
	// Animation
	StateProxyClient proxy(
      grpc::CreateChannel("localhost:50051", grpc::InsecureCredentials(),
                          ChannelArguments()));

	Bank b("test.txt", 3, false, &proxy);

	// Bank parameters: (input file, # tellers, Single line?, debug?)

	// Simulate a bank with 1 tellers and 1 line
	//Bank b("test.txt", 1, false, false);
	
	// Simulate a bank with 3 tellers and 1 line
	//Bank b("test.txt", 3, true, false);

	// Simulate a bank with 3 tellers and 3 line
	//Bank b("test.txt", 3, false, false);
	
	b.simulate();

	return 0;
}

// All function definitions starting from here

/*
Copy program interaction between user and the program here.
*/
