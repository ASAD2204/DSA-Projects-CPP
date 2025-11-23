/*
 * ============================================================================
 * PROJECT #7: LIBRARY BOOK MANAGEMENT SYSTEM - MAIN
 * ============================================================================
 */

#include "Book.h"
#include "LibraryCatalog.h"
#include <queue>
#include <iostream>
using namespace std;

class LibraryManager {
private:
    LibraryCatalog catalog;
    priority_queue<IssueRequest> requestQueue;
    int nextBookId;

public:
    LibraryManager() : nextBookId(101) {}

    void addBook(const string& title, const string& author, int copies) {
        Book book(nextBookId++, title, author, copies);
        catalog.addBook(book);
        cout << "✅ Book added with ID: " << (nextBookId - 1) << endl;
    }

    void displayAllBooks() const {
        cout << "\n📚 Library Catalog:" << endl;
        catalog.displayAll();
    }

    void searchBooks(const string& title) const {
        catalog.searchBooks(title);
    }

    void issueBook(int bookId, const string& studentName, int priority) {
        Book* book = catalog.findBook(bookId);
        
        if (book == nullptr) {
            cout << "❌ Book not found!" << endl;
            return;
        }

        if (book->availableCopies > 0) {
            book->availableCopies--;
            cout << "✅ Book issued to " << studentName << endl;
            cout << "   Remaining copies: " << book->availableCopies << endl;
        } else {
            IssueRequest req = {studentName, bookId, priority};
            requestQueue.push(req);
            cout << "⚠️  No copies available. Added to waiting list with priority " << priority << endl;
        }
    }

    void returnBook(int bookId) {
        Book* book = catalog.findBook(bookId);
        
        if (book == nullptr) {
            cout << "❌ Book not found!" << endl;
            return;
        }

        book->availableCopies++;
        cout << "✅ Book returned successfully!" << endl;

        // Process waiting requests
        while (!requestQueue.empty()) {
            IssueRequest req = requestQueue.top();
            if (req.bookId == bookId && book->availableCopies > 0) {
                requestQueue.pop();
                book->availableCopies--;
                cout << "📬 Book auto-issued to " << req.studentName 
                     << " (from waiting list)" << endl;
                break;
            } else {
                break;
            }
        }

        cout << "   Available copies: " << book->availableCopies << endl;
    }

    void showWaitingList() const {
        if (requestQueue.empty()) {
            cout << "\n⚠️  No pending requests!" << endl;
            return;
        }

        cout << "\n📋 Waiting List (by priority):" << endl;
        priority_queue<IssueRequest> temp = requestQueue;
        int pos = 1;
        while (!temp.empty()) {
            IssueRequest req = temp.top();
            temp.pop();
            Book* book = const_cast<LibraryCatalog&>(catalog).findBook(req.bookId);
            cout << "  " << pos++ << ". " << req.studentName 
                 << " waiting for Book ID " << req.bookId;
            if (book) cout << " (" << book->title << ")";
            cout << " - Priority: " << req.priority << endl;
        }
    }
};

int main() {
    LibraryManager library;

    cout << "\n========================================================\n";
    cout << "        LIBRARY BOOK MANAGEMENT SYSTEM                  \n";
    cout << "========================================================\n";

    // Add sample books
    library.addBook("Data Structures and Algorithms", "Cormen", 3);
    library.addBook("Introduction to Algorithms", "CLRS", 2);
    library.addBook("C++ Programming", "Bjarne Stroustrup", 4);
    library.addBook("Operating Systems", "Silberschatz", 2);
    library.addBook("Computer Networks", "Tanenbaum", 3);

    int choice;
    while (true) {
        cout << "\n  1. Add Book\n";
        cout << "  2. Display All Books\n";
        cout << "  3. Search Books\n";
        cout << "  4. Issue Book\n";
        cout << "  5. Return Book\n";
        cout << "  6. View Waiting List\n";
        cout << "  7. Exit\n";
        cout << "  Choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            string title, author;
            int copies;
            cout << "  Title: ";
            getline(cin, title);
            cout << "  Author: ";
            getline(cin, author);
            cout << "  Copies: ";
            cin >> copies;
            library.addBook(title, author, copies);
        }
        else if (choice == 2) {
            library.displayAllBooks();
        }
        else if (choice == 3) {
            string title;
            cout << "  Enter title to search: ";
            getline(cin, title);
            library.searchBooks(title);
        }
        else if (choice == 4) {
            int bookId, priority;
            string name;
            cout << "  Student Name: ";
            getline(cin, name);
            cout << "  Book ID: ";
            cin >> bookId;
            cout << "  Priority (1=High, 2=Med, 3=Low): ";
            cin >> priority;
            library.issueBook(bookId, name, priority);
        }
        else if (choice == 5) {
            int bookId;
            cout << "  Book ID: ";
            cin >> bookId;
            library.returnBook(bookId);
        }
        else if (choice == 6) {
            library.showWaitingList();
        }
        else if (choice == 7) {
            cout << "\n  📚 Thank you for using Library Management System!\n";
            break;
        }
    }

    return 0;
}
