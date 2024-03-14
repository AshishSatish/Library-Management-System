#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a book
struct Book {
  char title[100];
  char author[100];
  int id;
  int isAvailable; // 1 if available, 0 if borrowed
  struct Book *next;
  struct Book *prev;
};

// Define the structure for a student request
struct StudentRequest {
  char studentName[100];
  int bookId;
  int isReturned; // 1 if returned, 0 if not returned
  struct StudentRequest *next;
};

// Global variables for the doubly linked list of books and student requests
struct Book *head = NULL;
struct StudentRequest *requests = NULL;

// Function to add a new book to the library
void addBook(char title[], char author[], int id) {
  struct Book *newBook = (struct Book *)malloc(sizeof(struct Book));
  if (newBook == NULL) {
    printf("Memory allocation failed.\n");
    return;
  }
  strcpy(newBook->title, title);
  strcpy(newBook->author, author);
  newBook->id = id;
  newBook->isAvailable = 1; // Initially, the book is available
  newBook->next = NULL;

  if (head == NULL) {
    newBook->prev = NULL;
    head = newBook;
  } else {
    struct Book *current = head;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = newBook;
    newBook->prev = current;
  }
  printf("Book added successfully.\n");
}

// Function to borrow a book
void borrowBook(char studentName[], int bookId) {
  struct Book *currentBook = head;
  while (currentBook != NULL) {
    if (currentBook->id == bookId) {
      if (currentBook->isAvailable) {
        struct StudentRequest *request =
            (struct StudentRequest *)malloc(sizeof(struct StudentRequest));
        strcpy(request->studentName, studentName);
        request->bookId = bookId;
        request->isReturned = 0; // Initially, the book is not returned
        request->next = requests;
        requests = request;

        currentBook->isAvailable = 0; // Mark the book as borrowed
        printf("Book with ID %d has been borrowed by %s.\n", bookId,
               studentName);
        return;
      } else {
        printf("Book with ID %d is already borrowed.\n", bookId);
        return;
      }
    }
    currentBook = currentBook->next;
  }
  printf("Book with ID %d not found.\n", bookId);
}

// Function to return a borrowed book
void returnBook(char studentName[], int bookId) {
  struct StudentRequest *currentRequest = requests;
  while (currentRequest != NULL) {
    if (currentRequest->bookId == bookId &&
        strcmp(currentRequest->studentName, studentName) == 0) {
      if (currentRequest->isReturned == 0) {
        struct Book *currentBook = head;
        while (currentBook != NULL) {
          if (currentBook->id == bookId) {
            currentBook->isAvailable = 1; // Mark the book as available
            printf("Book with ID %d has been returned by %s. Thank you!\n",
                   bookId, studentName);
            break;
          }
          currentBook = currentBook->next;
        }
        currentRequest->isReturned = 1; // Mark the request as returned
      } else {
        printf("Book with ID %d has already been returned by %s.\n", bookId,
               studentName);
      }
      return;
    }
    currentRequest = currentRequest->next;
  }
  printf("No matching request found for book ID %d and student %s.\n", bookId,
         studentName);
}

// Function to display all books in the library
void displayLibrary() {
  if (head == NULL) {
    printf("Library is empty.\n");
    return;
  }

  struct Book *current = head;
  while (current != NULL) {
    printf("Book ID: %d\n", current->id);
    printf("Title: %s\n", current->title);
    printf("Author: %s\n", current->author);
    printf("Availability: %s\n",
           current->isAvailable ? "Available" : "Borrowed");
    printf("\n");
    current = current->next;
  }
}

// Function to display student requests
void displayRequests() {
  if (requests == NULL) {
    printf("No active student requests.\n");
    return;
  }

  struct StudentRequest *current = requests;
  printf("Active Student Requests:\n");
  while (current != NULL) {
    printf("Student: %s\n", current->studentName);
    printf("Book ID: %d\n", current->bookId);
    printf("Status: %s\n", current->isReturned ? "Returned" : "Not Returned");
    printf("\n");
    current = current->next;
  }
}

int main() {
  // Initialize some books
  addBook("Book 1", "Author A", 1);
  addBook("Book 2", "Author B", 2);
  addBook("Book 3", "Author C", 3);

  int choice;
  char studentName[100];
  int bookId;

  while (1) {
    printf("Library Management System\n");
    printf("1. Borrow a Book\n");
    printf("2. Return a Book\n");
    printf("3. Display Library\n");
    printf("4. Display Student Requests\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      printf("Enter your name: ");
      scanf("%s", studentName);
      printf("Choose a book to borrow by entering its ID:\n");
      displayLibrary();
      printf("Enter the book ID: ");
      scanf("%d", &bookId);
      borrowBook(studentName, bookId);
      break;
    case 2:
      printf("Enter your name: ");
      scanf("%s", studentName);
      printf("Enter the book ID to return:\n");
      displayRequests();
      printf("Enter the book ID: ");
      scanf("%d", &bookId);
      returnBook(studentName, bookId);
      break;
    case 3:
      displayLibrary();
      break;
    case 4:
      displayRequests();
      break;
    case 5:
      exit(0);
    default:
      printf("Invalid choice. Please try again.\n");
    }
  }

  return 0;
}
