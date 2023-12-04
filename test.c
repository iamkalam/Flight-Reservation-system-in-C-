#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void header();
void option1();
void option2();
void option3();

struct flight {
    int ticket;
    float price; // Changed from int to float for the price
};

int main() {
    struct flight book[10];
    char user[50], pw[50], adminu[] = "kalam", adminpw[] = "hello";
    int trip, date, date2, x;
    float total = 0.0; // Initialize total to 0

    printf("\nEnter username: ");
    fgets(user, sizeof(user), stdin);
    user[strcspn(user, "\n")] = '\0'; // Remove the newline character

    printf("\nEnter password: ");
    fgets(pw, sizeof(pw), stdin);
    pw[strcspn(pw, "\n")] = '\0'; // Remove the newline character

    if (strcmp(user, adminu) == 0 && strcmp(pw, adminpw) == 0) {
        printf("\nWelcome");

        printf("\nChoose if one way trip or roundtrip: ");
        printf("\n1. One way trip \n2. Roundtrip\n");
        scanf("%d", &trip);

        printf("\nDate: ");
        printf("\n1. August 10, 2017 \n2. August 11, 2017\n3. August 12, 2017(not applicable for round trip)\n");
        scanf("%d", &date);

        switch (trip) {
            case 1: {
                printf("\nHow many tickets will you get?:");
                scanf("%d", &x);

                for (int a = 0; a < x; a++) {
                    printf("\nPlease select which flight you will book: ");
                    scanf("%d", &book[a].ticket);
                    switch (date) {
                        case 1:
                            option1();
                            break;
                        case 2:
                            option2();
                            break;
                        case 3:
                            option3();
                            break;
                        default:
                            printf("\nInvalid date");
                            return 1;
                    }
                    total += book[a].price; // Accumulate the total within the loop
                }
                break;
            }
            case 2: {
                printf("\nHow many tickets will you get (excluding the return trip)?: ");
                scanf("%d", &x);

                for (int a = 0; a < x; a++) {
                    printf("\nPlease select which flight you will book: ");
                    scanf("%d", &book[a].ticket);

                    switch (date) {
                        case 1:
                            option1();
                            break;
                        case 2:
                            option2();
                            break;
                        case 3:
                            option3();
                            break;
                        default:
                            printf("\nInvalid date");
                            return 1;
                    }

                    printf("\nChoose date of return: \n1. August 11, 2017\n2. August 12, 2017\n");
                    scanf("%d", &date2);

                    switch (book[a].ticket) {
                        case 1:
                            printf("\nDetails for return trip");
                            header();
                            printf("Hong Kong to Manila     2,000   100         45\n");
                            break;
                        case 2:
                            printf("\nDetails for return trip");
                            header();
                            printf("Caticlan to Manila      1,500   75          67\n");
                            break;
                        case 3:
                            printf("\nDetails for return trip");
                            header();
                            printf("Singapore to Manila     4,000   100         46\n");
                            break;
                        default:
                            printf("\nInvalid");
                            return 1;
                    }
                    total += book[a].price; // Accumulate the total within the loop
                }
                break;
            }
            default:
                printf("\nInvalid trip type");
                return 1;
        }

        printf("\nSummary: ");
        for (int a = 0; a < x; a++) {
            printf("\nDetails of Ticket no. [%d]", a + 1);
            printf("\nFlight no. [%d]\n", book[a].ticket);
        }

        printf("\nTotal number of tickets: %d\n", x);
        printf("Total Price: %0.2f\n", total);
    } else {
        printf("\nInvalid login");
    }

    return 0;
}

void header() {
    printf("\nFlight                Price   Seating Capacity    Available Seats\n");
}

void option1() {
    printf("\nFlight                Price   Seating Capacity    Available Seats\n");
    printf("1. Manila To Hong Kong      1,500   100         16\n");
    printf("2. Manila To Caticlan       1,000   75          0\n");
    printf("3. Manila To Singapore      3,000   100         24\n");
}

void option2() {
    printf("\nFlight                Price   Seating Capacity    Available Seats\n");
    printf("4. Manila To Hong Kong      1,700   100         18\n");
    printf("5. Manila To Caticlan       2,000   75          24\n");
    printf("6. Manila To Singapore      4,000   100         65\n");
}

void option3() {
    printf("\nFlight                Price   Seating Capacity    Available Seats\n");
    printf("7. Manila To Hong Kong      2,000   100         46\n");
    printf("8. Manila To Caticlan       1,500   75          16\n");
    printf("9. Manila To Singapore      4,000   100         85\n");
}
