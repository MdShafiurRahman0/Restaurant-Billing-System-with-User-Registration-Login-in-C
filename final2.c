#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 10
#define MAX_USERNAME 20
#define MAX_PASSWORD 20

// Global arrays
char bfmenu[7][100];
char lunchmenu[7][100];
char dinnermenu[7][100];


// Function declarations
void display_bfmenu();
void bfast(char bfmenu[][100]);
void lunch(char lunchmenu[][100]);
void dinner(char dinnermenu[][100]);

void repeatbf(char bfmenu[][100]);
void display_bf_bill(char bfmenu[][100]);

void lunch_menucard();
void dinner_menu();
void repeatlunch(char lunchmenu[][100]);
void repeatdinner(char dinnermenu[][100]);

struct User {
    char username[MAX_USERNAME];
    char password[MAX_PASSWORD];
};

struct User users[MAX_USERS];
int numUsers = 0;

int total = 0;
float gst, cgst, sgst;
int purchased[][3] = {
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0}
};

int bfrate[7][2] = {
    {0, 30},
    {1, 35},
    {2, 40},
    {3, 20},
    {4, 15},
    {5, 20},
    {6, 30}
};

int lunchrate[7][2] = {
    {0, 80},
    {1, 120},
    {2, 20},
    {3, 120},
    {4, 150},
    {5, 160},
    {6, 30}
};

int dinner_rate[7][2] = {
    {0, 65},
    {1, 50},
    {2, 70},
    {3, 80},
    {4, 65},
    {5, 110},
    {6, 50}
};

void registerUser() {
    if (numUsers < MAX_USERS) {
        printf("\nEnter a username: ");
        scanf("%s", users[numUsers].username);

        printf("Enter a password: ");
        scanf("%s", users[numUsers].password);

        printf("Registration successful!\n");

        // Increment the number of registered users
        numUsers++;
    } else {
        printf("Maximum number of users reached. Cannot register more users.\n");
    }
}

int loginUser() {
    char username[MAX_USERNAME];
    char password[MAX_PASSWORD];

    printf("\nEnter your username: ");
    scanf("%s", username);

    printf("Enter your password: ");
    scanf("%s", password);

    for (int i = 0; i < numUsers; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            printf("Login successful!\n");
            return 1; // Return 1 to indicate successful login
        }
    }

    printf("Invalid username or password.\n");
    return 0; // Return 0 to indicate login failure
}
    
int main_menu() {
    char mealChoice;
    do {
        printf("\n\t\t      [A] Breakfast\n");
        printf("\t\t      [B] Lunch\n");
        printf("\t\t      [C] Dinner\n");
        printf("\t\t      [X] Logout\n");
        printf("Enter your choice here: ");
        scanf(" %c", &mealChoice);
        switch (mealChoice) {
            case 'A':
            case 'a':
                display_bfmenu();
                bfast(bfmenu);  // Assuming bfmenu is defined somewhere in your code
                break;
            case 'B':
            case 'b':
                lunch(lunchmenu);  // Assuming lunchmenu is defined somewhere in your code
                break;
            case 'C':
            case 'c':
                dinner(dinnermenu);  // Assuming dinnermenu is defined somewhere in your code
                break;
            case 'X':
            case 'x':
                printf("\nLogging out.\n");
                return 0;  // Return 0 to indicate logout
            default:
                printf("\nInvalid choice. Please enter a valid option.\n");
        }
    } while (1);
    return 0;
}


void display() {
    // Implementation of display
    printf("                Welcome to Error Restaurant.          \n ");
    printf("             +============================+          \n\n");
    printf("  && Please select the meal that you would like to purchase. && \n\n");
    printf("\t\t      [A] Breakfast\n");
    printf("\t\t      [B] Lunch\n");
    printf("\t\t      [C] Dinner\n");
}

void display_bfmenu() {
    // Implementation of display_bfmenu
      printf("                Welcome to Error Restaurant.          \n ");
    printf("             +============================+          \n\n");
    printf("                  $  Breakfast Menu  $ \n\n");
    printf("  && Please select the food that you would like to purchase. && \n\n");
    printf("\t\t   [0] Toast - Rs 30.00\n");
    printf("\t\t   [1] Idli-Vada - Rs 35.00\n");
    printf("\t\t   [2] Dosa - Rs 40.00\n");
    printf("\t\t   [3] UPMA Rs 20.00\n");
    printf("\t\t   [4] Milk- Rs 15.00\n");
    printf("\t\t   [5] Tea - Rs 20.00\n");
    printf("\t\t   [6] Coffee - Rs 30.00\n");
}

void bfast(char bfmenu[][100]) {
    // Implementation of bfast
    int choice = 0; //local variables
    int quantity = 0;
    int again = 0,amt=0;
    int code,i;
    display_bfmenu();
    printf("\nEnter the code:: ");
    scanf("%d", &code);
    getchar();
    printf("Total is %d\n\n",total);
    if(code>=0&&code<=6)
    {
        printf("\nEnter the quantity::");
        scanf("%d",&quantity);
        purchased[code][1]= quantity*bfrate[code][1]; /*purchased[code][1]+ (quantity*bfrate[code][1]);*/
        total+=purchased[code][ 1];
        printf("Total is %d\n\n",total);
        gst=total*0.12;
        cgst=gst/2;
        sgst=cgst;  }
    else
    {   printf("\nInvalid code entered, Please enter the code again!!!!\n\n");
        bfast(bfmenu); }
    repeatbf(bfmenu);
}

void repeatbf(char bfmenu[][100]) {
    // Implementation of repeatbf
    int again = 0;
    printf("\nWould you like to buy anything else?\n[1] Yes , [2] No : "); // Allows the user to choose whether to check-out or buy anything else.
    scanf("%d", &again);
    if (again == 1)
        bfast(bfmenu);
    else if (again == 2) {
        display_bf_bill(bfmenu);
        exit(0);
    } else {
        printf("\n\n\t\tSorry Invalid Decision Entered\n");
        repeatbf(bfmenu);
    }
}

void display_bf_bill(char bfmenu[][100]) {
    // Implementation of display_bf_bill
     int i;
    printf("  +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+          \n\n");
    printf("                      Error RESTAURANT                   \n");
    printf("                    BILLING INFORMATION                \n");
    printf("\t\t ITEMS\t\tPrice(in Rs.)\n");
    for(i=0;i<7;i++)
    {
        if(purchased[i][1]!=0)
        {
            printf("\t\t%s\t\t",bfmenu[i]);
            printf("%d\n",purchased[i][1]); /*purchased[i][1]);*/
        }
    }
    printf("\t\tGST=Rs.%0.2f\n",gst);
    printf("\t\tC-GST=Rs.%0.2f\n",cgst);
    printf("\t\tS-GST=Rs.%0.2f\n",sgst);
    printf("\t\tTotal=Rs.%d\n",total);
   
    printf("\n\n  +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+          \n\n");


}

void display_lunch_bill(char lunchmenu[][100]) {
    // Implementation of display_lunch_bill
    int i;
    printf("  +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+          \n\n");
    printf("                      Error RESTAURANT                   \n");
    printf("                    BILLING INFORMATION                \n");
    printf("\t\t ITEMS\t\t\tPrice(in Rs.)\n");
    for(i=0;i<7;i++)
    {   if(purchased[i][1]!=0)
        {  printf("\t\t %s \t\t",lunchmenu[i]);
            printf("%d\n",purchased[i][1]); } }
    printf("\t\tGST=Rs.%0.2f\n",gst);
    printf("\t\tC-GST=Rs.%0.2f\n",cgst);
    printf("\t\tS-GST=Rs.%0.2f\n",sgst);
    printf("\t\tTotal=Rs.%d\n",total);
    printf("\n\n  +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+          \n\n");}


void display_dinner_bill(char dinnermenu[][100])
{
    int i;
    printf("  +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+          \n\n");
    printf("                      Error RESTAURANT                   \n");
    printf("                    BILLING INFORMATION                \n");
    printf("\t\t ITEMS\t\t\tPrice(in Rs.)\n");
    for(i=0;i<7;i++)
    {
        if(purchased[i][1]!=0)
        {
            printf("\t\t %s \t\t",dinnermenu[i]);
            printf("%d\n",purchased[i][1]);
        }

    }
    printf("\t\tGST=Rs.%0.2f\n",gst);
    printf("\t\tC-GST=Rs.%0.2f\n",cgst);
    printf("\t\tS-GST=Rs.%0.2f\n",sgst);
    printf("\t\tTotal=Rs.%d\n\n",total);
    printf("\n\n  +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+          \n\n");
}

void lunch(char lunchmenu[][100]) {
    // Implementation of lunch
    int choice = 0; //local variables
    int quantity = 0;
    int again = 0,amt=0;
    int code,i;
    lunch_menucard();
    printf("\nEnter the code:: ");
    scanf("%d", &code);
    getchar();
    if(code>=0&&code<=6)
    {
        printf("\nEnter the quantity::");
        scanf("%d",&quantity);
       // purchased[code][1]= purchased[code][1]+(quantity*lunchrate[code][1]);
        purchased[code][1]= quantity*lunchrate[code][1];
         total+=purchased[code][ 1];
        gst=total*0.12;
        cgst=gst/2;
        sgst=cgst;   }
    else
    {  printf("\nInvalid code entered, Please enter the code again!!!!\n\n");
         lunch(lunchmenu);  }
    repeatlunch(lunchmenu);
}

void dinner(char dinnermenu[][100]) {
    // Implementation of dinner
    int choice = 0; //local variables
    int quantity = 0;
    int again = 0,amt=0;
    int code,i;
    dinner_menu();
    printf("\nEnter the code:: ");
    scanf("%d", &code);
    getchar();
    if(code>=0&&code<=6)
    {
        printf("\nEnter the quantity::");
        scanf("%d",&quantity);
       // purchased[code][1]= purchased[code][1]+(quantity*dinner_rate[code][1]);
        purchased[code][1]= quantity*dinner_rate[code][1];
        total+=purchased[code][1];
        gst=total*0.12;
        cgst=gst/2;
        sgst=cgst;  }
    else
    { printf("\nInvalid code entered, Please enter the code again!!!!\n\n");
        dinner(dinnermenu); }
    repeatdinner(dinnermenu);
}

void lunch_menucard() {
    // Implementation of lunch_menucard
    printf("                Welcome to Error Restaurant.          \n ");
    printf("             +============================+          \n\n");
    printf("                   $  Lunch Menu  $ \n\n");
    printf("  && Please select the food that you would like to purchase. && \n\n");
    printf("\t\t   [0] Veg Biryani - Rs 80.00\n");
    printf("\t\t   [1] Special Meal- Rs 120.00\n");
    printf("\t\t   [2] Roti - Rs 20.00\n");
    printf("\t\t   [3] Dal tadka - Rs 120.00\n");
    printf("\t\t   [4] Paneer Tikka - Rs 150.00\n");
    printf("\t\t   [5] Veg Mix - Rs 160.00\n");
    printf("\t\t   [6] Ice cream - Rs 30.00\n");
    printf("Enter your choice here : ");
}

void dinner_menu() {
    // Implementation of dinner_menu
      printf("                Welcome to Error Restaurant.          \n ");
    printf("             +============================+          \n\n");
    printf("                    $  Dinner Menu  $ \n\n");
    printf("  && Please select the food that you would like to purchase. && \n\n");
    printf("\t\t   [0] Fried Rice - Rs 65.00\n");
    printf("\t\t   [1] Spagetti- Rs50\n");
    printf("\t\t   [2] Burger - Rs 70.00\n");
    printf("\t\t   [3] Pasta - Rs 80.00\n");
    printf("\t\t   [4] Noodles - Rs 65.00\n");
    printf("\t\t   [5] Paratha - Rs 110.00\n");
    printf("\t\t   [6] Fruit Salad - Rs 50.00\n");
}

void repeatlunch(char lunchmenu[][100]) {
    // Implementation of repeatlunch
    int again = 0;
    printf("\nWould you like to buy anything else?\n[1] Yes , [2] No : "); // Allows the user to choose whether to check-out or buy anything else.
    scanf("%d", &again);
    if (again == 1)
        lunch(lunchmenu);
    else if (again == 2) {
        display_lunch_bill(lunchmenu);
        exit(0);
    } else {
        printf("\n\n\t\tSorry Invalid Decision Entered\n");
        repeatlunch(lunchmenu);
    }
}

void repeatdinner(char dinnermenu[][100]) {
    // Implementation of repeatdinner
    int again = 0;
    printf("\nWould you like to buy anything else?\n[1] Yes , [2] No : "); // Allows the user to choose whether to check-out or buy anything else.
    scanf("%d", &again);
    if (again == 1)
        dinner(dinnermenu);
    else if (again == 2) {
        display_dinner_bill(dinnermenu);
        exit(0);
    } else {
        printf("\n\n\t\tSorry Invalid Decision Entered\n");
        repeatdinner(dinnermenu);
    }
}


int main() {
    char choice;
    do{ printf("\n\t\t      [L] Login\n");
        printf("\t\t      [R] Register\n");
        printf("\t\t      [D] Exit\n");
        printf("Enter your choice here : ");
        scanf(" %c", &choice);
        switch (choice) {
            case 'R':
            case 'r':
                registerUser();
                break;
            case 'L':
            case 'l':
                if (loginUser() == 1) {
                    // User logged in successfully, show main menu
                    main_menu(); }
                 else {
                    printf("\nInvalid username or password. Please try again.\n");     }
                break;
            case 'D':
            case 'd':
                printf("\nExiting the program.\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please enter a valid option.\n"); }
    } while (1);
   return 0;}
