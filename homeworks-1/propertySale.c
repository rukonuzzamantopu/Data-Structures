#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for sales info
typedef struct {
    int uid;
    char address[100];
    int zip;
    int size;
    int year;
    int price;
} PropertySale;

// Structure for sales database
typedef struct {
    PropertySale sales[100];
    int salesCount;
} SalesDatabase;


void printMainMenu();
void Sales(SalesDatabase *db);
void Erase(SalesDatabase *db);
void Search(SalesDatabase *db);
void PrintDB(SalesDatabase *db);
void GetZIP(SalesDatabase *db);
void GetPrice(SalesDatabase *db);
void SaleCount(SalesDatabase *db);
int AveragePrice(SalesDatabase *db);
void SortByPriceAsc(SalesDatabase *db);
void SortByPriceDesc(SalesDatabase *db);
void SortRange(SalesDatabase *db);


int main() {
    int choice,pass;
    SalesDatabase db; // Declaring pointer to access database
    db.salesCount = 0;  // Declaring salesCount with 0 to count the number of sales property

    printf("\nPASSWORD: ");
    scanf("%d", &pass);
    for(;pass!=553;){
        printf("Invalid Password!\n");
        printf("\nPASSWORD: ");
        scanf("%d", &pass);
    }

    for(;pass==553;){
        printMainMenu();
        printf("\n\nENTER YOUR CHOICE: ");
        scanf("%d", &choice);
        printf("\n");

        if (choice==1) {
                Sales(&db);    // Insert a new sale info
                }
        else if (choice==2){
                Erase(&db);    // Delete a sale info
                }
        else if (choice==3){
                Search(&db);   // Search for a sale info
                }
        else if (choice==4){
                PrintDB(&db);  // Print the database
                }
        else if (choice==5){
                GetZIP(&db);
                }
        else if (choice==6){
                GetPrice(&db);
                }
        else if (choice==7){
                AveragePrice(&db); 
                }
        else if (choice==8){
                SaleCount(&db);
                }
        else if (choice==9){
                SortByPriceAsc(&db);
                }
        else if (choice==10){
                SortByPriceDesc(&db);
                }
        else if (choice==11){
                SortRange(&db);
                }
        else if (choice==12){
                break;
                }
        else{
            printf("Invalid choice. Please try again.\n");}
    }
    printf("Log Out Successful\n");
    return 0;
}



// Main menu fuction
void printMainMenu() {
    printf("\nMain Menu:\n");
    printf("1. Insert new flat sale information\n");
    printf("2. Delete a property from the system\n");
    printf("3. Find a property from the system\n");
    printf("4. See all properties\n");
    printf("5. Get zip code\n");
    printf("6. Price\n");
    printf("7. Average prices of sales property\n");
    printf("8. Total sales\n");
    printf("9. Sort by ascending order\n");
    printf("10. Sort by descending order\n");
    printf("11. Sort by range\n");
    printf("12. Log Out\n");
    printf("..........");
}


// Function to insert a new sale info
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

        PropertySale newSale = {uid, "", zip, size, year, price};
        strcpy(newSale.address, address);

        db->sales[db->salesCount] = newSale;
        db->salesCount++;

        printf("Sale added successfully.\n");
    }


// Function to delete a sold property info
void Erase(SalesDatabase *db) {
    int uid,count=0;
    printf("Enter the UID to delete: ");
    scanf("%d", &uid);

    for (int i = 0; i < db->salesCount; i++) {
        if (db->sales[i].uid == uid) {
            for (int j = i; j < db->salesCount-1; j++) {
                db->sales[j] = db->sales[j + 1];
            }
            db->salesCount--;
            printf("Sale with UID %d deleted successfully.\n", uid);
            count=1;  // To marke property is deleted
        }
    }
    if(count==0){
        printf("Sale with UID %d not found.\n", uid);
    }
}


// Function to search sold property
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


// Function to print sales database
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


// Function to get zip code
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


// Function to find price info
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


// Function of average price of sales
int AveragePrice(SalesDatabase *db) {
    if (db->salesCount == 0) {
        printf("Average price of sales: 0.00\n");
        return 0;
    }

    float avg,totalPrice = 0;
    for (int i = 0; i < db->salesCount; i++) {
        totalPrice += db->sales[i].price;
    }
    avg = totalPrice / db->salesCount;
    printf("Average price of sales: %.2f\n",avg);
    return 0;
}


// Fuction of total sales
void SaleCount(SalesDatabase *db) {
    int sales=db->salesCount;
    printf("Total sales: %d\n",sales);
}

// Ascending order by bubble sort
void SortByPriceAsc(SalesDatabase *db) {
    for (int i = 0; i < db->salesCount; i++) {
        for(int j =0; j<db->salesCount-1; j++)
        if(db->sales[j].price > db->sales[j+1].price){
            PropertySale temp=db->sales[j];
            db->sales[j]=db->sales[j+1];
            db->sales[j+1]=temp;
        }
    }
    printf("Properties sorted successfully.\n");
}
// Descending order by insertion sort
void SortByPriceDesc(SalesDatabase *db) {
    for (int i = 1; i < db->salesCount; i++) {
        PropertySale v = db->sales[i];
        int j = i - 1;
        while (j >= 0 && db->sales[j].price < v.price) {
            db->sales[j + 1] = db->sales[j];
            j--;
        }
        db->sales[j + 1] = v;
    }
    printf("Properties sorted successfully in descending order.\n");
}
// Sort in range by selection sort
void SortRange(SalesDatabase *db) {
    int low, up;
    printf("Enter the range of price (low high): ");
    scanf("%d %d", &low, &up);
    PropertySale propertiesInRange[db->salesCount];
    int inRangeCount = 0;
    PropertySale propertiesOutOfRange[db->salesCount];
    int outOfRangeCount = 0;
    for (int i = 0; i < db->salesCount; i++) {
        if (db->sales[i].price >= low && db->sales[i].price <= up) {
            propertiesInRange[inRangeCount++] = db->sales[i];
        } else {
            propertiesOutOfRange[outOfRangeCount++] = db->sales[i];
        }
    }
    // Sort the properties within the range using selection sort
    for (int i = 0; i < inRangeCount - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < inRangeCount; j++) {
            if (propertiesInRange[j].price < propertiesInRange[min_idx].price) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            PropertySale temp = propertiesInRange[i];
            propertiesInRange[i] = propertiesInRange[min_idx];
            propertiesInRange[min_idx] = temp;
        }
    }
    printf("Properties sorted successfully within range.\n");
    //results
    int Choice;
    printf("1. Print\n");
    printf("2. Exsit\n");
    scanf("%d", &Choice);
    if (Choice == 1) {
        for (int i = 0; i < inRangeCount; i++) {
            printf("UID: %d, Address: %s, ZIP: %d, Size: %d, Year: %d, Price: %d\n",
                propertiesInRange[i].uid, propertiesInRange[i].address, propertiesInRange[i].zip,
                propertiesInRange[i].size, propertiesInRange[i].year, propertiesInRange[i].price);
        }
        for (int i = 0; i < outOfRangeCount; i++) {
            printf("UID: %d, Address: %s, ZIP: %d, Size: %d, Year: %d, Price: %d\n",
                propertiesOutOfRange[i].uid, propertiesOutOfRange[i].address, propertiesOutOfRange[i].zip,
                propertiesOutOfRange[i].size, propertiesOutOfRange[i].year, propertiesOutOfRange[i].price);
        }
    }
    else if(Choice == 2){
        exit(0);
    }
}