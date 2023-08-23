#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Emp {
    char name[10];
    int id;
};
void displayEmpDetails(struct Emp arr[], int size) {
    printf("\nEmployee Details:\n");
    for (int j = 0; j < size; j++) {
        printf("Employee %d\n", j + 1);
        printf("Name: %s\n", arr[j].name);
        printf("ID: %d\n", arr[j].id);
        printf("-----------------\n");
    }
}
int main() {
    struct Emp e4Arr[3]; // Array of 3 struct Emp 
    for (int i = 0; i < sizeof(e4Arr) / sizeof(e4Arr[0]); ++i) {
        printf("Enter details for Employee %d:\n", i + 1);
        printf("\nEnter Name: ");
        scanf("%s", e4Arr[i].name);
        printf("\nEnter ID: ");
        scanf("%d", &e4Arr[i].id);
    }

    displayEmpDetails(e4Arr, sizeof(e4Arr) / sizeof(e4Arr[0]));

    return 0;
}

