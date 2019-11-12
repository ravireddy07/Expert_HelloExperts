#include<iostream>
using namespace std;

void LongestString(string ar[], int n);

void LongestString(string ar[], int n) {
    string str;
    int maxLength=0;
    for(int i=0;i<n;i++) {
        if(ar[i].size() > maxLength) {
            maxLength = ar[i].size();
            str = ar[i];
        }
    }
    cout<<"The longest string is: "<<str<<endl<<"Having the length of "<<maxLength;
}
