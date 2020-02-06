#include<bits/stdc++.h>
using namespace std;


int main() {
    int n, temp;
	cin>>n;
	int ar[n];
	for(int i=0;i<n;i++) {
		cin>>ar[i];
	}
	
	for(int i=0;i<n;i++) {
		for(int j=i+1;j<n;j++) {
			if(ar[i]>ar[j]) {
				temp = ar[i];
				ar[i] = ar[j];
				ar[j] = temp;
			}
		}
	}
	
	for(int i=0;i<n;i+=2) {
		cout<<ar[i]<<" ";
	}
	
}
