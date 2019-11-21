#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<bits/stdc++.h>

char binary[32];
int index=0;
void print_bits(int number) {
	for(int i=31;i>=0;i--) {
		if(number & 1<<i) {
			binary[index] = '1';
			index++;
		}
		else {
			binary[index] = '0';
			index++;
		}
	}
	printf("\nThe Binary Number is: ");	
	for(int i=0;i<sizeof(binary)/sizeof(binary[0]);i++) {
		if(i==8 || i==16 || i==24) {
			printf(" ");
		}
		printf("%c",binary[i]);
	}
	printf("\n");
}

int function1(char str[]) {
	int count=0;
	for(int i=0;i<8;i++) {
		if(str[i] == '1') {
			count++;
		}
	}
	return count;
}

int function2(char secondByte[]) {
	char sequence[3];
	printf("\nEnter the sequence: ");
	scanf("%s", &sequence);
    int M = sizeof(sequence)/sizeof(sequence[0]); 
    int N = sizeof(secondByte)/sizeof(secondByte[0]); 
  
    for (int i=0;i<=N-M;i++) {
    	int j;
        for(j=0;j<M;j++) {
        	if(secondByte[i+j] != sequence[j]) {
        		break;
			}
		}
        if(j == M) {
        	return i;
		}       
    }
    return -1;
}

int main() {
	int number, result=0;
	char secondByte[9],a;
	printf("Enter the Integer: ");
	scanf("%d",&number);
	print_bits(number);
	
	for(int k=16,j=0;k<24;k++,j++) {
		a = binary[k];
		secondByte[j] = a;
	}
	
	result = function1(secondByte);
	printf("\n\nThe set bits(1) inside the second byte is: %d\n",result);
	result = function2(secondByte); 
    if(result == -1) 
        printf("\nAnswer: No"); 
    else
        printf("\nAnswer: Yes");
    
	return 0;
}
