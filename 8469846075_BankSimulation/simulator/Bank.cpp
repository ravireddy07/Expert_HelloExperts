//  Created by Samir B. Bhatt

/** @file Bank.cpp */ 

#include <iostream>
#include <fstream>
#include <sstream>
#include "Bank.h"

using banksimulation::BankSimulatorState;

// Constructors
Bank::Bank(std::string ef) :
	eventFile(ef),
	tellerCount(1),
	oneLine(false),
	debug(false),
	proxy(nullptr)
{
}

Bank::Bank(std::string ef, int tc) :
	eventFile(ef),
	tellerCount(tc),
	oneLine(false),
	debug(false),
	proxy(nullptr)
{
}

Bank::Bank(std::string ef, int tc, bool ol, bool d) :
	eventFile(ef),
	tellerCount(tc),
	oneLine(ol),
	debug(d),
	proxy(nullptr)
{
}

Bank::Bank(std::string ef, int tc, bool d, StateProxyClient* proxyClient) : 
	eventFile(ef),
	tellerCount(tc),
	oneLine(false),
	debug(d),
	proxy(proxyClient)
{
}

// Utility functions

// NO NEED TO SORT!!!
int Bank::findMin(int source_arr[], int size) {
	// Create temporary array and copy contents of source array
	int* temp_arr = new int[size];
	for (int i = 0; i < size; i++) {
		temp_arr[i] = source_arr[i];
	}

	// Insertion sort is best for small arrays
	for (int i = 1; i < size; i++) {
		int x = temp_arr[i];
		int j = i;
		while (j > 0 && temp_arr[j - 1] > x) {
			temp_arr[j] = temp_arr[j - 1];
			j--;
		}
		temp_arr[j] = x;
	}

	int result = temp_arr[0];

	if (debug) {
		cout << "findMin: [";
		for (int i = 0; i < size; i++)
			cout << temp_arr[i] << ", ";
		cout << "]" << endl;
	}

	delete[] temp_arr;

	return result;
}

// Private helper functions
bool Bank::loadEvents() {
	BankEvent* arrivalEventArr;
	customerCount = 0;

	std::string line;
	ifstream iFile(eventFile);

	if (iFile.is_open()) {
		// First pass through input file is to get customerCount
		while (std::getline(iFile, line)) {
			customerCount++;
		}

		//std::cout << "Number of Events: " << customerCount << endl;

		arrivalEventArr = new BankEvent[customerCount];
		int arrIndex = 0;

		iFile.clear();
		iFile.seekg(0);

		// Second pass generates Arrival events
		while (std::getline(iFile, line)) {
			std::stringstream ss(line);
			std::string time, duration;

			std::getline(ss, time, ' ');
			std::getline(ss, duration, ' ');

			//std::cout << "Time: " << time << " Duration: " << duration << endl;
			arrivalEventArr[arrIndex] = BankEvent(ARRIVAL, std::stoi(time), std::stoi(duration), 0);
			arrIndex++;

		}

		iFile.close();

		// Create the main event queue
		eventQ = new Heap_PriorityQueue<BankEvent>(arrivalEventArr, customerCount);

		/*** Begin GRPC Hook ***/
		if(proxy != nullptr) {
			Heap_PriorityQueue<BankEvent> tempQ(arrivalEventArr, customerCount);
			BankEvent* tempArr = new BankEvent[customerCount];

			for(int i = 0; i < customerCount; i++) {
				tempArr[i] = tempQ.peek();
				tempQ.remove(); 
			}

			proxy->populateEventList(tempArr, customerCount);
			proxy->setAction(BankSimulatorState::EVENTS_LOADED);
			proxy->setTellerCount(tellerCount);
			proxy->SendState();

			delete[] tempArr;
		}
		/*** End GRPC Hook ***/
	}
	else {
		std::cout << "Unable to open " << eventFile << std::endl;
		return false;
	}

	delete[] arrivalEventArr;
	
	return true;
	
}

// Public methods
void Bank::simulate() {
	// First load events from input file
	
	if(!loadEvents())
		return;

	// Dynamically create teller line array

	if(oneLine) {
		tellerLine = new ListQueue<BankEvent>[1];
		tellerLineLength = new int[1];
		totalTellerLineLength = new int[1];
	} else {
		tellerLine = new ListQueue<BankEvent>[tellerCount];
		tellerLineLength = new int[tellerCount];
		totalTellerLineLength = new int[tellerCount];
	}
	
	bool* tellerAvailable = new bool[tellerCount];

	// Initialize class variables and arrays tracking statistics
	totalWaitTime = 0;
	maxWaitTime = 0;
	maxLineLength = 0;

	if(oneLine) {
		tellerLineLength[0] = 0;
		totalTellerLineLength[0] = 0;
	} else {
		for (int i = 0; i < tellerCount; i++) {
			tellerLineLength[i] = 0;
			totalTellerLineLength[i] = 0;
			tellerAvailable[i] = true;
		}
	}

	// Sample size is based on number of loop iterations
	tellerLineLengthSampleSize = 0;

	// Begin main loop
	std::cout << "Simulation Begins" << endl;
	while (!eventQ->isEmpty()) {
		BankEvent currentEvent = eventQ->peek();
		int currentTime = currentEvent.getTime();

		if (debug) {
			if(oneLine) {
				cout << endl << "LineLength: [";
				cout << tellerLineLength[0] << ", ";
				cout << "]" << endl;
			} else {
				cout << endl << "tellerLineLength: [";
				for (int i = 0; i < tellerCount; i++)
					cout << tellerLineLength[i] << ", ";
				cout << "]" << endl;
			}

			cout << "tellerAvailable: [";
			for (int i = 0; i < tellerCount; i++)
				cout << tellerAvailable[i] << ", ";
			cout << "]" << endl;
		}
		
		switch (currentEvent.getType()) {
		case ARRIVAL:
		{
			eventQ->remove();

			int tellerNum = -1;

			for (int i = 0; i < tellerCount; i++) {
				if (tellerAvailable[i]) {
					tellerNum = i;

					if (debug) {
						cout << "tellerNum: " << tellerNum << endl;
					}
					
					break;
				}

			}

			if(oneLine) {
				;
			} else {
				if (tellerNum == -1) {
					// Find smallest teller line
					//int minTellerLineLength = findMin(tellerLineLength, tellerCount);
					int minTellerLineLength = tellerLineLength[0];

					for (int i = 1; i < tellerCount; i++) {
						if (tellerLineLength[i] < minTellerLineLength) {
							minTellerLineLength = tellerLineLength[i];
						}
					}

					if (debug) {
						cout << "minTellerLineLength: " << minTellerLineLength << endl;
					}

					for (int i = 0; i < tellerCount; i++) {
						if (tellerLineLength[i] == minTellerLineLength) {
							tellerNum = i;

							if (debug) {
								cout << "tellerNum: " << tellerNum << endl;
							}

							break;
						}
					}
				}
			}

			if(oneLine) {
				if (tellerLine[0].isEmpty() && tellerNum != -1 && tellerAvailable[tellerNum]) {
					// Teller line is empty and teller is available
					// Send customer to teller and create Departure event

					/*** Begin GRPC Hook ***/
					tellerAvailable[tellerNum] = false;
					
					eventQ->add(BankEvent(DEPARTURE, currentTime + currentEvent.getDuration(), 0, tellerNum));

					if(proxy != nullptr) {
						proxy->setCurrentTime(currentTime);
						proxy->setTellerNum(tellerNum);
						proxy->setAction(BankSimulatorState::CUSTOMER_SENT_DIRECTLY_TO_TELLER);
						proxy->SendState();
					}
					
					/*** End GRPC Hook ***/
				}
				else {
					/*** Begin GRPC Hook ***/
					tellerLine[0].enqueue(currentEvent);
					tellerLineLength[0]++;

					if(proxy != nullptr) {
						proxy->setCurrentTime(currentTime);
						proxy->setTellerNum(tellerNum);
						proxy->setAction(BankSimulatorState::CUSTOMER_SENT_TO_TELLER_LINE);
						proxy->SendState();
					}
					/*** End GRPC Hook ***/

					// Keep track of overall largest line length
					if (tellerLineLength[0] > maxLineLength)
						maxLineLength = tellerLineLength[0];
				}
			} else {
				if (tellerLine[tellerNum].isEmpty() && tellerAvailable[tellerNum]) {
					// Teller line is empty and teller is available
					// Send customer to teller and create Departure event

					/*** Begin GRPC Hook ***/
					tellerAvailable[tellerNum] = false;
					
					eventQ->add(BankEvent(DEPARTURE, currentTime + currentEvent.getDuration(), 0, tellerNum));

					if(proxy != nullptr) {
						proxy->setCurrentTime(currentTime);
						proxy->setTellerNum(tellerNum);
						proxy->setAction(BankSimulatorState::CUSTOMER_SENT_DIRECTLY_TO_TELLER);
						proxy->SendState();
					}
					/*** End GRPC Hook ***/
				}
				else {
					/*** Begin GRPC Hook ***/
					tellerLine[tellerNum].enqueue(currentEvent);
					tellerLineLength[tellerNum]++;

					if(proxy != nullptr) {
						proxy->setCurrentTime(currentTime);
						proxy->setTellerNum(tellerNum);
						proxy->setAction(BankSimulatorState::CUSTOMER_SENT_TO_TELLER_LINE);
						proxy->SendState();
					}
					/*** End GRPC Hook ***/

					// Keep track of overall largest line length
					if (tellerLineLength[tellerNum] > maxLineLength)
						maxLineLength = tellerLineLength[tellerNum];
				}
			}
			
			if(tellerNum == -1) {
				std::cout << "Adding arrival event to line at time:\t" << currentTime << endl;
			} else {
				std::cout << "(Teller " << tellerNum + 1 << ") Processing arrival event at time:\t" << currentTime << endl;
			}
			
			break;
		}
		case DEPARTURE:
		{
			int tellerNum = currentEvent.getTellerNum();

			std::cout << "(Teller " << tellerNum + 1 << ") Processing departure event at time:\t" << currentTime << endl;

			/*** Begin GRPC Hook ***/
			eventQ->remove();

			if(proxy != nullptr) {
				proxy->setCurrentTime(currentTime);
				proxy->setTellerNum(tellerNum);
				proxy->setAction(BankSimulatorState::CUSTOMER_EXIT);
				proxy->SendState();
			}
			/*** End GRPC Hook ***/

			if(oneLine) {
				if (!tellerLine[0].isEmpty()) {
					// Send customer to teller and create Departure event
					currentEvent = tellerLine[0].peekFront();

					// Calculate and keep track of wait times
					int waitTime = currentTime - currentEvent.getTime();
					if (waitTime > maxWaitTime)
						maxWaitTime = waitTime;

					totalWaitTime += waitTime;

					/*** Begin GRPC Hook ***/
					tellerLine[0].dequeue();
					tellerLineLength[0]--;

					if(proxy != nullptr) {
						proxy->setCurrentTime(currentTime);
						proxy->setTellerNum(tellerNum);
						proxy->setAction(BankSimulatorState::CUSTOMER_SENT_TO_TELLER_FROM_LINE);
						proxy->SendState();
					}
					/*** End GRPC Hook ***/

					eventQ->add(BankEvent(DEPARTURE, currentTime + currentEvent.getDuration(), 0, tellerNum));
				}
				else {
					tellerAvailable[tellerNum] = true;
				}
			} else {
				if (!tellerLine[tellerNum].isEmpty()) {
					// Send customer to teller and create Departure event
					currentEvent = tellerLine[tellerNum].peekFront();

					// Calculate and keep track of wait times
					int waitTime = currentTime - currentEvent.getTime();
					if (waitTime > maxWaitTime)
						maxWaitTime = waitTime;

					totalWaitTime += waitTime;

					/*** Begin GRPC Hook ***/
					tellerLine[tellerNum].dequeue();
					tellerLineLength[tellerNum]--;

					if(proxy != nullptr) {
						proxy->setCurrentTime(currentTime);
						proxy->setTellerNum(tellerNum);
						proxy->setAction(BankSimulatorState::CUSTOMER_SENT_TO_TELLER_FROM_LINE);
						proxy->SendState();
					}
					/*** End GRPC Hook ***/

					eventQ->add(BankEvent(DEPARTURE, currentTime + currentEvent.getDuration(), 0, tellerNum));
				}
				else {
					tellerAvailable[tellerNum] = true;
				}
			}

			break;
		}
		default:
			break;
		}

		// Update total line lengths for statistics
		if(oneLine) {
			totalTellerLineLength[0] += tellerLineLength[0];
		} else {
			for (int i = 0; i < tellerCount; i++)
				totalTellerLineLength[i] += tellerLineLength[i];
		}
		
		tellerLineLengthSampleSize++;
		
	}

	delete[] tellerAvailable;

	/*** Begin GRPC Hook ***/
	if(proxy != nullptr) {
		proxy->setAction(BankSimulatorState::SIMULATION_END);
		proxy->SendState();
	}

	printStatistics();
	/*** End GRPC Hook ***/
}

void Bank::printStatistics() {
	std::cout << "Simulation Ends" << endl << endl;
	std::cout << "Final Statistics:" << endl;
	std::cout << "\tTotal Customers Processed: " << customerCount << endl;
	avgWaitTime = (double)totalWaitTime / customerCount;
	std::cout << "\tAverage Wait Time: " << avgWaitTime << endl;
	std::cout << "\tMaximum Wait Time: " << maxWaitTime << endl << endl;

	if(oneLine) {
		std::cout << "\tAverage Line Length : " << (double)totalTellerLineLength[0] / tellerLineLengthSampleSize << endl;
	} else {
		for (int i = 0; i < tellerCount; i++)
			std::cout << "\tAverage Line Length (Teller " << i+1 << "): " << (double)totalTellerLineLength[i] / tellerLineLengthSampleSize << endl;
	}
	std::cout << endl;
	std::cout << "\tMaximum Line Length: " << maxLineLength << endl;
}

// Destructor
Bank::~Bank() {
	delete[] tellerLine;
	delete[] tellerLineLength;
	delete[] totalTellerLineLength;
	delete eventQ;
}
