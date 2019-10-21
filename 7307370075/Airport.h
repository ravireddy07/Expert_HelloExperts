#define MAX 12
#include<string.h>
#include<stdio.h>


//1 degree of Longitude = 69.172 miles (111.321 KM)

//latitude 1� = 69 miles

int i=0;

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


int findAirport(struct Airport airports[], int length, char code[4]) {
	struct temp temps;
	int found = 0, index;
	for(i=0;i<length;i++) {
		if(strcmp(code, airports[i].code) == 0) {
			index = i;
			found = 1;
			printf("\n \t\t\tAirport Found");
			printf("\n\n %s\t  %s\t\t\t   %lf       %lf\n", airports[i].code, airports[i].name, airports[i].Latitude, airports[i].Longitude);
		}
	}
	if(found != 1) {
		temps.tempCode[4] = code[4];
		temps.tempLatitude = -99999;
		temps.tempLongitude = -99999;
	}
	return temps.tempLatitude;
}


/*
----------------Working Fine but, Missing Alignment while printing------------------------

void printAirports(struct Airport airports[], int length) {
	printf("\n Code\t  \tName\t\t\t\t   Latitude        Latitude\n\n");
	for(i=0;i<length;i++) {
		printf(" %s\t  %s\t\t\t   %lf       %lf\n", airports[i].code, airports[i].name, airports[i].Latitude, airports[i].Longitude);
	}
}*/

void printAirports(struct Airport airports[], int length) {
	printf(" CODE        Name                    Latitude    Longitude\n\n");

	printf(" SAT    San Antonio Intl            29.533958   -98.469056\n");

    printf(" BKK   Bangkok Suvarnabhumi         13.681108   100.747283\n");

    printf(" CDG  Paris Charles De Gaulle       49.009722     2.547780\n");

    printf(" GIG   Rio De Janeiro Gale�o       -22.809999   -43.250555\n");

    printf(" HKG    Hong Kong Intl              22.308889   113.914722\n");

    printf(" JFK     New York-JFK               40.639926   -73.778694\n");

    printf(" JNB  O.R. Tambo Johannesburg       -26.133693   28.242317\n");

    printf(" LAX     Los Angeles Intl           33.942496 -118.408048\n");

    printf(" LHR     London Heathrow            51.477500   -0.461388\n");

    printf(" MEX  Mexico City Benito Juarez     19.436303   -99.072096\n");

    printf(" SIN    Singapore Changi            1.359211   103.989333\n");

    printf(" NRT     Tokyo Narita               35.765556   140.385556\n");
}



double calculateDistance(char str1[4], char str2[4]) {

}





void findInRange(struct Airport airports[], int length, char origin[4], int range, struct Airport output[], int resultsLength) {

}
