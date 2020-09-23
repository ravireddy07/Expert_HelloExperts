#include<stdio.h>
#include<conio.h>
#include <ctype.h>
#include <string.h>

//items declaring
const char *items[7];

//Fixing prices
int prices[7] = {30, 40, 25, 35, 50, 45, 20};

int i,products = 0, quantity, total = 0;
float totaltaxed = 0;
int selected[7], quantities[7];

void menu()
{
	printf("\n\t===== MENU =====\n");
	
	//items defining
	items[0] = "Sandwich";
	items[1] = "Burger";
	items[2] = "Fruit Cake";
	items[3] = "Chocolate Ice Cream";
	items[4] = "Apple Pie";
	items[5] = "Vanilla Cupcake";
	items[6] = "Donut";
		
}

void displayMenu(){
	printf("\n%-4s\t%-22s\t%s\n", "S.no", "Item", "Price");
	for(i = 0; i<7; i++){
		printf("\n%-3d\t%-22s\t%d", i+1, items[i], prices[i]);
	}
}

void selection(){
	printf("\n\nPlease select products to buy. (Enter -1 to finsh selection items.)\n");
	
	int choice = 0;
	while(choice != -1){
		scanf("%d", &choice);
			if(choice == -1){
				break;
			}
			else if(choice > 0 && choice < 8){
				selected[products++] = (choice - 1);
			}
			else{
				printf("\nPlease enter a valid number\n");
			}
	}
	
	for(i = 0; i<products; i++)
	{
		printf("\nEnter the quantity of %s: ", items[selected[i]]);
		scanf("%d", &quantity);
		quantities[i] = quantity;
	}
}

void calculation()
{
	printf("\n\n\t===== BILL =====\n");
	printf("\n%-10s\t%-22s\t%s\n", "Quantity", "Item", "Total Price");
	
	for(i = 0; i<products; i++){
		printf("\n%-10d\t%-22s\t%d", quantities[i], items[i], quantities[i]*prices[selected[i]]);
		total += quantities[i]*prices[selected[i]];
	}
	
	float gst = 0.09*total;
	printf("\n\nCGST (9%): %f", gst);
	printf("\nSGST (9%): %f", gst);
	
	totaltaxed = total + (2*gst);
	
	printf("\n\nTOTAL: %.2f", totaltaxed);
}

int main()
{
	
	menu();
	displayMenu();
	selection();
	calculation();
	

	getch();
}
