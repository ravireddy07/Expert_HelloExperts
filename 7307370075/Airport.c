#include<stdio.h>
#include<string.h>
#include<math.h>
#include "Airport.h"

/*
####   To do   ####
1-- Put Printf before taking input from user by telling what type of input has to give....
2-- 
*/

int main(int argc, char *argv[]) {
    //Airport airports[MAX];
    int choice;
    //string ThreeLetterWord_1, ThreeLetterWord_2;  // Restrict to size 3
    //fillAirports(airports);

    do {
        /* Call the function to print the menu */
        printMenu();

        /* Get the menu choice from the user */
        scanf("%d", &choice);

        switch(choice) {
            case 1:  {
                /* 1. Get a 3-letter airport code from the user.*/
                //scanf("%s", &ThreeLetterWord_1);

                //2. Call findAirport()
                //findAirport(ThreeLetterWord_1);

                //3. If either the airport's latitude or longitude is -99999, that means the airport was not found. Print an appropriate error.
                if() {

                }
                else {

                }
                //4. If airport found, print the airport information.

                printf("");

                break;
            }
            case 2: {
                /*                    Call the printAirports() function.*/
                //printAirports();
                break;
            }
            case 3: {
                /* 1. Get two 3-letter airport codes from the user. */
                //scanf("%s %s", &ThreeLetterWord_1, &ThreeLetterWord_2);


                //2. Call findAirport() twice (one each for each of the airport codes entered).
                //findAirport(ThreeLetterWord_1);
                //findAirport(ThreeLetterWord_2);

                //3. If either airport's latitude or longitude is -99999, that means that airport was not found. Print an appropriate error.
                if() {

                }
                else {

                }
                //4. If both airports found successfully, call the calculateDistance() function.
                //calculateDistance();

                //5. Print out the distance between the two airports. */
                printf("");


                break;
            }
            case 4: {
                /* 1. Get a 3-letter airport code from the user.*/
                //scanf("%s", &ThreeLetterWord);

                //2. Call findAirport() on this origin airport code.
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
                printf("");

                break;
            }
            case 0: {
                printf("Good-bye!\n");
                break;
            }
        }
    } while (choice != 0);
    
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
