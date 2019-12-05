#include<bits/stdc++.h>
#include<iostream>

using namespace std;
int ASCII_difference=31;

int charCheck(char input_char) {
	return (input_char&ASCII_difference); //bit operation
} 

int main() {
	string str;
	int loc;
	cout<<"Enter the charcters and press enter :";
	cin>>str;
	cout<<endl;
	for(int i=0;i<str.length();i++) {
		if((str[i] >= 65 && str[i]	<=90) || (str[i] >= 97 && str[i] <= 122)) {
			loc = charCheck(str[i]);
			cout<<str[i]<<" is at Location: "<<loc<<endl;
		}
		else {
			cout<<-1<<endl;
		}
	}
	return 0;
}
