/*
Write a program that presents a menu to the user using an enum.
The user can select an option by entering a corresponding number. Implement actions for each menu option.
*/
#include <stdio.h>

// Enum representing menu options
enum MenuOption {
    Option1=1,
    Option2,
    Option3,
    Option4,
    Option5,
    Quit
};

int main() {
    enum MenuOption userChoice;

    do {
        printf("Menu:\n");
        printf("1. Option 1\n");
        printf("2. Option 2\n");
        printf("3. Option 3\n");
        printf("4. Option 4\n");
        printf("5. Option 5\n");
        printf("6. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &userChoice);

        switch (userChoice) {
            case Option1:
                printf("Option 1 selected.\n");
                break;
            case Option2:
                printf("Option 2 selected.\n");
                break;
            case Option3:
                printf("Option 3 selected.\n");
                break;
            case Option4:
                printf("Option 4 selected.\n");
                break;
            case Option5:
                printf("Option 5 selected.\n");
                break;
            case Quit:
                printf("Quitting the program.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    } while (userChoice != Quit);

    return 0;
}
/*
This program presents a menu to the user using an enum.
It allows the user to select options by entering the corresponding number.
The program then performs the action associated with the selected option or quits if the user chooses the "Quit" option.
*/
