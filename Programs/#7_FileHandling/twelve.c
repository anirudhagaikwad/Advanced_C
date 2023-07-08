/*
Write a program to delete a text file.
*/
#include <stdio.h>

int main() {
    int status;

    // Delete the file using remove function
    status = remove("text.txt");
    if (status == 0) {
        printf("File deleted successfully.\n");
    } else {
        printf("Unable to delete the file.\n");
    }

    return 0;
}
/*
This program deletes a text file ("text.txt") using the remove function. It calls the remove function and checks the return status.
If the file is successfully deleted, it displays a success message. Otherwise, it displays an error message.
*/
