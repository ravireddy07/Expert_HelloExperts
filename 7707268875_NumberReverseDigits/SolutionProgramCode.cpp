#include<stdio.h>
#include<bits/stdc++.h>

int main() {
  int temp, counter=0, n,ar[100]; //Array is used to store the single digits of given number
  
  printf("Enter a Positive Number: ");
  scanf("%d",&n);
  if(n<0) {
    printf("\nThe given number is not +ve Integer.");  //Taking Input
    return 0;
  }
  else {
    while(n!=0) {
      temp = n%10;
      ar[counter] = temp;
      n /= 10;
      counter++; //counter is used for index and size of the array
    }
  }
  
   //Printing the Output
   if(counter == 0) {  //counter = 0, means array is empty
   	return 0;
   }
   else {
   	printf("\nNumbers are : ");
    for(int j=0;j<counter;j++) {
    	printf("%d ",ar[j]);
    }
   }
  return 0;
}
