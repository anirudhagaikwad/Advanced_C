/*
    Government officer wants to manage census data of the each year. Help them to store and display data of cencus
    which should include year, population and literacy rate.

    Example:
    Enter year: 2023
    Enter population: 250000000
    Enter literacy rate: 87

    Census Data
    Year: 2023
    Population: 250000000
    Literacy Rate: 87.00

*/

#include <stdio.h>
#include <string.h>

// Structure to store census data
struct CensusData {
    int year;
    int population;
    float literacyRate;
};

int main() {
    struct CensusData census; // Declare a variable of type 'struct CensusData'

    // Prompt the user to enter census data
    printf("Enter year: ");
    scanf("%d", &census.year);

    printf("Enter population: ");
    scanf("%d", &census.population);

    printf("Enter literacy rate: ");
    scanf("%f", &census.literacyRate);

    // Display the entered census data
    printf("\nCensus Data\n");
    printf("Year: %d\n", census.year);
    printf("Population: %d\n", census.population);
    printf("Literacy Rate: %.2f\n", census.literacyRate);

    return 0;
}

/*
In the program above, the structure CensusData is used to store census data, including the year, population, and literacy rate.
The user is prompted to enter the census data, which is then stored in the structure variable census. Finally, the entered census data
is displayed on the console.

This program can be used to store and manage census data for a specific year, allowing for easy retrieval and analysis of the
population and literacy rate for that year.

*/
