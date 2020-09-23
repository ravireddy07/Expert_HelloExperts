#include <stdio.h>
char letter_grade(int points);

char letter_grade(int points) {
    char gradep;
    if(points >=90 && points <=100) {
        gradep = 'A';
        printf("You're Topper. You got A Grade.");
    }
    else if(points > 81 && points < 90) {
        gradep = 'B';
        printf("You achieved B Grade, Just missed the A Grade.");
    }
    else if(points > 65 && points < 81) {
        gradep = 'C';
        printf("You got C Grade, Just missed the B Grade.");
    }
    else if(points >=50 && points < 65) {
        gradep = 'D';
        printf("Oops, That's Close, You got D Grade.");
    }
    else {
        gradep = 'E';
        printf("Oops, You Failed. Better luck Next time.");
    }
    return gradep;
}

int main() {
    int points =80;
    char output = letter_grade(points);
    printf("\nYou got %c Grade.", output);
    return 0;
}
