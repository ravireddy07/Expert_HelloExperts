#include<iostream>
#include<fstream>
#include<iomanip>
#define MAX 100  //define here the size of th array

using namespace std;
void getNames(string names[], int marks[], int& numElts);

int main() {
    string names[MAX];
    int marks[MAX], numElts;
    getNames(names, marks, numElts);
    return 0;
}

void getNames(string names[], int marks[], int& numElts) {
	string filename = "data.txt";
	
	ifstream fin(filename.c_str());
    
    if(fin.is_open()) {
        numElts = 0;
        while(!fin.eof()) {
            fin>>names[numElts];
            fin>>marks[numElts];
            numElts++;
        }
        fin.close();
    }
    else {
        cout<<"Unable to open file : "<<filename<<endl;
    }
    
    //Displaying
    cout<<" Names\t\t Marks"<<endl;
    for(int i=0;i<numElts;i++) {
        cout<<" "<<names[i]<<" \t  "<<marks[i]<<endl;
    }
    cout<<endl<<"Total: "<<numElts<<endl;
    return;
}
