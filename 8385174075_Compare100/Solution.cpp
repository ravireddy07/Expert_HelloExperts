#include<bits/stdc++.h>
#include<iostream>

using namespace std;

int readData(int x[]) {
	int checkValue=0, size=0, array[2];
	cout<<"Enter Values to x: "<<endl;
	for(int i=0;i<100;i++) {
		cin>>checkValue;
		if(checkValue != 999) {
			x[i] = checkValue;
			size++;
		}
		else {
			cout<<"The size of x[] is: "<<size<<endl;
			return size;
		}
	}
	
	cout<<"The size of x[] is: "<<size<<endl;
	return size;
}

void testing(int x[], int array[], int size) {
	int currentSmall=x[0], currentBig=x[0];
	for(int i=0;i<size;i++) {
		if(x[i]>=currentBig) {
			currentBig = x[i];
			array[1] = currentBig;
		}
		else if(x[i]<=currentSmall) {
			currentSmall = x[i];
			array[0] = currentSmall;
		}
	}
	cout<<endl<<"Smallest is: "<<currentSmall<<endl<<"Largest is: "<<currentBig<<endl<<endl;
	return;
}


int main() {
	int x[100], array[2], sizeofX;
	sizeofX = readData(x);
	testing(x, array, sizeofX);
	return 0;
}
