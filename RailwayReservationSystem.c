#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SEATS 50
#define FILENAME "bookings.dat"

typedef struct {
    int booking_id;
    char passenger_name[50];
    int train_number;
    int seat_number;
    char status[10];
} Ticket;

int get_next_booking_id() {
    Ticket t;
    int max_id = 0;
    FILE *fp = fopen(FILENAME, "rb");
    if (fp) {
        while (fread(&t, sizeof(Ticket), 1, fp)) 
            if (t.booking_id > max_id) max_id = t.booking_id;
        fclose(fp);
    }
    return max_id + 1;
}

void book_ticket() {
    Ticket t;
    printf("\n--- 1. Book New Ticket ---\n");
    
    int total = get_next_booking_id() - 1;
    if (total >= MAX_SEATS) {
        printf("**No seats available (MAX %d).**\n", MAX_SEATS);
        return;
    }
    
    t.booking_id = total + 1;
    printf("Passenger Name: ");
    scanf(" %[^\n]", t.passenger_name);
    printf("Train Number: ");
    scanf("%d", &t.train_number);
    t.seat_number = total + 1;
    strcpy(t.status, "BOOKED");
    
    FILE *fp = fopen(FILENAME, "ab");
    if (fp) {
        fwrite(&t, sizeof(Ticket), 1, fp);
        fclose(fp);
        printf("**Booked!** ID:%d, Seat:%d\n", t.booking_id, t.seat_number);
    }
}

void cancel_ticket() {
    int id;
    printf("\n--- 2. Cancel Ticket ---\nEnter ID: ");
    scanf("%d", &id);
    
    FILE *in = fopen(FILENAME, "rb"), *out = fopen("temp.dat", "wb");
    if (!in || !out) return;
    
    Ticket t;
    int found = 0;
    while (fread(&t, sizeof(Ticket), 1, in)) {
        if (t.booking_id == id && strcmp(t.status, "BOOKED") == 0) {
            strcpy(t.status, "CANCELLED");
            found = 1;
            printf("**Cancelled: %s**\n", t.passenger_name);
        }
        fwrite(&t, sizeof(Ticket), 1, out);
    }
    
    fclose(in); fclose(out);
    if (found) {
        remove(FILENAME);
        rename("temp.dat", FILENAME);
    } else {
        remove("temp.dat");
        printf("**ID %d not found.**\n", id);
    }
}

void check_availability() {
    Ticket t;
    FILE *fp = fopen(FILENAME, "rb");
    int booked = 0;
    
    printf("\n--- 3. Availability (Cap: %d) ---\n", MAX_SEATS);
    if (fp) {
        while (fread(&t, sizeof(Ticket), 1, fp))
            if (strcmp(t.status, "BOOKED") == 0) booked++;
        fclose(fp);
    }
    
    printf("Booked: %d, Available: %d\n", booked, MAX_SEATS - booked);
}

void view_all_bookings() {
    printf("\n--- 4. All Bookings ---\n");
    printf("+-------+---------------------------------+----------+----------+-----------+\n");
    printf("| ID    | Passenger Name                  | Train No | Seat No  | Status    |\n");
    printf("+-------+---------------------------------+----------+----------+-----------+\n");
    
    FILE *fp = fopen(FILENAME, "rb");
    if (!fp) {
        printf("No bookings.\n");
        return;
    }
    
    Ticket t;
    int count = 0;
    while (fread(&t, sizeof(Ticket), 1, fp)) {
        printf("| %-5d | %-31s | %-8d | %-8d | %-9s |\n",
               t.booking_id, t.passenger_name, t.train_number, t.seat_number, t.status);
        count++;
    }
    fclose(fp);
    printf("+-------+---------------------------------+----------+----------+-----------+\n");
    printf("Total: %d\n", count);
}

int main() {
    int choice;
    do {
        printf("\n\n==================================\n");
        printf("  RAILWAY RESERVATION SYSTEM\n");
        printf("==================================\n");
        printf("1. Book Ticket\n");
        printf("2. Cancel Ticket\n");
        printf("3. Check Availability\n");
        printf("4. View All Bookings\n");
        printf("5. Exit\n");
        printf("----------------------------------\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            continue;
        }
        
        switch (choice) {
            case 1: book_ticket(); break;
            case 2: cancel_ticket(); break;
            case 3: check_availability(); break;
            case 4: view_all_bookings(); break;
            case 5: printf("Goodbye!\n"); break;
            default: printf("Invalid (1-5)\n");
        }
    } while (choice != 5);
    return 0;
}
