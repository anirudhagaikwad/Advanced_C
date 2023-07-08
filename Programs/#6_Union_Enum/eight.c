/* Convert between different units of measurement using a union.
 The program can convert temperature between Celsius and Fahrenheit.
*/

#include <stdio.h>

// Union definition for Temperature
union Temperature {
    float celsius;
    float fahrenheit;
};

// Function to convert Celsius to Fahrenheit
float convertCelsiusToFahrenheit(float celsius) {
    return (celsius * 9 / 5) + 32;
}

// Function to convert Fahrenheit to Celsius
float convertFahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

int main() {
    // Creating a temperature union
    union Temperature temperature;

    // Converting Celsius to Fahrenheit
    temperature.celsius = 25;
    float fahrenheit = convertCelsiusToFahrenheit(temperature.celsius);

    // Converting Fahrenheit to Celsius
    float celsius = convertFahrenheitToCelsius(fahrenheit);

    // Displaying the results
    printf("Celsius: %.2f\n", temperature.celsius);
    printf("Fahrenheit: %.2f\n", fahrenheit);
    printf("Celsius: %.2f\n", celsius);

    return 0;
}

/*
This program utilizes a union to convert temperature between Celsius and Fahrenheit.
The union Temperature can store values for both Celsius and Fahrenheit.
The program converts Celsius to Fahrenheit and vice versa using conversion functions.
The results are displayed accordingly.
*/
