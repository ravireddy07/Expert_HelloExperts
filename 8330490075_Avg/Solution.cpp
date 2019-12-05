#include<bits/stdc++.h>
#include<iostream>
#include<iomanip>

using namespace std; 
int n=10;

int main() {
	int ar[n],sum=0, min, max;
	double average, temp;
	cout<<"Enter 10 value to array: "<<endl;
	for(int i=0;i<n;i++) {
		cin>>ar[i];
		sum += ar[i];
	}
	
	cout<<"Value Percent of Total:"<<endl;
	for(int i=0;i<n;i++) {
		temp = (double)(ar[i])/2;
		cout<<ar[i]<<setw(7)<<fixed<<setprecision(2)<<temp<<endl;	
	}
	min = ar[0];
	max = ar[0];
	
	for(int i=0;i<n;i++) {
		if(ar[i]>max) {
			max = ar[i];
		}
		else if(ar[i]<min) {
			min = ar[i];
		}
	}
	cout<<endl<<endl<<"Values used range from "<<min<<" to "<<max<<endl<<endl;
	average = (float)sum/10;
	cout<<"Average of the Ten Values = "<<fixed<<setprecision(2)<<average<<endl<<endl;
	
	cout<<"Values above the Average "<<endl<<endl;
	
	for(int i=0;i<n;i++) {
		if(ar[i]>average) {
			cout<<ar[i]<<endl<<endl;
		}
	}

	return 0;
}
