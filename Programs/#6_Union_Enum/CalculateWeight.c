/* using an enum to calculate a person's weight on different planets */
#include <stdio.h>

enum Planet {
    Earth,
    Mercury,
    Venus,
    Mars,
    Jupiter,
    Saturn,
    Uranus,
    Neptune
};

double calculateWeight(double earthWeight, enum Planet planet) {
    double relativeGravity[] = {
        1.0,      // Earth
        0.38,     // Mercury
        0.91,     // Venus
        0.38,     // Mars
        2.34,     // Jupiter
        0.93,     // Saturn
        0.89,     // Uranus
        1.13      // Neptune
    };

    return earthWeight * relativeGravity[planet];
}

int main() {
    double earthWeight;
    enum Planet planet;

    printf("Enter your weight on Earth (in kg): ");
    scanf("%lf", &earthWeight);

    printf("Select a planet:\n");
    printf("0. Earth\n1. Mercury\n2. Venus\n3. Mars\n4. Jupiter\n");
    printf("5. Saturn\n6. Uranus\n7. Neptune\n");
    printf("Enter the planet number: ");
    
    int planetNumber;
    scanf("%d", &planetNumber);
    planet = (enum Planet)planetNumber;

    double weightOnPlanet = calculateWeight(earthWeight, planet);
    printf("Your weight on the selected planet is: %.2lf kg\n", weightOnPlanet);

    return 0;
}


/*
In this example, the enum Planet defines constants for various planets. The function calculateWeight takes a person's weight on Earth and the chosen planet as parameters, and it calculates and returns the weight on the specified planet based on relative gravity values.

You can select a planet by entering its number, and the program will calculate and display your weight on that planet. Please note that the actual calculations are approximate and based on relative gravity values, not considering other factors like atmosphere or other variations.
*/
