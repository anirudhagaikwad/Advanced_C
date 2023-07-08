#include <stdio.h>

/*Develop a Product Inventory Management System using functions and structures.
 Each product has a product ID and a structure representing its details,
 which consists of the name, price, and quantity in stock.
*/

// Structure definition for Product
struct Product {
    int productID;
    char name[50];
    float price;
    int quantity;
};

// Function to display product details
void displayProduct(struct Product prod) {
    printf("Product ID: %d\n", prod.productID);
    printf("Name: %s\n", prod.name);
    printf("Price: %.2f\n", prod.price);
    printf("Quantity: %d\n", prod.quantity);
    printf("\n");
}

int main() {
    // Creating a product structure variable
    struct Product prod;

    // Inputting product details
    printf("Enter product details:\n");
    printf("Product ID: ");
    scanf("%d", &prod.productID);
    printf("Name: ");
    scanf("%s", prod.name);
    printf("Price: ");
    scanf("%f", &prod.price);
    printf("Quantity: ");
    scanf("%d", &prod.quantity);
    printf("\n");

    // Displaying product details using the function
    printf("Product Details:\n");
    displayProduct(prod);

    return 0;
}
/*
This program implements a Product Inventory Management System using functions and structures.
Each product has a product ID and details such as name, price, and quantity in stock, represented by a structure.
The program allows the user to input product details and then displays the product information using a separate function.
*/
