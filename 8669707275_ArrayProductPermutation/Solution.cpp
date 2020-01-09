#include<iostream>
#include<bits/stdc++.h> 
using namespace std;

int findArrayProduct(int n, int A[], int B[]) {
    int product=0;
    for(int i=0;i<n;i++) {
        product += A[i]*B[i];
    }
    return product;
}

int findPermutations(int a[], int n, int b[]) {
	int countProduct=0, MinProduct=0, counter=0;
	sort(a, a + n);
	do{
	   countProduct = findArrayProduct(n, a, b);
	   if(counter==0) {
	   	    MinProduct = countProduct;
	   	}
	   	else if(countProduct < MinProduct) {
	   		MinProduct = countProduct;
	   	}
		counter++;
	} while(next_permutation(a, a + n));
	return MinProduct;	
}

int main() {
    int n, size,FinalProduct;
    cout<<"No of test cases: ";
    cin>>n;
    for(int testCase=0;testCase<n;testCase++) {
    	cout<<endl<<endl;
        FinalProduct = 0;
        cout<<endl<<"Size of arrays: ";
        cin>>size;
        int A[size], B[size];
        
        cout<<endl<<"Enter Array A elements: ";
        for(int i=0;i<size;i++) {
            cin>>A[i];
        }
        cout<<endl<<"Enter Array B elements: ";
        for(int i=0;i<size;i++) {
            cin>>B[i];
        }
        
        FinalProduct = findPermutations(A, size, B);
        cout<<endl<<"test #"<<testCase+1<<" : "<<FinalProduct;
    }
}

