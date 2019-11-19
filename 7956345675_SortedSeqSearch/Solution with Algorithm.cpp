#include<bits/stdc++.h>
#include<iostream>
using namespace std;

/* Complexcity O(1) */

/*    Algorithm

1-  take input of array and item to be searched
2-  set pos=0 and found = false
3-  while (end of the array)&&(item not found):
          if ar[pos] == item:
	         found = True
	         return Item found and Exit().
	      else:
	         pos = pos+1
4-  Print Item not Found and Exit().
*/

void compare(int ar[], int item, int n) {
	int pos = 0;
	bool found = false;
	
	while(pos<n && !found) {
		if(ar[pos] == item) {
			found = true;
			cout<<endl<<"Item Found at index "<<pos<<" in the array.";
			return;
		}
		else {
			pos+=1;
		}
	}
	cout<<endl<<"Item not found";
	return;
}

int main() {
	 
	//User input 
	int n,item;
	cout<<"Enter the size of the array: ";
	cin>>n;
	int ar[n];
	
	cout<<endl<<"Enter the elements of the array :"<<endl;
	for(int i=0;i<n;i++) {
		cin>>ar[i];
	}
	
	cout<<endl<<"enter the item to be searched in the Array: ";
	cin>>item;
	
	//int ar[10] = {1,3,5,53,62,34,50,6,26,65},item = 43;
	compare(ar,item,n/*(sizeof(ar)/sizeof(ar[0]))*/);
}
