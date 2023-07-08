#include <stdio.h>

/* Develop a Bank Account Management System using an array of structures.
 Each bank account has an account number and a structure representing the balance,
 which consists of the amount in the account and the currency.
*/

// Structure definition for Balance
struct Balance {
    double amount;
    char currency[10];
};

// Structure definition for Bank Account
struct BankAccount {
    int accountNumber;
    struct Balance balance;
};

int main() {
    // Array of structures to store bank account data
    struct BankAccount accounts[2];

    // Inputting bank account information
    printf("Enter details for 2 bank accounts:\n");
    for (int i = 0; i < 2; i++) {
        printf("Bank Account %d:\n", i + 1);
        printf("Account Number: ");
        scanf("%d", &accounts[i].accountNumber);
        printf("Amount: ");
        scanf("%lf", &accounts[i].balance.amount);
        printf("Currency: ");
        scanf("%s", accounts[i].balance.currency);
        printf("\n");
    }

    // Displaying bank account information
    printf("Bank Account Details:\n");
    for (int i = 0; i < 2; i++) {
        printf("Account Number: %d\n", accounts[i].accountNumber);
        printf("Balance: %.2lf %s\n", accounts[i].balance.amount, accounts[i].balance.currency);
        printf("\n");
    }

    return 0;
}

/*
This program illustrates a Bank Account Management System using an array of structures.
Each bank account has an account number and a balance, represented by a nested structure.
The balance consists of the amount in the account and the currency.
The program allows the user to input details for 2 bank accounts and then displays the account information.
*/

