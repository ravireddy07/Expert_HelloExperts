#include<iostream>
#include "Solution.h"
using namespace std;

int main() {
    string array[5],str;
    for(int i=0;i<5;i++) {
        cout<<"Enter string #"<<i+1;
        cin>>array[i];
        cout<<endl;
    }
    LongestString(array, 5);
}

