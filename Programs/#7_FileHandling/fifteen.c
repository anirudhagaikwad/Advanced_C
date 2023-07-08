/*
file handling program in C that performs operations such as
renaming and deleting files, as well as handling file errors and exceptions.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *file;
    char filename[100], newFilename[100];

    printf("Enter the name of the file to rename: ");
    scanf("%s", filename);

    // Check if the file exists
    if (access(filename, F_OK) == -1) {
        printf("File does not exist.\n");
        return 1;
    }

    // Open the file in read mode
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Unable to open the file.\n");
        return 1;
    }

    // Close the file
    fclose(file);

    printf("Enter the new name for the file: ");
    scanf("%s", newFilename);

    // Rename the file
    if (rename(filename, newFilename) == 0) {
        printf("File renamed successfully.\n");

        // Open the renamed file in read mode
        file = fopen(newFilename, "r");
        if (file == NULL) {
            printf("Unable to open the renamed file.\n");
            return 1;
        }

        // Display the contents of the renamed file
        printf("Contents of the renamed file:\n");
        char ch;
        while ((ch = fgetc(file)) != EOF) {
            printf("%c", ch);
        }

        // Close the renamed file
        fclose(file);

        // Delete the renamed file
        if (remove(newFilename) == 0) {
            printf("Renamed file deleted successfully.\n");
        } else {
            printf("Unable to delete the renamed file.\n");
        }
    } else {
        printf("Unable to rename the file.\n");
    }

    return 0;
}
/*
In this program, the user is prompted to enter the name of a file to rename. The program first checks if the file exists using the access function. If the file does not exist, an error message is displayed, and the program terminates.
If the file exists, it is opened in read mode.

The user is then prompted to enter the new name for the file. The program uses the rename function to rename the file. If the renaming operation is successful, the program proceeds to open the renamed file in read mode.

The contents of the renamed file are then displayed on the console. The program reads each character from the file using fgetc and prints it until the end of the file is reached.

Finally, the program attempts to delete the renamed file using the remove function. If the deletion is successful, a success message is displayed. If not, an error message is displayed.

*/
