#include "Airport.c"
#define MAX 100

//---------------------Data----------------------------
/*
CODE Name                       Latitude    Longitude

SAT San Antonio Intl            29.533958   -98.469056

BKK Bangkok Suvarnabhumi        13.681108   100.747283

CDG Paris Charles De Gaulle     49.009722     2.547780

GIG Rio De Janeiro Galeão     -22.809999   -43.250555

HKG Hong Kong Intl              22.308889   113.914722

JFK New York-JFK                40.639926   -73.778694

JNB O.R. Tambo Johannesburg    -26.133693   28.242317

LAX Los Angeles Intl            33.942496 -118.408048

LHR London Heathrow             51.477500   -0.461388

MEX Mexico City Benito Juarez   19.436303   -99.072096

SIN Singapore Changi             1.359211   103.989333

NRT Tokyo Narita                35.765556   140.385556

*/

//1 degree of Longitude = 69.172 miles (111.321 KM)

//latitude 1° = 69 miles


//------------------------------Function Declaration----------------------------------

void printMenu();

void fillAirports(Airport airports[MAX]);   //int fillAirports(Airport airports[MAX])

findAirport(Airport airports[MAX], int length, char code[4]); //Airport findAirport(Airport airports[MAX], int length, char code[4]) 

void printAirports((Airport airports[MAX], int length);  //void printAirports(Airport airports[MAX], int length)

void printAirport(Airport airport); //void printAirport(Airport airport)

double calculateDistance(Airport airport1, Airport airport2);  //double calculateDistance(Airport airport1, Airport airport2)

void findInRange(Airport airports[MAX], int length, Airport origin, int range, Airport output[MAX], int *resultsLength);   //void findInRange(Airport airports[MAX], int length, Airport origin, int range, Airport output[MAX], int *resultsLength)


//------------------------------Function Initialization-------------------------------

void printMenu() {

}


void fillAirports(Airport airports[MAX]) {

}

findAirport(ThreeLetterWord_1) {

}

printAirports() {

}

printAirport() {

}

calculateDistance() {

}

findInRange() {

}
