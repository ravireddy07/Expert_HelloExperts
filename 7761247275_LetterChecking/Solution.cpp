/*
public class LastFirst {
	public static String check (String s) {
		return "fun";
	}
}

If the first letter is bigger than the last, return "aplus".
If the last letter is bigger than the first, return "compsci"
if the first and last letters are same, return "apluscompsci"

*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;



//Checking conditions.
int Case1_Case2_Case3(string s) {
	int n = s.length();
	if(n < 2) {
		return 0;
	}
	else if(s[0] < s[n-1]) {
		return 11;                    // first one represent that case1 and second one represent's true.
	}
	else if(s[0] > s[n-1]) {
		return 21;					  // 2 represent that case2 and second one represent's true.
	}
	else if(s[0] == s[n - 1]) {
		return 31;                    // 3 represent that case3 and second one represent's true.
	}
	else {
		return 0;
	}
}



int main() {
	string ss;
	cout<<"Enter String: ";
	cin>>ss;
	
	int result1;
	result1 = Case1_Case2_Case3(ss);
	
	
	if(result1 == 11) {
		cout<<endl<<"aplus";
		return 0;
	}
	else if(result1 == 21) {
		cout<<endl<<"compsci";
		return 0;
	}
	else if(result1 == 31) {
		cout<<endl<<"apluscompsci";
		return 0;
	}
	else{
		cout<<endl<<"Invalid String..!";
		return 0;
	}
}
