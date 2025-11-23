/*
 * ============================================================================
 * PROJECT #2: CONTACT BOOK / PHONEBOOK
 * ============================================================================
 * Author: [Your Name]
 * Course: Data Structures & Algorithms
 * 
 * Description:
 *   A phonebook application using Binary Search Tree for efficient contact
 *   storage and retrieval. Supports searching, categorization, and CSV export.
 * 
 * Features:
 *   ✅ Add new contacts
 *   ✅ View all contacts (alphabetically sorted)
 *   ✅ Search by name (prefix matching)
 *   ✅ Search by phone number
 *   ✅ Search by category
 *   ✅ Delete contacts
 *   ✅ Export to CSV
 *   ✅ Auto-save/load
 * 
 * Data Structure: Binary Search Tree (BST)
 * Time Complexity: O(log n) average for search/insert/delete
 * ============================================================================
 */

#include "ContactBook.h"
#include <iostream>
#include <limits>
using namespace std;

void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void displayMenu() {
    cout << "\n";
    cout << "========================================================\n";
    cout << "           CONTACT BOOK MANAGEMENT SYSTEM               \n";
    cout << "========================================================\n";
    cout << "\n";
    cout << "  [CONTACT] OPERATIONS:\n";
    cout << "    1. Add New Contact\n";
    cout << "    2. Display All Contacts\n";
    cout << "    3. Search Contact\n";
    cout << "    4. Delete Contact\n";
    cout << "\n";
    cout << "  💾 FILE OPERATIONS:\n";
    cout << "    5. Export to CSV\n";
    cout << "    6. Save & Exit\n";
    cout << "\n";
    cout << "  Enter your choice: ";
}

void searchMenu(ContactBook& book) {
    int choice;
    cout << "\n";
    cout << "  🔍 SEARCH OPTIONS:\n";
    cout << "    1. Search by Name\n";
    cout << "    2. Search by Phone Number\n";
    cout << "    3. Search by Category\n";
    cout << "    4. Back to Main Menu\n";
    cout << "\n  Enter choice: ";
    cin >> choice;

    string input;
    cin.ignore();

    switch(choice) {
        case 1:
            cout << "\n  Enter name (or part of name): ";
            getline(cin, input);
            book.searchByName(input);
            break;
        case 2:
            cout << "\n  Enter phone number: ";
            getline(cin, input);
            book.searchByPhone(input);
            break;
        case 3:
            cout << "\n  Enter category: ";
            getline(cin, input);
            book.searchByCategory(input);
            break;
        case 4:
            return;
        default:
            cout << "\n  ❌ Invalid choice!" << endl;
    }
}

void addSampleData(ContactBook& book) {
    cout << "\n  📥 Adding sample contacts..." << endl;
    
    book.addContact(Contact("John Doe", "555-0101", "john@email.com", "123 Main St", "Family"));
    book.addContact(Contact("Jane Smith", "555-0102", "jane@email.com", "456 Oak Ave", "Friends"));
    book.addContact(Contact("Bob Johnson", "555-0103", "bob@work.com", "789 Pine Rd", "Work"));
    book.addContact(Contact("Alice Williams", "555-0104", "alice@email.com", "321 Elm St", "Family"));
    book.addContact(Contact("Charlie Brown", "555-0105", "charlie@email.com", "654 Maple Dr", "Friends"));
    
    cout << "\n  ✅ Sample data added successfully!" << endl;
}

int main() {
    ContactBook book("contacts.csv");
    int choice;
    bool running = true;

    cout << "\n";
    cout << "╔════════════════════════════════════════════════════════╗\n";
    cout << "║                    WELCOME TO                          ║\n";
    cout << "║          CONTACT BOOK MANAGEMENT SYSTEM                ║\n";
    cout << "╚════════════════════════════════════════════════════════╝\n";

    if (book.getTotalContacts() > 0) {
        cout << "\n  ℹ️  Loaded " << book.getTotalContacts() << " contact(s) from file.\n";
    } else {
        char addSample;
        cout << "\n  No existing contacts found.";
        cout << "\n  Would you like to add sample data? (y/n): ";
        cin >> addSample;
        if (addSample == 'y' || addSample == 'Y') {
            addSampleData(book);
        }
    }

    while (running) {
        displayMenu();
        cin >> choice;

        switch(choice) {
            case 1: {
                string name, phone, email, address, category;

                cout << "\n  ➕ ADD NEW CONTACT\n";
                cout << "  " << string(50, '-') << endl;

                cin.ignore();
                cout << "  Name: ";
                getline(cin, name);

                cout << "  Phone Number: ";
                getline(cin, phone);

                cout << "  Email: ";
                getline(cin, email);

                cout << "  Address: ";
                getline(cin, address);

                cout << "  Category (Family/Friends/Work/General): ";
                getline(cin, category);
                if (category.empty()) category = "General";

                Contact newContact(name, phone, email, address, category);
                book.addContact(newContact);
                break;
            }

            case 2:
                cout << "\n  📋 ALL CONTACTS (Alphabetically Sorted)\n";
                book.displayAll();
                break;

            case 3:
                searchMenu(book);
                break;

            case 4: {
                string name;
                cout << "\n  🗑️  DELETE CONTACT\n";
                cout << "  Enter name to delete: ";
                cin.ignore();
                getline(cin, name);

                char confirm;
                cout << "\n  Are you sure? (y/n): ";
                cin >> confirm;
                if (confirm == 'y' || confirm == 'Y') {
                    book.deleteContact(name);
                } else {
                    cout << "\n  ❌ Deletion cancelled." << endl;
                }
                break;
            }

            case 5: {
                string exportFile;
                cout << "\n  💾 EXPORT TO CSV\n";
                cout << "  Enter filename (e.g., my_contacts.csv): ";
                cin.ignore();
                getline(cin, exportFile);
                book.exportToCSV(exportFile);
                break;
            }

            case 6:
                cout << "\n  💾 Saving data..." << endl;
                book.saveToFile();
                cout << "\n";
                cout << "  ╔════════════════════════════════════════════╗\n";
                cout << "  ║   Thank you for using Contact Book!        ║\n";
                cout << "  ╚════════════════════════════════════════════╝\n";
                cout << "\n";
                running = false;
                break;

            default:
                cout << "\n  ❌ Invalid choice!" << endl;
                clearInputBuffer();
        }

        if (running && choice >= 1 && choice <= 6) {
            cout << "\n  Press Enter to continue...";
            clearInputBuffer();
            cin.get();
        }
    }

    return 0;
}
