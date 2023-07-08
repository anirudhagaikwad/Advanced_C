/* Create a Contact Management System using an array of structures.
 Each contact has a name and a structure representing their phone number,
 which consists of the country code, area code, and number.
*/

#include <stdio.h>

// Structure definition for Phone Number
struct PhoneNumber {
    int countryCode;
    int areaCode;
    long long int number;
};

// Structure definition for Contact
struct Contact {
    char name[50];
    struct PhoneNumber phoneNumber;
};

int main() {
    // Array of structures to store contact data
    struct Contact contacts[5];

    // Inputting contact information
    printf("Enter details for 5 contacts:\n");
    for (int i = 0; i < 5; i++) {
        printf("Contact %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", contacts[i].name);
        printf("Country Code: ");
        scanf("%d", &contacts[i].phoneNumber.countryCode);
        printf("Area Code: ");
        scanf("%d", &contacts[i].phoneNumber.areaCode);
        printf("Number: ");
        scanf("%lld", &contacts[i].phoneNumber.number);
        printf("\n");
    }

    // Displaying contact information
    printf("Contact Details:\n");
    for (int i = 0; i < 5; i++) {
        printf("Name: %s\n", contacts[i].name);
        printf("Phone Number: +%d (%d) %lld\n", contacts[i].phoneNumber.countryCode,
               contacts[i].phoneNumber.areaCode, contacts[i].phoneNumber.number);
        printf("\n");
    }

    return 0;
}

/*
This program implements a Contact Management System using an array of structures.
Each contact has a name and a phone number, represented by a nested structure.
The phone number consists of a country code, area code, and the actual number.
The program allows the user to input details for 5 contacts and then displays the contact information.
*/
