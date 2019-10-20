#include<stdio.h>
#include<string.h>
#include<math.h>
#include "Airport.h"


int main(int argc, char *argv[]) {
	
    struct Airport airports[MAX];
    int choice, length=12, status_1,status_2;
    char getCode_1[4], getCode_2[4];
	fillAirports(airports);
	

    do {
        /* Call the function to print the menu */
        printMenu();

        /* Get the menu choice from the user */
        scanf("%d", &choice);

        switch(choice) {
            case 1:  {
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
                //1. Get two 3-letter airport codes from the user. 
                printf("\nEnter the Two(2) Airport Codes to find: ");
                scanf("%s %s", getCode_1, getCode_2);


                //2. Call findAirport(Airport airports[MAX], int length, char code[4]) twice (one each for each of the airport codes entered).
                status_1 = findAirport(airports, length, getCode_1);
                status_2 = findAirport(airports, length, getCode_2);

                //3. If either airport's latitude or longitude is -99999, that means that airport was not found. Print an appropriate error.
                if() {

                }
                else {

                }
                //4. If both airports found successfully, call the calculateDistance() function.
                //calculateDistance();

                //5. Print out the distance between the two airports. 

                break;
            }
            case 4: {
                /* 1. Get a 3-letter airport code from the user.
                //scanf("%s", &ThreeLetterWord);

                //2. Call findAirport(Airport airports[MAX], int length, char code[4]) on this origin airport code.
                //findAirport(ThreeLetterWord);

                //3. If the airport's latitude or longitude is -99999, that means the airport was not found. Print an appropriate error.
                if() {

                }
                else {

                }

                //4. If airport found successfully, get a range in miles (integer) from the user.
                //calculateDistance(); //Print Miles(Integer)

                //5. Call findInRange() to get an array of Airports within the specified range of the origin airport.
                //findInRange();

                //6. Print the return array of airports in range. If the result length returned is zero, print a message that no airports were found.*/
                printf("4");

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
