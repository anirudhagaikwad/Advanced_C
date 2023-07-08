/*
Write a program that uses an enum to represent the days of the week. Print the name of each day and its corresponding value.
*/
#include <stdio.h>

// Enum representing the days of the week
enum Days {
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday
};

int main() {
    enum Days currentDay;

    for (currentDay = Monday; currentDay <= Sunday; currentDay++) {
        switch (currentDay) {
            case Monday:
                printf("Monday: %d\n", currentDay);
                break;
            case Tuesday:
                printf("Tuesday: %d\n", currentDay);
                break;
            case Wednesday:
                printf("Wednesday: %d\n", currentDay);
                break;
            case Thursday:
                printf("Thursday: %d\n", currentDay);
                break;
            case Friday:
                printf("Friday: %d\n", currentDay);
                break;
            case Saturday:
                printf("Saturday: %d\n", currentDay);
                break;
            case Sunday:
                printf("Sunday: %d\n", currentDay);
                break;
        }
    }

    return 0;
}
/*
This program demonstrates the usage of an enum to represent the days of the week. It defines an enum type "Days" and
assigns integer values to each day. The program then iterates over the enum values and uses a switch statement to print the name of
each day along with its corresponding value.
*/
