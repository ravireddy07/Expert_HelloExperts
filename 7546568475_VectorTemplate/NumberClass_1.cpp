#include<iostream>
#include<vector>
using namespace std;

template <class T>
class NumberClass {
	private:
		vector<T> vect;
	public:
		NumberClass(T TempVect[], T size) { //getting the values to get initilized for vector
			for(T i=0;i<size;i++) {
				vect.push_back(TempVect[i]); //Pushing the elements of array to Vector
			}
		}

		//Printing the elements/values of Vector
		T printNumber(T size) {
			for(T i=0;i<size;i++) {
				cout<<vect[i]<<" ";
			}
		}

		//Descriptional Printing the elements/values of Vector
		T printNumberWithDescription(T size) {
			for(T i=0;i<size;i++) {
				cout<<endl<<"Element at index "<<i<<" is: "<<vect[i];
			}
		}
};


int main() {
	int arr[] = {99, 34, 12, 44, 77, 2, 37, 4, 54, 68, 44, 102, 5, 42}; //storing values
	int n = sizeof(arr)/sizeof(arr[0]);
	NumberClass <int> mynum(arr, n);
	mynum.printNumber(n); //Printing
	//mynum.printNumberWithDescription(n); //Printing

	return 0;
}
