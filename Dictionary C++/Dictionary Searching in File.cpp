#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;

int main()
{
	fstream file;
	string name,search;
	int counter = 0;
	
	file.open("Dictionary.txt");
	
while(file >>name)
{
		cout<<"Enter the Word to Search in the File: ";
		cin>>search;
		
	while(file >>name)
		{
		if(search == name)
		{
			cout<<"Word is Found in the File at place: "<<counter<<endl<<endl;
			counter++;
		}
		else
		{
			cout<<"Word is Not Found in the File at Place: "<<counter<<endl<<endl;
			counter++;
		}
	}
		
	
}
	file.close();
	return 0;
}
