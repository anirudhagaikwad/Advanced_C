/*
Write a program that aims to create a simple bank account management system.
It uses a structure called BankAccount to store the account number, account holder's name, and account balance.
The user is prompted to enter the account details, including the account number, account holder's name, and account balance.
The program then displays the entered information, providing an overview of the account details.

Example:

Enter account number: 9831300392343
Enter account holder name: Rajiv Gandhi
Enter account balance: 9897021

Account Details
Account Number: 9831300392343
Account Holder Name: Rajiv Gandhi
Balance: 9897021.00

*/
#include <stdio.h>
#include <string.h>

// Structure to store bank account details
struct BankAccount {
    char accountNumber[20];
    char accountHolderName[50];
    float balance;
};

int main() {
    struct BankAccount account;

    // Prompting the user to enter the account number
    printf("Enter account number: ");
    fgets(account.accountNumber, sizeof(account.accountNumber), stdin);
    account.accountNumber[strcspn(account.accountNumber, "\n")] = '\0';

    // Prompting the user to enter the account holder's name
    printf("Enter account holder name: ");
    fgets(account.accountHolderName, sizeof(account.accountHolderName), stdin);
    account.accountHolderName[strcspn(account.accountHolderName, "\n")] = '\0';

    // Prompting the user to enter the account balance
    printf("Enter account balance: ");
    scanf("%f", &account.balance);

    // Displaying the account details
    printf("\nAccount Details\n");
    printf("Account Number: %s\n", account.accountNumber);
    printf("Account Holder Name: %s\n", account.accountHolderName);
    printf("Balance: %.2f\n", account.balance);

    return 0;
}


/*
This program manages a bank account. It uses a structure called BankAccount to store the account number,
account holder's name, and account balance.
The user is prompted to enter the account details, and the program displays the entered information.
*/
