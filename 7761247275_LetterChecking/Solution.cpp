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
#define MAX_CHAR 26

//If the first letter is bigger than the last, return "aplus".
int Case1AndCase2AndCase3(string &str) {
	int charCount[MAX_CHAR] = {0};      //to keep count of characters, Initially count of all characters is initialized to zero. 
	int n = str.length();
	
	 
	for (int i=0; i<n; i++) {			//Traverse string and increment count of characters
		charCount[str[i]-'a']++;
	}
	
	// 'a'-'a' will be 0, 'b'-'a' will be 1, so for location of character in count array we wil do str[i]-'a'. 
			 

	for(int i=0;i<1;i++) {
      if(str[i] > str[n]) {
        return 11;
      }
      else if(str[i] < str[n]) {
        return 21;
      }
      else if(str[i] == str[n]) {
      	return 31;
	  }
      else {
        return 0;
      }
    }
}



/*
//Checking if the first and last letters are same.
int Case3(string s) {
	int n = s.length();
	if(n < 2) {
		return -1;
	}
	
	if(s[0] == s[n - 1]) {
		return 1;
	}
	else {
		return 0;
	}
}
*/


int main() {
	string ss;
	cin>>ss;
	
	int result1;
	result1 = Case1AndCase2AndCase3(ss);
	
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
		return 0;
	}
}
