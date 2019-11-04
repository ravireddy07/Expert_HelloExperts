#include<iostream>
using namespace std;
#define ll long long int


int FunctionlengthOfTicketNumber(ll num) {
	int count=0;
	while(num != 0) {
		count++;
		num /= 10;
    }
    return count;
}

int main() {
	ll ticketNumber, sum1=0, sum2=0;
	cout<<"Enter Ticket Number to check wheither Lucky or not: ";
	cin>>ticketNumber;
	
	int lengthOfTicketNumber = FunctionlengthOfTicketNumber(ticketNumber);
	
	for(int i=0;i<lengthOfTicketNumber;i++) {
		if(i<lengthOfTicketNumber/2) {
			sum2 += ticketNumber%10;
			ticketNumber /= 10;
		}
		else {
			sum1 += ticketNumber%10;
			ticketNumber /= 10;
		}
	}
	
	if(sum1 == sum2) {
		cout<<endl<<"True";
	}
	else {
		cout<<endl<<"False";
	}
}
