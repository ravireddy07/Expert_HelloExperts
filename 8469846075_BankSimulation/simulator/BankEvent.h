//  Created by Samir B. Bhatt

/** @file BankEvent.h */ 
 
#ifndef _BANK_EVENT
#define _BANK_EVENT

enum EventType { ARRIVAL, DEPARTURE };

class BankEvent {
private:
	EventType type;
	int time;
	int duration;
	int tellerNum;
public:
	BankEvent();
	BankEvent(EventType et, int t, int d, int tn);

	EventType getType();
	int getTime();
	int getDuration();
	int getTellerNum();

	void setType(EventType et);
	void setTime(int t);
	void setDuration(int d);
	void setTellerNum(int tn);

	friend bool operator< (BankEvent &be1, BankEvent &be2);
	friend bool operator> (BankEvent &be1, BankEvent &be2);

	~BankEvent();
};

#endif