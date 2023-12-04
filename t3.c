#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void header();
void option1();
void option2();
void option3();
void displayFlightDetails(int selectedTicket);
void saveTicketDetails(int tickets[], float prices[], int numTickets);
void saveFlightDetails(float flightPrices[], int size);
void printTicket(int ticketNo, int flightNo, float price,char user[]);

int main()
{
    int tickets[10];
    float prices[10];
    char user[50], pw[50], adminu[] = "kalam", adminpw[] = "hello";
    int trip, date, date2, x;
    float total = 0.0; // Initialize total to 0

    // Array to store flight prices
    float flightPrices[] = {1500.0, 1000.0, 3000.0, 1500.0, 1000.0, 3000.0, 1500.0, 1000.0, 3000.0};

    // File handling for flight details
    saveFlightDetails(flightPrices, sizeof(flightPrices) / sizeof(flightPrices[0]));

    printf("\nEnter username: ");
    fgets(user, sizeof(user), stdin);
    user[strcspn(user, "\n")] = '\0'; // Remove the newline character

    printf("\nEnter password: ");
    fgets(pw, sizeof(pw), stdin);
    pw[strcspn(pw, "\n")] = '\0'; // Remove the newline character

    printf("\n\n\t*******************************************************************");
    printf("\n\t                  AIRLINE BOOKING SYSTEM                  ");
    printf("\n\t*******************************************************************");

    if (strcmp(user, adminu) == 0 && strcmp(pw, adminpw) == 0)
    {
        printf("\nWelcome");

        printf("\nChoose if one way trip or roundtrip: ");
        printf("\n1. One way trip \n2. Roundtrip\n");
        scanf("%d", &trip);

        printf("\nDate: ");
        printf("\n1. Dec 10, 2023 \n2. Dec 14, 2023\n3. Dec 20, 2023(not applicable for round trip)\n");
        scanf("%d", &date);

        switch (trip)
        {
        case 1:
        {
            printf("\nHow many tickets will you get?:");
            scanf("%d", &x);

            int selectedTicket; // Move the declaration outside the loop

            for (int a = 0; a < x; a++)
            {
                printf("\nPlease select which flight you will book: ");

                printf("\nFlight                Price   Seating Capacity    Available Seats\n");
                printf("1. Islamabd to Karachi\t1,500   100         \t16\n");
                printf("2. Islamabad to Gilgit\t1,000   75          \t0\n");
                printf("3. Islamabd To Lahore \t3,000   100         \t24\n");

                scanf("%d", &selectedTicket);

                switch (date)
                {
                case 1:
                    displayFlightDetails(selectedTicket);
                    break;
                case 2:
                    displayFlightDetails(selectedTicket);
                    break;
                case 3:
                    displayFlightDetails(selectedTicket);
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

            // Print tickets after the loop
            printf("\nSummary: ");
            for (int a = 0; a < x; a++)
            {
                printf("\nDetails of Ticket no. [%d]", a + 1);
                printf("\nFlight no. [%d]\n", tickets[a]);
                displayFlightDetails(tickets[a]); // Call to display the flight details again in the summary
                // Print the ticket
                printTicket(a + 1, tickets[a], prices[a],adminu);
            }
        }
        break;

        case 2:
        {
            printf("\nHow many tickets will you get (excluding the return trip)?: ");
            scanf("%d", &x);

            for (int a = 0; a < x; a++)
            {
                int selectedTicket;
                printf("\nPlease select which flight you will book: ");
                scanf("%d", &selectedTicket);

                switch (date)
                {
                case 1:
                    displayFlightDetails(selectedTicket);
                    break;
                case 2:
                    displayFlightDetails(selectedTicket);
                    break;
                case 3:
                    displayFlightDetails(selectedTicket);
                    break;
                default:
                    printf("\nInvalid date");
                    return 1;
                }

                printf("\nChoose date of return: \n1. Dec 11, 2023\n2. Dec 12, 2023\n");
                scanf("%d", &date2);

                switch (selectedTicket)
                {
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

                // Print the ticket
                printTicket(a + 1, tickets[a], prices[a],adminu);
            }
        }
        break;

        default:
            printf("\nInvalid trip type");
            return 1;
        }

        printf("\nTotal number of tickets: %d\n", x);
        printf("Total Price: %0.2f\n", total);

        // File handling for ticket details
        saveTicketDetails(tickets, prices, x);
    }
    else
    {
        printf("\nInvalid login");
    }

    return 0;
}

void header()
{
    printf("\nFlight                Price   Seating Capacity    Available Seats\n");
}

void option1()
{
    printf("\nFlight                Price   Seating Capacity    Available Seats\n");
    printf("1. Islamabd to Karachi\t1,500   100         \t16\n");
    printf("2. Islamabad to Gilgit\t1,000   75          \t0\n");
    printf("3. Islamabd To Lahore \t3,000   100         \t24\n");
}

void option2()
{
    printf("\nFlight                Price   Seating Capacity    Available Seats\n");
    printf("4. Islamabd to Karachi    1,500   100      \t18\n");
    printf("5. Islamabad to Gilgit     1000   75        \t  24\n");
    printf("6. Islamabd To Lahore    3000   100         \t65\n");
}

void option3()
{
    printf("\nFlight                Price   Seating Capacity    Available Seats\n");
    printf("7. Islamabd to Karachi      1,500   100        \t 46\n");
    printf("8. Islamabad to Gilgit      1000   75          \t16\n");
    printf("9. Islamabd To Lahore      3,000   100         \t85\n");
}

void displayFlightDetails(int selectedTicket)
{
    switch (selectedTicket)
    {
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
        printf("\nInvalid flight selection");
        break;
    }
}

void saveTicketDetails(int tickets[], float prices[], int numTickets)
{
    FILE *ticketFile = fopen("ticket_details.txt", "a");
    if (ticketFile == NULL)
    {
        printf("Error opening file for writing ticket details. Exiting.\n");
        exit(1);
    }

    for (int i = 0; i < numTickets; i++)
    {
        fprintf(ticketFile, "Ticket No. [%d]\n", i + 1);
        fprintf(ticketFile, "Flight No. [%d]\n", tickets[i]);
        fprintf(ticketFile, "Price: %0.2f\n", prices[i]);
        fprintf(ticketFile, "\n");
    }

    fclose(ticketFile);
}

void saveFlightDetails(float flightPrices[], int size)
{
    FILE *flightFile = fopen("flight_details.dat", "wb");
    if (flightFile == NULL)
    {
        printf("Error opening file for writing flight details. Exiting.\n");
        exit(1);
    }

    fwrite(flightPrices, sizeof(float), size, flightFile);

    fclose(flightFile);
}

void printTicket(int ticketNo, int flightNo, float price,char user[])
{
    printf("\n");
    printf("\n");
    printf("************Ticket**************\n");
    printf("\n\nTicket No. [%d]", ticketNo);
    printf("\nFlight No. [%d]\n", flightNo);
   // displayFlightDetails(flightNo);
    printf("\nPASSENGER NAME: %s\n",user);
    printf("Price: %0.2f\n", price);
    printf("\n");
}
