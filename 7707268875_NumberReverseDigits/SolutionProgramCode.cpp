#include<stdio.h>
#include<bits/stdc++.h>

void main() {
  int temp, counter=0, n,ar[100];
  printf("Enter a Positive Number: ");
  scanf("%d",&n);
  if(n<0) {
    printf("\nThe given number is not +ve Integer.");
    return;
  }
  else {
    while(n!=0) {
      temp = num%10;
      ar[counter] = temp;
      num /= 10;
      counter++;
    }
  }

  //Printing the Output
  printf("\nNumbers are : ");
  for(int j=0;j<counter;j++) {
    printf("%d ",ar[j]);
  }
  return;
}
