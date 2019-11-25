#include<iostream>
using namespace std;

void SquarePattern() {
	int size;
	startAgain:
	cout<<"Enter size between 1-9 only: "<<endl;
	cin>>size;
	if(size >= 1 and size <=9) {
		for(int i=0;i<size;i++) {
			for(int j=0;j<size;j++) {
				cout<<size;
			}
			cout<<endl;
		}
	}
	else {
		cout<<"Not vaild size... Try again."<<endl;
		goto startAgain;
	}
}

void TrianglePattern() {
	int size;
	startagain:
	cout<<"Enter size between 1-9 only: "<<endl;
	cin>>size;
	if(size >= 1 and size <=9) {
		for(int i=0;i<size;i++) {
			for(int j=0;j<i+1;j++) {
				cout<<size;
			}
			cout<<endl;
		}
	}
	else {
		cout<<"Not vaild size... Try again."<<endl;
		goto startagain;
	}
}

void DiaginalPattern() {
	int size;
	Startagain:
	cout<<"Enter size between 1-9 only: "<<endl;
	cin>>size;
	if(size >= 1 and size <=9) {
		for(int i=0;i<size;i++) {
			for(int j=0;j<size;j++) {
				if(i==j) {
					cout<<size;
				}
				else {
					cout<<"*";
				}
			}
			cout<<endl;
		}
	}
	else {
		cout<<"Not vaild size... Try again."<<endl;
		goto Startagain;
	}
}

void ReverseDiaginalPattern() {
	int size;
	StartAgain:
	cout<<"Enter size between 1-9 only: "<<endl;
	cin>>size;
	if(size >= 1 and size <=9) {
		for(int i=size;i>0;i--) {
			for(int j=0;j<size;j++) {
				if(i==j+1) {
					cout<<size;
				}
				else {
					cout<<"*";
				}
			}
			cout<<endl;
		}
	}
	else {
		cout<<"Not vaild size... Try again."<<endl;
		goto StartAgain;
	}
}


int main() {
	char choice, repeat;
	
	startAgain:
	do{
		cout<<"\t\t1. Square Pattern"<<endl;
		cout<<"\t\t2. Triangle Pattern"<<endl;
		cout<<"\t\t3. Diaginal Pattern"<<endl;
		cout<<"\t\t4. Reverse diaginal Pattern"<<endl;
		cout<<"\t\t5. Quit"<<endl;
		cin>>choice;
		
		if(choice == '1') {
			SquarePattern();
		}
		else if(choice == '2') {
			TrianglePattern();
		}
		else if(choice == '3') {
			DiaginalPattern();
		}
		else if(choice == '4') {
			ReverseDiaginalPattern();
		}
		else if(choice == '5') {
			cout<<"Exit Successfull..!!"<<endl;
			return 0;
		}
		else {
			cout<<"Not a Valid Option, Try again."<<endl;
		}
		cout<<endl<<"Repeat Selection, Press 'y' to continue:";
		cin>>repeat;
	}while(repeat == 'y' || repeat == 'Y');
	return 0;
}
