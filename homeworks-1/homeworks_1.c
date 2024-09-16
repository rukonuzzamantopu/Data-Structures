#include <stdio.h>
#include <stdlib.h> //for exit(0)
#include <string.h>

typedef struct {
    int uid;
    char address[100];
    int zip;
    int size;
    int year;
    int price;
} PropertySale;

typedef struct {
    PropertySale sales[100];
    int salesCount; 
} SalesDatabase;

void printMainMenu(void);
void Sales(SalesDatabase *db);
void Erase(SalesDatabase *db);
void Search(SalesDatabase *db);
void PrintDB(SalesDatabase *db);
void GetZIP(SalesDatabase *db);
void GetPrice(SalesDatabase *db);
int SalesCount(SalesDatabase *db);
float AveragePrice(SalesDatabase *db);



int main() {
    SalesDatabase db;
    db.salesCount = 0;  
    int choice;
    
    while (1) { 
        printMainMenu();
        printf("\n\nENTER YOUR CHOICE: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                Sales(&db);    
                break;
            case 2:
                Erase(&db);    
                break;
            case 3:
                Search(&db);   
                break;
            case 4:
                PrintDB(&db);  
                break;
            case 5:
                GetZIP(&db);  
                break;
            case 6:
                GetPrice(&db);  
                break;
            case 7:
                printf("\nAverage price of all sales: %.2f\n", AveragePrice(&db));
                break;
            case 8:
                printf("\nTotal sales: %d\n", SalesCount(&db));
                break;
            case 9:
                exit(0);       
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}


void printMainMenu(void) {
    printf("\nWELCOME TO OUR SYSTEM\n\n");
    printf("1. Insert new flat sale information\n");
    printf("2. Delete a property from the system\n");
    printf("3. Find a property from the system\n");
    printf("4. See all properties\n");
    printf("5. Zip code\n");
    printf("6. Price of proprety\n");
    printf("7. Average prices\n");
    printf("8. Total sales\n");
    printf("7. EXIT\n");
}

void Sales(SalesDatabase *db) {
        int uid, zip, year, price;
        float size;
        char address[100];

        printf("Enter UID: ");
        scanf("%d", &uid);
        printf("Enter Address: ");
        scanf(" %[^\n]s", address); 
        printf("Enter ZIP code: ");
        scanf("%d", &zip);
        printf("Enter size: ");
        scanf("%f", &size);
        printf("Enter construction year: ");
        scanf("%d", &year);
        printf("Enter price: ");
        scanf("%d", &price);

        PropertySale new_sale = {uid, "", zip, size, year, price};
        strcpy(new_sale.address, address);

        db->sales[db->salesCount] = new_sale;
        db->salesCount++;

        printf("Sale add successfully.\n");
    }

void Erase(SalesDatabase *db) {
    int uid;
    printf("Enter the UID to delete: ");
    scanf("%d", &uid);

    for (int i = 0; i < db->salesCount; i++) {
        if (db->sales[i].uid == uid) {
            for (int j = i; j < db->salesCount-1; j++) {
                db->sales[j] = db->sales[j + 1];
            }
            db->salesCount--;
            printf("Sale with UID %d deleted successfully.\n", uid);
            break;
        }
        printf("Sale with UID %d not found.\n", uid);
    }
}

void Search(SalesDatabase *db) {
    int uid,count=0;;
    printf("Enter the UID to search for: ");
    scanf("%d", &uid);

    for (int i = 0; i < db->salesCount; i++) {
        if (db->sales[i].uid == uid) {
            printf("Sale found: UID=%d, Address=%s, ZIP=%d, Size=%d, Year=%d, Price=%d\n",
            db->sales[i].uid, db->sales[i].address, db->sales[i].zip,
            db->sales[i].size, db->sales[i].year, db->sales[i].price);
            count = 1;  // To marke property is found
        }
    }

    if (count==0) {
        printf("Sale with UID %d not found.\n", uid);
    }
}

// Function of sales database
void PrintDB(SalesDatabase *db) {
    if (db->salesCount == 0) {
        printf("No sales available.\n");
        return;
    }

    for (int i = 0; i < db->salesCount; i++) {
        printf("UID: %d, Address: %s, ZIP: %d, Size: %d, Year: %d, Price: %d\n",
        db->sales[i].uid, db->sales[i].address, db->sales[i].zip,
        db->sales[i].size, db->sales[i].year, db->sales[i].price);
    }
}


void GetZIP(SalesDatabase *db) {
    int uid,count=0;;
    printf("Enter the UID: ");
    scanf("%d", &uid);

    for (int i = 0; i < db->salesCount; i++) {
        if (db->sales[i].uid == uid) {
            printf("Zip Code: %d\n", db->sales[i].zip);
            count = 1;  // To marke zip code is found
        }
    }

    if (count==0) {
        printf("Zip code with UID %d not found.\n", uid);
    }
}


void GetPrice(SalesDatabase *db) {
    int uid,count=0;;
    printf("Enter the UID: ");
    scanf("%d", &uid);

    for (int i = 0; i < db->salesCount; i++) {
        if (db->sales[i].uid == uid) {
            printf("Price: %d\n", db->sales[i].price);
            count = 1;  // To marke price is found
        }
    }

    if (count==0) {
        printf("Price with UID %d not found.\n", uid);
    }
}

float AveragePrice(SalesDatabase *db) {
    if (db->salesCount == 0) {
        return 0.0f;
    }

    float total_price = 0;
    for (int i = 0; i < db->salesCount; i++) {
        total_price += db->sales[i].price;
    }

    return total_price / db->salesCount;
}


int SalesCount(SalesDatabase *db) {
    return db->salesCount;
}