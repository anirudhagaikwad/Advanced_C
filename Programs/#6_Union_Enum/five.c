/* Perform currency conversion using union to represent different currencies.
 The program can convert between USD, EUR, and GBP currencies.
*/

#include <stdio.h>

// Union definition for Currency
union Currency {
    float usd;
    float eur;
    float gbp;
};

// Function to convert USD to EUR
float convertUSDtoEUR(float usd) {
    return usd * 0.85;
}

// Function to convert EUR to USD
float convertEURtoUSD(float eur) {
    return eur * 1.18;
}

// Function to convert USD to GBP
float convertUSDtoGBP(float usd) {
    return usd * 0.73;
}

// Function to convert GBP to USD
float convertGBPtoUSD(float gbp) {
    return gbp * 1.37;
}

int main() {
    // Creating a currency union
    union Currency currency;

    // Converting USD to EUR
    currency.usd = 100;
    float eur = convertUSDtoEUR(currency.usd);

    // Converting EUR to USD
    float usd = convertEURtoUSD(eur);

    // Converting USD to GBP
    float gbp = convertUSDtoGBP(currency.usd);

    // Converting GBP to USD
    usd = convertGBPtoUSD(gbp);

    // Displaying the results
    printf("USD: %.2f\n", currency.usd);
    printf("EUR: %.2f\n", eur);
    printf("GBP: %.2f\n", gbp);
    printf("USD: %.2f\n", usd);

    return 0;
}
/*

This program demonstrates the use of a union to perform currency conversion between USD, EUR, and GBP. The union Currency can hold
values for each currency.
The program converts USD to EUR and vice versa, as well as USD to GBP and vice versa. The results are displayed accordingly.
*/
