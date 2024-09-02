/*C++ Lab question on File

Define a class Library with data members ISBN, bookTitle, author, and numberOfCopies. Implement methods to add new books, issue books, 
return books, update book details, and delete books. The library's catalog should be maintained in a file. Specifically, implement the
 following operations:
1. Add New Book: Insert a new book's details into the catalog file. Ensure that each book. has a unique ISBN and that duplicate 
entries are not allowed.
2. Issue Book: Mark a book as issued by decreasing the number of available copies in the catalog file. Ensure that a book cannot be
 issued if the number of available copies is zero. 3. Return Book: Mark a book as returned by increasing the number of available copies
  in the catalog file.
4. Update Book Details: Edit the details of a book, such as ISBN, book Title, author, or numberOfCopies, in the catalog file. Ensure
 that changing ISBN does not result in duplicates.
5. Delete Book: Allow the user to delete a book's record from the catalog file only if the following conditions are met:
.The number of available copies is zero.
• The book has not been issued to any user, meaning all copies have been returned and there are no outstanding issues for the book.
Ensure that the number of copies is appropriately updated for each operation and that file operations maintain data integrity, Provide
 methods to read from and write to the file for maintaining the catalog data.*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <conio.h>

using namespace std;

const int MAX_BOOKS = 100; // Define a fixed size for the book array

class Library {
    string ISBN, bookTitle, author;
    int numberOfCopies;

public:
    void getData() {
        cout << "Enter book details\n\n";
        cout << "Enter book ISBN: " << endl;
        cin >> ISBN;

        cout << "Enter book title: ";
        cin.ignore();
        getline(cin, bookTitle);

        cout << "Enter author name: ";
        getline(cin, author);

        cout << "Enter the number of copies: ";
        cin >> numberOfCopies;
        cin.ignore();
    }

    void showData() const {
        cout << "Book details\n";
        cout << "ISBN: " << ISBN << "\n";
        cout << "Title: " << bookTitle << "\n";
        cout << "Author: " << author << "\n";
        cout << "No. of copies: " << numberOfCopies << "\n";
    }

    static int readFromFile(Library books[]) {
        ifstream inf("Library.txt");
        if (!inf) {
            cerr << "Error opening file!\n";
            return 0;
        }

        string line, isbn, title, author;
        int copies, count = 0;
        while (getline(inf, line) && count < MAX_BOOKS) {
            stringstream ss(line);
            getline(ss, isbn, ',');
            getline(ss, title, ',');
            getline(ss, author, ',');
            ss >> copies;
            books[count].ISBN = isbn;
            books[count].bookTitle = title;
            books[count].author = author;
            books[count].numberOfCopies = copies;
            count++;
        }
        inf.close();
        return count;
    }

    static void writeToFile(Library books[], int count) {
        ofstream outf("Library.txt");
        if (!outf) {
            cerr << "Error creating file!\n";
            return;
        }
        for (int i = 0; i < count; i++) {
            outf << books[i].ISBN << "," << books[i].bookTitle << "," << books[i].author << "," << books[i].numberOfCopies << "\n";
        }
        outf.close();
    }

    void addBook() {
        Library books[MAX_BOOKS];
        int count = readFromFile(books);

        if (count >= MAX_BOOKS) {
            cout << "Library is full. Cannot add more books!\n";
            return;
        }

        cout << "Add Book\n";
        getData();

        for (int i = 0; i < count; i++) {
            if (books[i].ISBN == ISBN) {
                cout << "ISBN must be unique!\n";
                return;
            }
        }

        books[count] = *this;
        count++;
        writeToFile(books, count);
        cout << "Book added successfully!\n";
    }

    void issueBook() {
        string isbn;
        cout << "Enter the ISBN of the book to issue: ";
        cin >> isbn;

        Library books[MAX_BOOKS];
        int count = readFromFile(books);
        bool found = false;

        for (int i = 0; i < count; i++) {
            if (books[i].ISBN == isbn) {
                found = true;
                if (books[i].numberOfCopies > 0) {
                    books[i].numberOfCopies--;
                    cout << books[i].bookTitle << " issued successfully!\n";
                } else {
                    cout << "Sorry, this book is currently unavailable!\n";
                }
                break;
            }
        }

        if (!found) {
            cout << "Book with ISBN " << isbn << " not found!\n";
        } else {
            writeToFile(books, count);
        }
    }

    void returnBook() {
        string isbn;
        cout << "Enter the ISBN of the book to return: ";
        cin >> isbn;

        Library books[MAX_BOOKS];
        int count = readFromFile(books);
        bool found = false;

        for (int i = 0; i < count; i++) {
            if (books[i].ISBN == isbn) {
                found = true;
                books[i].numberOfCopies++;
                cout << books[i].bookTitle << " returned successfully!\n";
                break;
            }
        }

        if (!found) {
            cout << "Book with ISBN " << isbn << " not found!\n";
        } else {
            writeToFile(books, count);
        }
    }

    void updateBook() {
        string isbn;
        cout << "Enter the ISBN of the book to update: ";
        cin >> isbn;
        cin.ignore();

        Library books[MAX_BOOKS];
        int count = readFromFile(books);
        bool found = false;

        for (int i = 0; i < count; i++) {
            if (books[i].ISBN == isbn) {
                found = true;
                cout << "Update details\n";
                getData();
                books[i] = *this;
                break;
            }
        }

        if (!found) {
            cout << "Book with ISBN " << isbn << " not found!\n";
        } else {
            writeToFile(books, count);
            cout << "Book updated successfully!\n";
        }
    }

    void deleteBook() {
        string isbn;
        cout << "Enter the ISBN of the book to delete: ";
        cin >> isbn;

        Library books[MAX_BOOKS];
        int count = readFromFile(books);
        bool found = false;

        for (int i = 0; i < count; i++) {
            if (books[i].ISBN == isbn) {
                found = true;
                char confirm;
                cout << "Are you sure you want to delete the book \"" << books[i].bookTitle << "\"? (y/n): ";
                cin >> confirm;

                if (confirm == 'y' || confirm == 'Y') {
                    for (int j = i; j < count - 1; j++) {
                        books[j] = books[j + 1];
                    }
                    count--;
                    cout << "Book deleted successfully!\n";
                } else {
                    cout << "Deletion canceled.\n";
                }
                break;
            }
        }

        if (!found) {
            cout << "Book with ISBN " << isbn << " not found!\n";
        } else {
            writeToFile(books, count);
        }
    }

    void listBooks() {
        Library books[MAX_BOOKS];
        int count = readFromFile(books);

        if (count == 0) {
            cout << "No books available in the catalog.\n";
            return;
        }

        cout << "List of books\n\n";
        for (int i = 0; i < count; i++) {
            books[i].showData();
            cout << endl;
        }
    }
};

int main() {
    char ch;
    Library lib;

    while (true) {
        system("cls");
        cout << "Library Management System\n\n1.Add Book\n2.Issue Book\n3.Return Book\n4.Update Book\n5.Delete Book\n6.List Books\n7.Exit\n\nEnter your choice: ";
        cin >> ch;

        switch (ch) {
            case '1':
                lib.addBook();
                break;
            case '2':
                lib.issueBook();
                break;
            case '3':
                lib.returnBook();
                break;
            case '4':
                lib.updateBook();
                break;
            case '5':
                lib.deleteBook();
                break;
            case '6':
                lib.listBooks();
                break;
            case '7':
                exit(0);
            default:
                cout << "Invalid choice!";
        }

        cout << "\nPress any key to continue:";
        cin.ignore();
        getch();
    }
}

