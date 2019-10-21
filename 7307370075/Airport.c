#include<stdio.h>
#include<string.h>
#include<math.h>
#include "Airport.h"


int main(int argc, char *argv[]) {

    struct Airport airports[MAX];
    int choice, length=12, status_1, status_2, resultsLength=0;
    double rangeDistance;
    char getCode_1[4], getCode_2[4];
		fillAirports(airports);


    do {
			printMenu();

			scanf("%d", &choice);

			switch(choice) {
				case 1: {
					printf("\nEnter the Airport Code to find: ");
					scanf("%s", getCode_1);

					status_1 = findAirport(airports, length, getCode_1);

					if(status_1 == -99999) {
						printf(" CODE        Name                    Latitude    Longitude\n\n");
						printf(" %s           -                       %lf        %lf", getCode_1, &temps.tempLatitude, &temps.tempLongitude);
						printf("\n \t\t\tAirport Not Found\n");
					}
					break;
				}
			  case 2: {
					printAirports(airports, length);
					break;
				}
				case 3: {
					printf("\nEnter the Two(2) Airport Codes to find: ");
					scanf("%s %s", getCode_1, getCode_2);

					status_1 = findAirport(airports, length, getCode_1);
					status_2 = findAirport(airports, length, getCode_2);

					//3. If either airport's latitude or longitude is -99999, that means that airport was not found. Print an appropriate error.
					if(status_1 || status_2 == -99999) {
						printf("\n \t\t\tAirport Not Found\n");
					}
					else if(status_1 == -99999 && status_2 != -99999) {
						printf("Airport %s is not found, But Airport %s is found. Please check Again...!", getCode_1, getCode_2);
					}
					else if(status_1 != -99999 && status_2 == -99999) {
						printf("Airport %s is not found, But Airport %s is found. Please check Again...!", getCode_2, getCode_1);
					}
					else {
						calculateDistance(getCode_1, getCode_2);
					}
					break;
				}
				case 4: {
					printf("\nEnter the Airport Code to find: ");
					scanf("%s", getCode_1);

					status_1 = findAirport(airports, length, getCode_1);

					if(status_1 == -99999) {
						printf(" CODE        Name                    Latitude    Longitude\n\n");
						printf(" %s           -                       %lf        %lf", getCode_1, &temps.tempLatitude, &temps.tempLongitude);
						printf("\n \t\t\tAirport Not Found\n");
					}
					else {
						printf("\n Enter the range to find nearby Airports: ");
						scanf("%lf", &rangeDistance);

						findInRange(airports, length, getCode_1, rangeDistance, output, resultsLength);

						if(resultsLength == 0) {
							printf("\n \t\t\tNo Airports Found\n");
						}
						else {
							printf("\n There are %d Airports in given range.\n", resultsLength);
						}
					}

					break;
				}
				case 0: {
					printf("\n\t\t\t\t   Good-bye!\n");
					break;
				}
			}
		} while (choice != 0);

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
