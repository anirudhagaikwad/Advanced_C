/*
Given n non-negative integers representing an elevation map where the width of each bar is 1,
compute how much water it can trap after raining.

Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6

Input: height = [4,2,0,3,2,5]
Output: 9

*/
#include <stdio.h>

int trap(int* height, int heightSize){
    int rain = 0;       // Variable to store the total amount of trapped rainwater
    int highest;        // Variable to store the index of the highest point in the array
    int high, ground, next;

    // Loop through the array from left to right
    for (int i = 0; i < heightSize; i++){
        high = height[i];       // Current height
        ground = 0;             // Variable to store the sum of the heights of the lower points
        next = i + 1;

        // Calculate the sum of the heights of the lower points until a higher or equal point is found
        while (next < heightSize && high > height[next]){
            ground += height[next];
            next++;
        }

        // If a higher or equal point is found, calculate the trapped rainwater
        if (next < heightSize){
            next--;
            if (next > i){
                rain += high * (next - i) - ground;
                i = next;
            }
        } else {
            highest = i;
            break;
        }
    }

    // Loop through the array from right to the highest point
    for (int i = heightSize - 1; i > highest; i--){
        high = height[i];       // Current height
        ground = 0;             // Variable to store the sum of the heights of the lower points
        next = i - 1;

        // Calculate the sum of the heights of the lower points until a higher point is found
        while (high > height[next]){
            ground += height[next];
            next--;
        }
        next++;

        // Calculate the trapped rainwater
        if (i > next){
            rain += high * (i - next) - ground;
            i = next;
        }
    }

    return rain;        // Return the total amount of trapped rainwater
}

int main(){
    int array[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    int size = sizeof(array) / sizeof(array[0]);
    int result = trap(array, size);

    printf("Rainwater trapped units: %d", result);

    return 0;
}
