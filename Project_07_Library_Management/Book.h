/*
 * ============================================================================
 * PROJECT #7: LIBRARY BOOK MANAGEMENT SYSTEM
 * ============================================================================
 * Data Structure: BST (for book catalog) + Priority Queue (for issue requests)
 * Features: Add/search books, issue/return, priority-based request queue
 * ============================================================================
 */

#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <iostream>
using namespace std;

struct Book {
    int bookId;
    string title;
    string author;
    int totalCopies;
    int availableCopies;

    Book() : bookId(0), totalCopies(0), availableCopies(0) {}
    
    Book(int id, string t, string a, int copies) 
        : bookId(id), title(t), author(a), totalCopies(copies), availableCopies(copies) {}

    void display() const {
        cout << "  [" << bookId << "] " << title << " by " << author 
             << " (" << availableCopies << "/" << totalCopies << " available)" << endl;
    }
};

struct IssueRequest {
    string studentName;
    int bookId;
    int priority; // 1 = High, 2 = Medium, 3 = Low

    bool operator<(const IssueRequest& other) const {
        return priority > other.priority; // Min heap (higher priority first)
    }
};

#endif
