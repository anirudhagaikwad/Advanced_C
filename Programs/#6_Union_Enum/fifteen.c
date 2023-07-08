/*
Write a program that uses an enum to represent the cardinal directions (North, South, East, West).
Prompt the user to enter a direction and display a message based on the direction entered.
*/

#include <stdio.h>

// Enum representing cardinal directions
enum Direction {
    North,
    South,
    East,
    West
};

int main() {
    enum Direction userDirection;

    printf("Enter a direction (N, S, E, W): ");
    char direction;
    scanf(" %c", &direction);

    switch (direction) {
        case 'N':
            userDirection = North;
            printf("Heading North.\n");
            break;
        case 'S':
            userDirection = South;
            printf("Heading South.\n");
            break;
        case 'E':
            userDirection = East;
            printf("Heading East.\n");
            break;
        case 'W':
            userDirection = West;
            printf("Heading West.\n");
            break;
        default:
            printf("Invalid direction.\n");
            return 1;
    }

    return 0;
}
/*
This program uses an enum to represent the cardinal directions.
It prompts the user to enter a direction (N, S, E, W) and displays a message based on the direction entered.
The program uses a switch statement to determine the direction and prints an appropriate message.
*/
