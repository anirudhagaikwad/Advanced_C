/*
Write a program that uses an enum to represent the months of the year.
Print the name of each month and its corresponding value.
*/

#include <stdio.h>

// Enum representing the months of the year
enum Months {
    January = 1,
    February,
    March,
    April,
    May,
    June,
    July,
    August,
    September,
    October,
    November,
    December
};

int main() {
    enum Months currentMonth;

    for (currentMonth = January; currentMonth <= December; currentMonth++) {
        switch (currentMonth) {
            case January:
                printf("January: %d\n", currentMonth);
                break;
            case February:
                printf("February: %d\n", currentMonth);
                break;
            case March:
                printf("March: %d\n", currentMonth);
                break;
            case April:
                printf("April: %d\n", currentMonth);
                break;
            case May:
                printf("May: %d\n", currentMonth);
                break;
            case June:
                printf("June: %d\n", currentMonth);
                break;
            case July:
                printf("July: %d\n", currentMonth);
                break;
            case August:
                printf("August: %d\n", currentMonth);
                break;
            case September:
                printf("September: %d\n", currentMonth);
                break;
            case October:
                printf("October: %d\n", currentMonth);
                break;
            case November:
                printf("November: %d\n", currentMonth);
                break;
            case December:
                printf("December: %d\n", currentMonth);
                break;
        }
    }

    return 0;
}
/*
This program uses an enum to represent the months of the year. It assigns values to each month, starting from 1 for January.
The program then loops through the enum values and prints the name of each month along with its corresponding value.
*/
