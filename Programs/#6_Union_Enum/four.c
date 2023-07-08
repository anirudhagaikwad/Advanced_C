/* Convert between different units of measurement using union.
The program can convert length between meters and feet, and weight between kilograms and pounds.
*/

#include <stdio.h>

// Union definition for Measurement
union Measurement {
    struct {
        float meters;
    } length;

    struct {
        float kilograms;
    } weight;
};

// Function to convert meters to feet
float convertMetersToFeet(float meters) {
    return meters * 3.28084;
}

// Function to convert feet to meters
float convertFeetToMeters(float feet) {
    return feet / 3.28084;
}

// Function to convert kilograms to pounds
float convertKilogramsToPounds(float kilograms) {
    return kilograms * 2.20462;
}

// Function to convert pounds to kilograms
float convertPoundsToKilograms(float pounds) {
    return pounds / 2.20462;
}

int main() {
    // Creating a measurement union
    union Measurement measurement;

    // Converting length from meters to feet
    measurement.length.meters = 5;
    float lengthInFeet = convertMetersToFeet(measurement.length.meters);

    // Converting length from feet to meters
    float lengthInMeters = convertFeetToMeters(lengthInFeet);

    // Converting weight from kilograms to pounds
    measurement.weight.kilograms = 10;
    float weightInPounds = convertKilogramsToPounds(measurement.weight.kilograms);

    // Converting weight from pounds to kilograms
    float weightInKilograms = convertPoundsToKilograms(weightInPounds);

    // Displaying the results
    printf("Length:\n");
    printf("%.2f meters = %.2f feet\n", measurement.length.meters, lengthInFeet);
    printf("%.2f feet = %.2f meters\n", lengthInFeet, lengthInMeters);

    printf("\nWeight:\n");
    printf("%.2f kilograms = %.2f pounds\n", measurement.weight.kilograms, weightInPounds);
    printf("%.2f pounds = %.2f kilograms\n", weightInPounds, weightInKilograms);

    return 0;
}
/*
This program uses a union to convert between different units of measurement, specifically length between meters and feet,
and weight between kilograms and pounds. The union Measurement contains nested structures for length and weight.
The program converts length from meters to feet and vice versa, as well as weight from kilograms to pounds and vice versa.
The results are displayed accordingly.
*/
