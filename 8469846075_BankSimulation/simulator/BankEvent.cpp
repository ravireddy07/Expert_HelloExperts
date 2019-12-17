//  Created by Samir B. Bhatt

/** @file BankEvent.cpp */ 
 
#include "BankEvent.h"

BankEvent::BankEvent() {

}

BankEvent::BankEvent(EventType et, int t, int d, int tn) : type(et), time(t), tellerNum(tn) {
	if (et == DEPARTURE) {
		duration = 0;
	}
	else {
		duration = d;
	}

}

EventType BankEvent::getType() {
	return type;
}

int BankEvent::getTime() {
	return time;
}

int BankEvent::getDuration() {
	return duration;
}

int BankEvent::getTellerNum() {
	return tellerNum;
}

void BankEvent::setType(EventType et) {
	type = et;
}

void BankEvent::setTime(int t) {
	time = t;
}

void BankEvent::setDuration(int d) {
	duration = d;
}

void BankEvent::setTellerNum(int tn) {
	tellerNum = tn;
}

bool operator< (BankEvent &be1, BankEvent &be2) {
	return (be1.getTime() < be2.getTime());
}

bool operator> (BankEvent &be1, BankEvent &be2) {
	return (be1.getTime() > be2.getTime());
}

BankEvent::~BankEvent() {

}