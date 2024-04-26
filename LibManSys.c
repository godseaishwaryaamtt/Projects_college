#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants for maximum number of books and maximum length of strings
#define MAX_BOOKS 100
#define MAX_LENGTH 100

// Define structure to represent book information
typedef struct library {
    char b_name[MAX_LENGTH];
    char b_author[MAX_LENGTH];
    int b_pages;
    float b_price;
} lib;

// Global variable to keep track of the number of books
int count = 0;

// Function prototypes
void add_books(lib L[]);
void display_books(lib L[]);
void author_books(lib L[]);
int total();

int main() {
    lib L[MAX_BOOKS]; // Array to store book information

    int choice;
    while (1) {
        // Display menu options
        printf("\n\tWELCOME TO THE LIBRARY\n");
        printf("\t1. Add Book Information\n");
        printf("\t2. Display Book Information\n");
        printf("\t3. List all books by a given Author\n");
        printf("\t4. List the total count of books\n");
        printf("\t5. Exit\n");
        printf("\tEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_books(L);
                break;
            case 2:
                display_books(L);
                break;
            case 3:
                author_books(L);
                break;
            case 4:
                total();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

// Function to add book information
void add_books(lib L[]) {
    if (count >= MAX_BOOKS) {
        printf("Library full!\n");
        return;
    }

    // Input book name
    printf("Enter the Name of the Book: ");
    getchar(); // Consume the newline character left in the input buffer
    fgets(L[count].b_name, MAX_LENGTH, stdin);
    L[count].b_name[strcspn(L[count].b_name, "\n")] = '\0'; // Remove the newline character

    // Input author name
    printf("\nEnter the Name of the Author: ");
    fgets(L[count].b_author, MAX_LENGTH, stdin);
    L[count].b_author[strcspn(L[count].b_author, "\n")] = '\0'; // Remove the newline character

    // Input number of pages
    printf("\nEnter the number of Pages: ");
    scanf("%d", &L[count].b_pages);

    // Input price of the book
    printf("\nEnter the Price of the Book: ");
    scanf("%f", &L[count].b_price);

    count++; // Increment book count
}

// Function to display all book information
void display_books(lib L[]) {
    if (count == 0) {
        printf("Library is empty!\n");
        return;
    }

    printf("Library Database:\n");
    for (int i = 0; i < count; i++) {
        printf("Book Name: %s\n", L[i].b_name);
        printf("Author Name: %s\n", L[i].b_author);
        printf("Number of Pages: %d\n", L[i].b_pages);
        printf("Price of Book: %.2f\n", L[i].b_price);
        printf("\n");
    }
}

// Function to list all books by a given author
void author_books(lib L[]) {
    if (count == 0) {
        printf("Library is empty!\n");
        return;
    }

    char author_name[MAX_LENGTH];
    printf("Enter the Name of Author: ");
    getchar(); // Consume the newline character left in the input buffer
    fgets(author_name, MAX_LENGTH, stdin);
    author_name[strcspn(author_name, "\n")] = '\0'; // Remove the newline character

    printf("Books by Author '%s':\n", author_name);
    for (int i = 0; i < count; i++) {
        if (strcmp(author_name, L[i].b_author) == 0) {
            printf("Book Name: %s\n", L[i].b_name);
            printf("Number of Pages: %d\n", L[i].b_pages);
            printf("Price of Book: %.2f\n", L[i].b_price);
            printf("\n");
        }
    }
}

// Function to display the total count of books
int total() {
    printf("Total count of books: %d\n", count);
    return count;
}
