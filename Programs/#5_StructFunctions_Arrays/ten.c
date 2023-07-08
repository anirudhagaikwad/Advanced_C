#include <stdio.h>

/* Implement a Product Inventory Management System using an array of structures.
Each product has a name and a structure representing its price,
which consists of the selling price and the cost price.
*/

// Structure definition for Price
struct Price {
    float sellingPrice;
    float costPrice;
};

// Structure definition for Product
struct Product {
    char name[50];
    struct Price price;
};

int main() {
    // Array of structures to store product data
    struct Product products[3];

    // Inputting product information
    printf("Enter details for 3 products:\n");
    for (int i = 0; i < 3; i++) {
        printf("Product %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", products[i].name);
        printf("Selling Price: ");
        scanf("%f", &products[i].price.sellingPrice);
        printf("Cost Price: ");
        scanf("%f", &products[i].price.costPrice);
        printf("\n");
    }

    // Displaying product information
    printf("Product Details:\n");
    for (int i = 0; i < 3; i++) {
        printf("Name: %s\n", products[i].name);
        printf("Selling Price: %.2f\n", products[i].price.sellingPrice);
        printf("Cost Price: %.2f\n", products[i].price.costPrice);
        printf("\n");
    }

    return 0;
}

/*
This program demonstrates a Product Inventory Management System using an array of structures.
Each product has a name and a price, represented by a nested structure.
The price consists of the selling price and the cost price of the product.
The program allows the user to input details for 3 products and then displays the product information.
*/
