#include <stdio.h>
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
        printf("\n1. Insert new flat sale\n2. Delete flat sale\n3. Search flat sale\n4. Print all sales\n5. Get ZIP code\n6. Get Price\n7. Average Price\n8. Total Sales\n9. Exit\n");
        printf("Enter your choice: ");
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
                printf("\nAverage price: %.2f\n", AveragePrice(&db));
                break;
            case 8:
                printf("\nTotal sales: %d\n", SalesCount(&db));
                break;
            case 9:
                return 0;  
            default:
                printf("Invalid choice, try again.\n");
        }
    }
    return 0;
}

void Sales(SalesDatabase *db) {
    if (db->salesCount >= 100) {
        printf("Database is full!\n");
        return;
    }

    PropertySale new_sale;  

    printf("Enter UID: ");
    scanf("%d", &new_sale.uid);
    printf("Enter Address: ");
    scanf(" %[^\n]s", new_sale.address); 
    printf("Enter ZIP: ");
    scanf("%d", &new_sale.zip);
    printf("Enter size of Square Feet: ");
    scanf("%d", &new_sale.size);
    printf("Enter construction year: ");
    scanf("%d", &new_sale.year);
    printf("Enter price in taka: ");
    scanf("%d", &new_sale.price);

    db->sales[db->salesCount] = new_sale;
    db->salesCount++;  
    printf("Sale added successfully.\n");
}

void Erase(SalesDatabase *db) {
    int uid;
    printf("Enter the UID to delete: ");
    scanf("%d", &uid);

    int found = 0;  
    for (int i = 0; i < db->salesCount; i++) {
        if (db->sales[i].uid == uid) {
            found = 1;
            for (int j = i; j < db->salesCount - 1; j++) {
                db->sales[j] = db->sales[j + 1];
            }
            db->salesCount--;  
            printf("Sale with UID %d deleted successfully.\n", uid);
            break;
        }
    }

    if (!found) {
        printf("Sale with UID %d not found.\n", uid);
    }
}

void Search(SalesDatabase *db) {
    int uid;
    printf("Enter the UID to search: ");
    scanf("%d", &uid);

    for (int i = 0; i < db->salesCount; i++) {
        if (db->sales[i].uid == uid) {
            printf("Sale found: UID=%d, Address=%s, ZIP=%d, Size=%d, Year=%d, Price=%d\n",
                   db->sales[i].uid, db->sales[i].address, db->sales[i].zip,
                   db->sales[i].size, db->sales[i].year, db->sales[i].price);
            return;
        }
    }
    printf("Sale with UID %d not found.\n", uid);
}

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
    int uid;
    printf("Enter UID: ");
    scanf("%d", &uid);

    for (int i = 0; i < db->salesCount; i++) {
        if (db->sales[i].uid == uid) {
            printf("ZIP Code: %d\n", db->sales[i].zip);
            return;
        }
    }
    printf("Sale with UID %d not found.\n", uid);
}

void GetPrice(SalesDatabase *db) {
    int uid;
    printf("Enter UID: ");
    scanf("%d", &uid);

    for (int i = 0; i < db->salesCount; i++) {
        if (db->sales[i].uid == uid) {
            printf("Price: %d\n", db->sales[i].price);
            return;
        }
    }
    printf("Sale with UID %d not found.\n", uid);
}

int SalesCount(SalesDatabase *db) {
    return db->salesCount;
}

float AveragePrice(SalesDatabase *db) {
    if (db->salesCount == 0) {
        return 0.0;
    }

    float total_price = 0;
    for (int i = 0; i < db->salesCount; i++) {
        total_price += db->sales[i].price;
    }

    return total_price / db->salesCount;
}
