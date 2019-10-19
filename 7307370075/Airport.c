#include<stdio.h>
#include<string.h>
#include<math.h>
#include "Airport.h"


int main(int argc, char *argv[]) {
    Airport airports[MAX];
    int choice;
    //fillAirports(airports);

    while(1) {
        /* Call the function to print the menu */
        printMenu();

        /* Get the menu choice from the user */
        scanf("%d", &choice);

        switch(choice) {
            case 1:  {
                /* 1. Get a 3-letter airport code from the user.

                2. Call findAirport()

                3. If either the airport's latitude or longitude is -99999, that means the airport was not found. Print an appropriate error.

                4. If airport found, print the airport information.*/

                break;
            }
            case 2: {
                /*                    Call the printAirports() function.*/
                break;
            }
            case 3: {
                /* 1. Get two 3-letter airport codes from the user.

                   2. Call findAirport() twice (one each for each of the airport codes entered).

                   3. If either airport's latitude or longitude is -99999, that means that airport was not found. Print an appropriate error.

                   4. If both airports found successfully, call the calculateDistance() function.

                   5. Print out the distance between the two airports. */

                   break;
            }
            case 4: {
                /* 1. Get a 3-letter airport code from the user.

                2. Call findAirport() on this origin airport code.

                3. If the airport's latitude or longitude is -99999, that means the airport was not found. Print an appropriate error.

                4. If airport found successfully, get a range in miles (integer) from the user.

                5. Call findInRange() to get an array of Airports within the specified range of the origin airport.

                6. Print the return array of airports in range. If the result length returned is zero, print a message that no airports were found.*/

                break;
            }
            case 0: {
                default: {
                    printf("Good-bye!\n");
                    return 0;
                }
            }
        }
    }
    return 0;
}


void printMenu() {
    printf("\n#########################################\n");

    printf("\tAirport Program Menu\n");

    printf("#########################################\n");

    printf("\t1 - Get Airport Information\n");

    printf("\t2 - Get Airport Listing\n");

    printf("\t3 - Get Distance Between Two Airports\n");

    printf("\t4 - Find Airports Within Range\n");

    printf("\t0 - Quit\n");

    printf("Enter your selection: ");
}
