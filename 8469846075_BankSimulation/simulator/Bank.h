//  Created by Samir B. Bhatt

/** @file Bank.h */ 
 
#ifndef _BANK
#define _BANK

#include "Heap_PriorityQueue.h"
#include "ListQueue.h"
#include "BankEvent.h"
#include "StateProxyClient.h"

class Bank {
private:
	Heap_PriorityQueue<BankEvent>* eventQ;
	ListQueue<BankEvent>* tellerLine;
	int* tellerLineLength;

	int customerCount;
	bool oneLine;
	int tellerCount;

	int totalWaitTime;
	double avgWaitTime;
	int maxWaitTime;

	int* totalTellerLineLength;
	int tellerLineLengthSampleSize;
	int maxLineLength;

	std::string eventFile;

	bool loadEvents();

	// Utility Functions
	int findMin(int arr[], int size);

	bool debug;

	StateProxyClient* proxy;
public:
	Bank(std::string ef);
	Bank(std::string ef, int tc);
	Bank(std::string ef, int tc, bool ol, bool d);
	Bank(std::string ef, int tc, bool d, StateProxyClient* proxyClient);

	void simulate();
	void printStatistics();

	~Bank();
};

#endif