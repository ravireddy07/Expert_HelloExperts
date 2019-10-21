#include<stdio.h>
#include<string.h>
#include<math.h>
#define MAX 12

int i,k=0, j, leng = 12;
double distance, pi = 3.14159265358979323846, radians = 6373;

struct Airport {
	char code[4];
	char name[27];
	double Latitude;
	double Longitude;
}airports[MAX], output[MAX];

struct temp {
	char tempCode[4];
	double tempLatitude;
	double tempLongitude;
}temps;

void fillAirports(struct Airport airports[]) {
	//1
	strcpy(airports[0].code, "SAT");
	strcpy(airports[0].name, "San Antonio Intl");
	airports[0].Latitude = 29.533958;
	airports[0].Longitude = -98.469056;
    //2
	strcpy(airports[1].code, "BKK");
	strcpy(airports[1].name, "Bangkok Suvarnabhumi");
	airports[1].Latitude = 13.681108;
	airports[1].Longitude = 100.747283;
	//3
	strcpy(airports[2].code, "CDG");
	strcpy(airports[2].name, "Paris Charles De Gaulle");
	airports[2].Latitude = 49.009722;
	airports[2].Longitude = 2.547780;
	//4
	strcpy(airports[3].code, "GTG");
	strcpy(airports[3].name, "Rio De Janeiro Gale�o");
	airports[3].Latitude = -22.809999;
	airports[3].Longitude = -43.250555;
	//5
	strcpy(airports[4].code, "HKG");
	strcpy(airports[4].name, "Hong Kong Intl");
	airports[4].Latitude = 22.308889;
	airports[4].Longitude = 113.914722;
	//6
	strcpy(airports[5].code, "JFK");
	strcpy(airports[5].name, "New York-JFK");
	airports[5].Latitude = 40.639926;
	airports[5].Longitude = -73.778694;
	//7
	strcpy(airports[6].code, "JNB");
	strcpy(airports[6].name, "O.R. Tambo Johannesburg");
	airports[6].Latitude = -26.133693;
	airports[6].Longitude = 28.242317;
	//8
	strcpy(airports[7].code, "LAX");
	strcpy(airports[7].name, "Los Angeles Intl");
	airports[7].Latitude = 33.942496;
	airports[7].Longitude = -118.408048;
	//9
	strcpy(airports[8].code, "LHR");
	strcpy(airports[8].name, "London Heathrow");
	airports[8].Latitude = 51.477500;
	airports[8].Longitude = -0.461388;
	//10
	strcpy(airports[9].code, "MEX");
	strcpy(airports[9].name, "Mexico City Benito Juarez");
	airports[9].Latitude = 19.436303;
	airports[9].Longitude = -99.072096;
	//11
	strcpy(airports[10].code, "SIN");
	strcpy(airports[10].name, "Singapore Changi");
	airports[10].Latitude = 1.359211;
	airports[10].Longitude = 103.989333;
	//12
	strcpy(airports[11].code, "NRT");
	strcpy(airports[11].name, "Tokyo Narita");
	airports[11].Latitude = 35.765556;
	airports[11].Longitude = 140.385556;

	return;
}

// C++ program for the haversine formula 
// C++ program for the 
// haversine formula 

double haversine(double latitude1, double longitude1, double latitude2, double longitude2) { 
		// Distance between Latitudes and Longitudes
		double pi = 3.14159265358979323846, radians = 6373;
		double distanceLatitude = (latitude2 - latitude1)*(pi/180.0); 
		double distanceLongitude = (longitude2 - longitude1)*(pi/180.0); 

		// Convert to Radians 
		latitude1 = (latitude1) * pi / 180.0; 
		latitude2 = (latitude2) * pi / 180.0; 

		// Haversine formulae 
		double a = (pow(sin(distanceLatitude/2),2) + pow(sin(distanceLongitude/2),2)*(cos(latitude1)*cos(latitude2)));
		double c = 2*asin(sqrt(a)); 
		return radians*c; 
} 

double calculateDistance(struct Airport airports[], int leng, char code1[4], char code2[4]) {
	printf("\n\n %s\t  %s\t\t\t   %lf       %lf\n", airports[0].code, airports[0].name, airports[0].Latitude, airports[0].Longitude);
	for(k=0;k<leng;k++) {
		if(strcmp(code1, airports[k].code) == 0) {
			printf("\n \t\t\tAirport Found");
		}
	}	
}

/*
for(j=0;j<12;j++) {
				if(strcmp(str2, airports[j].code) == 0) {
					printf("Hello\n");
					//distance = haversine(29.533958, -98.469056, 13.681108, 100.747283);
					//return distance;
				}
			}
			
*/
// Driver code 
int main() 
{ 
	double result;
	
	
	result = calculateDistance(airports, leng, "LHR", "LAX");; 
	printf("%lf", result);
	return 0; 
} 

// This code is contributed 
// by Mahadev. 
  
