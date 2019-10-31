/*
Write a program named TemperaturesComparison that allows a user to input five daily Fahrenheit temperatures that must range from -30 to 130; 
if a temperature is out of range, require the user to reenter it. If no temperature is lower than any previous one, display a message Getting warmer. 
If every temperature is lower than the previous one, display a message Getting cooler. If the temperatures are not entered in either ascending or descending order,
display a message It’s a mixed bag. Finally, display the temperatures in the order they were entered, and then display the average of the temperatures.
*/

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void Display(int ar[], int n) {
	for(int i=0;i<n;i++) {
		cout<<ar[i]<<" ";
	}
	return;
}


int main() {
	int dailyFahren[5], count=0;
	
	while(count != 5) {
		cout<<"\nEnter the "<<count+1<<"st Temperature >> ";
		cin>>dailyFahren[count];
		if(dailyFahren[count] < 130 && dailyFahren[count] > -30) {
			count++;      //if temperature is in range , then only we will increment index and take next input
		}
		else {
			cout<<"Out of Range --  	please re-enter\n";
		}
	}
	
	
	if(dailyFahren[0]>dailyFahren[1] && dailyFahren[1]>dailyFahren[2] && dailyFahren[2]>dailyFahren[3] && dailyFahren[3]>dailyFahren[4]) {
		cout<<"\n Getting warmer : ";
		Display(dailyFahren, 5);
	}
	else if(dailyFahren[0]<dailyFahren[1] && dailyFahren[1]<dailyFahren[2] && dailyFahren[2]<dailyFahren[3] && dailyFahren[3]<dailyFahren[4]) {
		cout<<"\n Getting cooler : ";
		Display(dailyFahren, 5);
	}
	else {
		cout<<"\n It's a mixed bag : ";
		Display(dailyFahren, 5);
	}
}
