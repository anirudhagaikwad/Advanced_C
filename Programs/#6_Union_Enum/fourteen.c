/*
Write a program that uses an enum to represent grades (A, B, C, D, F).
Prompt the user to enter a grade and display a message based on the grade entered.
*/
#include <stdio.h>

// Enum representing grades
enum Grade {
    A,
    B,
    C,
    D,
    F
};

int main() {
    enum Grade userGrade;

    printf("Enter your grade (A, B, C, D, F): ");
    char grade;
    scanf(" %c", &grade);

    switch (grade) {
        case 'A':
            userGrade = A;
            printf("Excellent!\n");
            break;
        case 'B':
            userGrade = B;
            printf("Good job!\n");
            break;
        case 'C':
            userGrade = C;
            printf("Well done.\n");
            break;
        case 'D':
            userGrade = D;
            printf("You passed.\n");
            break;
        case 'F':
            userGrade = F;
            printf("You failed.\n");
            break;
        default:
            printf("Invalid grade.\n");
            return 1;
    }

    return 0;
}
/*
This program uses an enum to represent grades.
It prompts the user to enter a grade and displays a corresponding message based on the grade entered.
The program uses a switch statement to determine the grade and prints an appropriate message.
*/
