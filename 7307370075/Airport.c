#include<stdio.h>
#include<string.h>
#include<math.h>
#include "Airport.h"             //Loading airport.h header file
#define KM_mile 1.60893707538269        //Difference between Kilometer and Mile

int main(int argc, char *argv[]) {

    struct Airport airports[MAX];
    struct Output output[132];  //Output of distances between two airports. 132 is the maximum combination.
    int choice, length=12,ll, status_1, status_2, resultsLength=0;
    double rangeDistance, resultDistance;
    char getCode_1[4], getCode_2[4];  //Taking input of Airport codes. Not more than 3 letters
		fillAirports(airports);  //Inserting Data


    do {
			printMenu();

			scanf("%d", &choice);

			switch(choice) {
				case 1: {
					printf("\nEnter the Airport Code to find: ");
					scanf("%s", getCode_1);

					status_1 = findAirport(airports, length, getCode_1); //storing the output of findAirport() in status_1 to print appropriate Message.

					if(status_1 == -99999) {
						printf(" CODE        Name                    Latitude    Longitude\n\n");
						printf(" %s           -                       %lf        %lf", getCode_1, &temps.tempLatitude, &temps.tempLongitude);
						printf("\n \t\t\tAirport Not Found. Check the code and try again.\n");
					}
					break;
				}

			  case 2: {
					printAirports(airports, length);
					break;
				}

				case 3: {
					printf("\nEnter the First Airport Code: ");
					scanf("%s", getCode_1);
					status_1 = findAirport(airports, length, getCode_1); //storing the output of findAirport() in status_1 to print appropriate Message.

					printf("\nEnter the Second Airport Code to find: ");
					scanf("%s", getCode_2);
					status_2 = findAirport(airports, length, getCode_2); //storing the output of findAirport() in status_2 to print appropriate Message.

					if(status_1 || status_2 == -99999) {
						printf("\n \t\t\tAirport Not Found. Check the code and try again.\n");
					}
					else if(status_1 == -99999 && status_2 != -99999) {
						printf("Airport %s is not found, But Airport %s is found. Please check Again...!", getCode_1, getCode_2);
					}
					else if(status_1 != -99999 && status_2 == -99999) {
						printf("Airport %s is not found, But Airport %s is found. Please check Again...!", getCode_2, getCode_1);
					}
					else {
						resultDistance = calculateDistance(airports, getCode_1, getCode_2);
            // Showing or Printing the output of calculateDistance() in Miles and Kilometers
						printf("\nThe Distance Between two Airports is: %lf miles and %lf KM.\n", resultDistance, resultDistance*KM_mile);
					}
					break;
				}

				case 4: {
					printf("\nEnter the Airport Code to find: ");
					scanf("%s", getCode_1);

					status_1 = findAirport(airports, length, getCode_1); //storing the output of findAirport() in status_1 to print appropriate Message.

					if(status_1 == -99999) {
						printf(" CODE        Name                    Latitude    Longitude\n\n");
						printf(" %s           -                       %lf        %lf", getCode_1, &temps.tempLatitude, &temps.tempLongitude);
						printf("\n \t\t\tAirport Not Found\n");
					}
					else {
						printf("\n Enter the range to find nearby Airports: ");
						scanf("%lf", &rangeDistance); //Entering the range

            //findInRange() function will return the number of airports in given range
            //resultsLength will have the count of Airports are in given range.
						resultsLength = findInRange(airports, length, getCode_1, rangeDistance, output, resultsLength);

						if(resultsLength == 0) {
							printf("\n \t\t\tNo Airports Found.\n");
						}
						else {
							printf("\n There are %d Airports in given range.\n", resultsLength);  //printing the number of airports in range
						}
					}
					break;
				}

				case 0: {
					printf("\n\t\t\t\t   Good-bye!\n");
					break;
				}
			}
		} while (choice != 0); //it will run again and again until choice=0
                           //Advantage of this, we don't have to comile again and again for checking multiple options
		return 0;
}


void printMenu() {

	printf("\n\n\n\t\t\t\t   #########################################\n");

	printf("\t\t\t\t\t   Airport Program Menu\n");

	printf("\t\t\t\t   #########################################\n");

	printf("\t\t\t\t\t   1 - Get Airport Information\n");

	printf("\t\t\t\t\t   2 - Get Airport Listing\n");

	printf("\t\t\t\t\t   3 - Get Distance Between Two Airports\n");

	printf("\t\t\t\t\t   4 - Find Airports Within Range\n");

	printf("\t\t\t\t\t   0 - Quit\n\n");

	printf("\t\t\t\t   Enter your selection: ");
}
