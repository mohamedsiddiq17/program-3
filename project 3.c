/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <stdio.h>
#include <string.h>

// Structure to group different types of student information into one record
struct Student {
    int rollNo;
    char name[50];
    float cutoffMark;
    char city[50];
    char dream[100];
};

// Separate functional modules for collecting and displaying records
void collectDetails(struct Student s[], int n);
void displayDetails(struct Student s[], int n);

int main() {
    int n;

    // Step 1: Start the application
    printf("=============================================\n");
    printf("      STUDENT DETAILS MANAGEMENT SYSTEM      \n");
    printf("=============================================\n\n");

    // Step 2: Enter and validate the total number of students
    printf("Enter the total number of students: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid input! Please enter a positive number of students.\n");
        return 1;
    }

    // Array of structures to handle multiple student records
    struct Student students[n];

    // Step 3 & 4: Collect details for every student
    collectDetails(students, n);

    // Step 5: Display details of every student
    displayDetails(students, n);

    // Step 6: End the application
    printf("\nAll student records processed successfully. Exiting...\n");
    return 0;
}

// Module 1: Collects Roll Number, Name, Cut-off Mark, City, and Dream
void collectDetails(struct Student s[], int n) {
    for (int i = 0; i < n; i++) {
        printf("\n--- Enter Details for Student %d ---\n", i + 1);

        printf("Roll Number  : ");
        scanf("%d", &s[i].rollNo);
        getchar(); // Clears the newline left in the input buffer

        printf("Name         : ");
        fgets(s[i].name, sizeof(s[i].name), stdin);
        s[i].name[strcspn(s[i].name, "\n")] = '\0'; // Removes trailing newline

        printf("Cut-off Mark : ");
        scanf("%f", &s[i].cutoffMark);
        getchar(); // Clears the newline left in the input buffer

        printf("City         : ");
        fgets(s[i].city, sizeof(s[i].city), stdin);
        s[i].city[strcspn(s[i].city, "\n")] = '\0';

        printf("Dream        : ");
        fgets(s[i].dream, sizeof(s[i].dream), stdin);
        s[i].dream[strcspn(s[i].dream, "\n")] = '\0';
    }
}

// Module 2: Displays all student records in an organized format
void displayDetails(struct Student s[], int n) {
    printf("\n=============================================\n");
    printf("            STUDENT RECORDS SUMMARY          \n");
    printf("=============================================\n");

    for (int i = 0; i < n; i++) {
        printf("\nStudent %d:\n", i + 1);
        printf("  Roll Number  : %d\n", s[i].rollNo);
        printf("  Name         : %s\n", s[i].name);
        printf("  Cut-off Mark : %.2f\n", s[i].cutoffMark);
        printf("  City         : %s\n", s[i].city);
        printf("  Dream        : %s\n", s[i].dream);
        printf("---------------------------------------------\n");
    }
}