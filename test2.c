#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void header();
void option1();
void option2();
void option3();

int main() {
    int tickets[10];
    float prices[10];
    char user[50], pw[50], adminu[] = "kalam", adminpw[] = "hello";
    int trip, date, date2, x;
    float total = 0.0; // Initialize total to 0

    // Array to store flight prices
    float flightPrices[] = {1500.0, 1000.0, 3000.0, 1700.0, 2000.0, 4000.0, 2000.0, 1500.0, 4000.0};

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
                    int selectedTicket;
                    printf("\nPlease select which flight you will book: ");
                    scanf("%d", &selectedTicket);

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

                    // Assign ticket number and price directly to arrays
                    tickets[a] = selectedTicket;
                    // Retrieve the price from the array based on the selected flight
                    prices[a] = flightPrices[selectedTicket - 1];
                    total += prices[a]; // Accumulate the total within the loop
                }
                break;
            }
            case 2: {
                printf("\nHow many tickets will you get (excluding the return trip)?: ");
                scanf("%d", &x);

                for (int a = 0; a < x; a++) {
                    int selectedTicket;
                    printf("\nPlease select which flight you will book: ");
                    scanf("%d", &selectedTicket);

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

                    switch (selectedTicket) {
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

                    // Assign ticket number and price directly to arrays
                    tickets[a] = selectedTicket;
                    // Retrieve the price from the array based on the selected flight
                    prices[a] = flightPrices[selectedTicket - 1];
                    total += prices[a]; // Accumulate the total within the loop
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
            printf("\nFlight no. [%d]\n", tickets[a]);
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
    printf("1. Islamabd to Karachi\t1,500   100         \t16\n");
    printf("2. Islamabad to Gilgit\t1,000   75          \t0\n");
    printf("3. Islamabd To Lahore \t3,000   100         \t24\n");
}

void option2() {
    printf("\nFlight                Price   Seating Capacity    Available Seats\n");
    printf("4. Islamabd to Karachi    1,700   100      \t18\n");
    printf("5. Islamabad to Gilgit     2,000   75        \t  24\n");
    printf("6. Islamabd To Lahore    4,000   100         \t65\n");
}

void option3() {
    printf("\nFlight                Price   Seating Capacity    Available Seats\n");
    printf("7. Islamabd to Karachi      2,000   100        \t 46\n");
    printf("8. Islamabad to Gilgit      1,500   75          \t16\n");
    printf("9. Islamabd To Lahore      4,000   100         \t85\n");
}
