/*
Write a program that simulates a traffic light using an enum.
The program should print the color of the traffic light and wait for a specified duration before changing to the next color.
*/

#include <stdio.h>
#include<windows.h> //header file required to use Sleep() method

// Enum representing the colors of a traffic light
enum TrafficLight {
    Red,
    Yellow,
    Green
};

int main() {
    enum TrafficLight currentColor;
    int i=0;
    while (i<10) {
        // Red
        currentColor = Red;
        printf("Traffic light: Red\n");
        Sleep(20);

        // Yellow
        currentColor = Yellow;
        printf("Traffic light: Yellow\n");
        Sleep(22);

        // Green
        currentColor = Green;
        printf("Traffic light: Green\n");
        Sleep(23);
        i++;
    }

    return 0;
}
/*
This program uses an enum to represent the colors of a traffic light.
It simulates a traffic light by printing the color and waiting for a specified duration before changing to the next color.
The program continues to loop indefinitely, simulating a traffic light's changing colors.
*/
