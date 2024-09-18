#include <stdio.h>
#include <string.h>

// Define a structure for property sales
struct PropertySale {
    int uid, zip, year;
    float size, price;
    char address[50];
} pop[100]; // Array to hold 100 properties

int t = -1; // Index for the property array

// Function to insert new property sale information
void insert() {
    if (t >= 99) { // Limit the size of entries
        printf("Cannot add more properties. Database full.\n");
        return;
    }

    t++; // Increment index before storing data

    printf("\nEnter your Property Information:\n");

    printf("Enter Your UID: ");
    scanf("%d", &pop[t].uid);

    printf("Enter Address: ");
    scanf(" %[^\n]s", pop[t].address); // To allow spaces in address

    printf("Enter ZIP code: ");
    scanf("%d", &pop[t].zip);

    printf("Enter Size: ");
    scanf("%f", &pop[t].size);

    printf("Enter Construction Year: ");
    scanf("%d", &pop[t].year);

    printf("Enter Price: ");
    scanf("%f", &pop[t].price);

    printf("Property added successfully.\n");
}

// Function to delete a property from the system
void delete() {
    int uid, i, found = 0;

    if (t == -1) {
        printf("No properties to delete.\n");
        return;
    }

    printf("Enter the UID to delete: ");
    scanf("%d", &uid);

    for (i = 0; i <= t; i++) {
        if (pop[i].uid == uid) {
            found = 1;
            break;
        }
    }

    if (found =1) {
        for (int j = i; j < t; j++) {
            pop[j] = pop[j + 1]; // Shift left to remove the element
        }
        t--; // Decrease the index
        printf("Property with UID %d deleted successfully.\n", uid);
    } 
    else {
        printf("Property with UID %d not found.\n", uid);
    }
}

// Function to search for a property by UID
void search() {
    int uid, found = 0;

    if (t == -1) {
        printf("No properties to search.\n");
        return;
    }

    printf("Enter the UID to search: ");
    scanf("%d", &uid);

    for (int i = 0; i <= t; i++) {
        if (pop[i].uid == uid) {
            found = 1;
            printf("Property found:\n");
            printf("UID: %d, Address: %s, ZIP: %d, Size: %.2f, Year: %d, Price: %.2f\n",
                   pop[i].uid, pop[i].address, pop[i].zip, pop[i].size, pop[i].year, pop[i].price);
            break;
        }
    }

    if (!found) {
        printf("Property with UID %d not found.\n", uid);
    }
}

// Function to view all properties
void view() {
    if (t == -1) {
        printf("No properties available.\n");
        return;
    }

    for (int i = 0; i <= t; i++) {
        printf("\nProperty %d:\n", i + 1);
        printf("UID: %d, Address: %s, ZIP: %d, Size: %.2f sqft, Year: %d, Price: %.2f\n",
               pop[i].uid, pop[i].address, pop[i].zip, pop[i].size, pop[i].year, pop[i].price);
    }
}

// Function to get the ZIP code of a property by UID
void zip() {
    int uid, found = 0;

    if (t == -1) {
        printf("No properties available.\n");
        return;
    }

    printf("Enter the UID to get ZIP code: ");
    scanf("%d", &uid);

    for (int i = 0; i <= t; i++) {
        if (pop[i].uid == uid) {
            printf("ZIP code of UID %d is: %d\n", uid, pop[i].zip);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Property with UID %d not found.\n", uid);
    }
}

// Function to get the price of a property by UID
void price() {
    int uid, found = 0;

    if (t == -1) {
        printf("No properties available.\n");
        return;
    }

    printf("Enter the UID to get price: ");
    scanf("%d", &uid);

    for (int i = 0; i <= t; i++) {
        if (pop[i].uid == uid) {
            printf("Price of UID %d is: %.2f\n", uid, pop[i].price);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Property with UID %d not found.\n", uid);
    }
}

// Function to calculate the average price of all properties
void average_price() {
    if (t == -1) {
        printf("No properties available to calculate the average price.\n");
        return;
    }

    float total = 0;
    for (int i = 0; i <= t; i++) {
        total += pop[i].price;
    }

    printf("Average price of all properties is: %.2f\n", total / (t + 1));
}

// Function to count total sales (total number of properties)
void total_sale() {
    printf("Total sales (number of properties): %d\n", t + 1);
}

int main() {
    int n;

    do {
        printf("\n1. Insert New Flat Sale Information");
        printf("\n2. Delete a Property From the System");
        printf("\n3. Search a Property From the System");
        printf("\n4. View All Properties");
        printf("\n5. Get ZIP Code of a Property");
        printf("\n6. Get Price of a Property");
        printf("\n7. Average Price of All Properties");
        printf("\n8. Total Sales");
        printf("\n9. EXIT");
        printf("\nEnter your option: ");

        scanf("%d", &n); // Take input for menu option

        switch (n) {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                search();
                break;
            case 4:
                view();
                break;
            case 5:
                zip();
                break;
            case 6:
                price();
                break;
            case 7:
                average_price();
                break;
            case 8:
                total_sale();
                break;
            case 9:
                printf("Exiting...\n");
                break;
            default:
                printf("You Entered Invalid option, please try again.\n");
        }
    } while (n != 9); // Loop until the user selects exit

    return 0;
}