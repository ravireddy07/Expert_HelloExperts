Design a class named NumberClass that has a vector of any data type (use Class Template).
You should create a parameterized constructor that accept the initialization value for the vector.
There should also be member functions to perform the following operations: - Print (cout) each element stored in the vector. -

#include <iostream>
#include <vector>
using namespace std;
//create code here

int main() {

vector<int>myNum({99,34,12,44,77,2,37,4,54,68, 44, 102, 5, 42});
cout << "Print the elements in the vector" << endl;
myNum.printNumber();
}
