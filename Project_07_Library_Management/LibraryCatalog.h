/*
 * ============================================================================
 * LIBRARY CATALOG - BST IMPLEMENTATION
 * ============================================================================
 * Binary Search Tree for efficient book searching by ID
 * ============================================================================
 */

#ifndef LIBRARY_CATALOG_H
#define LIBRARY_CATALOG_H

#include "Book.h"

class BookNode {
public:
    Book data;
    BookNode* left;
    BookNode* right;

    BookNode(const Book& book) : data(book), left(nullptr), right(nullptr) {}
};

class LibraryCatalog {
private:
    BookNode* root;

    BookNode* insert(BookNode* node, const Book& book) {
        if (node == nullptr) {
            return new BookNode(book);
        }

        if (book.bookId < node->data.bookId) {
            node->left = insert(node->left, book);
        } else if (book.bookId > node->data.bookId) {
            node->right = insert(node->right, book);
        }

        return node;
    }

    BookNode* search(BookNode* node, int bookId) {
        if (node == nullptr || node->data.bookId == bookId) {
            return node;
        }

        if (bookId < node->data.bookId) {
            return search(node->left, bookId);
        }
        return search(node->right, bookId);
    }

    void inorder(BookNode* node) const {
        if (node != nullptr) {
            inorder(node->left);
            node->data.display();
            inorder(node->right);
        }
    }

    void searchByTitle(BookNode* node, const string& title) const {
        if (node != nullptr) {
            searchByTitle(node->left, title);
            if (node->data.title.find(title) != string::npos) {
                node->data.display();
            }
            searchByTitle(node->right, title);
        }
    }

public:
    LibraryCatalog() : root(nullptr) {}

    void addBook(const Book& book) {
        root = insert(root, book);
    }

    Book* findBook(int bookId) {
        BookNode* node = search(root, bookId);
        return (node != nullptr) ? &(node->data) : nullptr;
    }

    void displayAll() const {
        if (root == nullptr) {
            cout << "  No books in catalog!" << endl;
            return;
        }
        inorder(root);
    }

    void searchBooks(const string& title) const {
        cout << "\n  Search Results for \"" << title << "\":" << endl;
        searchByTitle(root, title);
    }
};

#endif
