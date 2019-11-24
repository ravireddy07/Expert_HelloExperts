#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string>
using namespace std;

int main() {
	string input = "price.dat";
	string output = "output.dat";
	string descrip;
	double price, NumOfReadings=0, Maximum_Price=0, Minimum_Price, Avg_Price=0;
	ifstream inFile;
	ofstream outFile;
	inFile.open(input.c_str());
	outFile.open(output.c_str());
	if (inFile.fail() || outFile.fail()) {
		cout<<"\nThe file was not successfully opened"
			<<"\n Please check that the file currently exists."
			<<endl;
		system("PAUSE");
		exit(1);
	}
	
	inFile>>descrip>>price;
	Minimum_Price = price;
	while (inFile.good()) {
		//cout<<descrip<<' '<<price<<endl;
		if(Maximum_Price < price) {
			Maximum_Price = price;
		}
		else if(Minimum_Price > price) {
			Minimum_Price = price;
		}	
		Avg_Price += price;
		NumOfReadings++;
		inFile>>descrip>>price;
	}
	
	cout<<endl<<"Number of Price Readings: "<<NumOfReadings;
	outFile<<"Number of Price Readings: "<<NumOfReadings<<endl;
	cout<<endl<<"Maximum Price: "<<Maximum_Price;
	outFile<<"Maximum Price: "<<Maximum_Price<<endl;
	cout<<endl<<"Minimum Price: "<<Minimum_Price;
	outFile<<"Minimum Price: "<<Minimum_Price<<endl;
	cout<<endl<<"Average Price: "<<(Avg_Price/NumOfReadings);
	outFile<<"Average Price: "<<(Avg_Price/NumOfReadings)<<endl;
	cout<<endl;
	inFile.close();
	outFile.close();
	system("PAUSE");
	return 0;
}
