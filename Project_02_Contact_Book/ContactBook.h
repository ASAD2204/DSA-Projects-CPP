/*
 * ============================================================================
 * ContactBook.h - Contact Book Management using BST
 * ============================================================================
 * Implements contact storage using Binary Search Tree for efficient searching
 * ============================================================================
 */

#ifndef CONTACTBOOK_H
#define CONTACTBOOK_H

#include "Contact.h"
#include <fstream>
#include <algorithm>
#include <vector>

class ContactBook {
private:
    // Node structure for BST
    struct Node {
        Contact data;
        Node* left;
        Node* right;

        Node(Contact c) : data(c), left(nullptr), right(nullptr) {}
    };

    Node* root;
    int totalContacts;
    string filename;

    // Helper function to insert recursively
    Node* insertHelper(Node* node, const Contact& contact) {
        if (node == nullptr) {
            totalContacts++;
            return new Node(contact);
        }

        // Compare names for BST ordering (case-insensitive)
        string name1 = contact.getName();
        string name2 = node->data.getName();
        transform(name1.begin(), name1.end(), name1.begin(), ::tolower);
        transform(name2.begin(), name2.end(), name2.begin(), ::tolower);

        if (name1 < name2) {
            node->left = insertHelper(node->left, contact);
        } else if (name1 > name2) {
            node->right = insertHelper(node->right, contact);
        } else {
            cout << "\n❌ Contact with name '" << contact.getName() << "' already exists!" << endl;
        }

        return node;
    }

    // Inorder traversal to display contacts alphabetically
    void inorderDisplay(Node* node) const {
        if (node == nullptr) return;
        inorderDisplay(node->left);
        node->data.display();
        inorderDisplay(node->right);
    }

    // Store contacts in vector for sorting
    void collectContacts(Node* node, vector<Contact>& contacts) const {
        if (node == nullptr) return;
        collectContacts(node->left, contacts);
        contacts.push_back(node->data);
        collectContacts(node->right, contacts);
    }

    // Find minimum node (for deletion)
    Node* findMin(Node* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    // Delete node helper
    Node* deleteHelper(Node* node, const string& name) {
        if (node == nullptr) return nullptr;

        string nodeName = node->data.getName();
        transform(nodeName.begin(), nodeName.end(), nodeName.begin(), ::tolower);
        string searchName = name;
        transform(searchName.begin(), searchName.end(), searchName.begin(), ::tolower);

        if (searchName < nodeName) {
            node->left = deleteHelper(node->left, name);
        } else if (searchName > nodeName) {
            node->right = deleteHelper(node->right, name);
        } else {
            // Node found
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                totalContacts--;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                totalContacts--;
                return temp;
            }

            // Node with two children
            Node* temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteHelper(node->right, temp->data.getName());
        }
        return node;
    }

    // Destroy tree
    void destroyTree(Node* node) {
        if (node != nullptr) {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
    }

    // Save tree to file
    void saveTreeToFile(Node* node, ofstream& file) const {
        if (node == nullptr) return;
        saveTreeToFile(node->left, file);
        file << node->data.toCSV() << endl;
        saveTreeToFile(node->right, file);
    }

public:
    // Constructor
    ContactBook(string file = "contacts.csv") : root(nullptr), totalContacts(0), filename(file) {
        loadFromFile();
    }

    // Destructor
    ~ContactBook() {
        saveToFile();
        destroyTree(root);
    }

    // Add contact
    bool addContact(const Contact& contact) {
        int prevCount = totalContacts;
        root = insertHelper(root, contact);
        if (totalContacts > prevCount) {
            cout << "\n✅ Contact added successfully!" << endl;
            return true;
        }
        return false;
    }

    // Display all contacts (alphabetically sorted)
    void displayAll() const {
        if (root == nullptr) {
            cout << "\n⚠️  No contacts in the phonebook!" << endl;
            return;
        }

        Contact::displayHeader();
        inorderDisplay(root);
        cout << string(102, '=') << endl;
        cout << "Total Contacts: " << totalContacts << endl;
    }

    // Search by name (prefix matching)
    void searchByName(const string& name) const {
        vector<Contact> allContacts;
        collectContacts(root, allContacts);

        bool found = false;
        Contact::displayHeader();

        for (const auto& contact : allContacts) {
            string contactName = contact.getName();
            transform(contactName.begin(), contactName.end(), contactName.begin(), ::tolower);
            string searchName = name;
            transform(searchName.begin(), searchName.end(), searchName.begin(), ::tolower);

            if (contactName.find(searchName) != string::npos) {
                contact.display();
                found = true;
            }
        }

        if (!found) {
            cout << "\n⚠️  No contact found with name: " << name << endl;
        }
    }

    // Search by phone number
    void searchByPhone(const string& phone) const {
        vector<Contact> allContacts;
        collectContacts(root, allContacts);

        bool found = false;
        Contact::displayHeader();

        for (const auto& contact : allContacts) {
            if (contact.getPhoneNumber().find(phone) != string::npos) {
                contact.display();
                found = true;
            }
        }

        if (!found) {
            cout << "\n⚠️  No contact found with phone: " << phone << endl;
        }
    }

    // Search by category
    void searchByCategory(const string& category) const {
        vector<Contact> allContacts;
        collectContacts(root, allContacts);

        bool found = false;
        Contact::displayHeader();

        for (const auto& contact : allContacts) {
            if (contact.getCategory() == category) {
                contact.display();
                found = true;
            }
        }

        if (!found) {
            cout << "\n⚠️  No contact found in category: " << category << endl;
        }
    }

    // Delete contact by name
    bool deleteContact(const string& name) {
        int prevCount = totalContacts;
        root = deleteHelper(root, name);
        if (totalContacts < prevCount) {
            cout << "\n✅ Contact deleted successfully!" << endl;
            return true;
        }
        cout << "\n❌ Contact not found!" << endl;
        return false;
    }

    // Export to CSV
    void exportToCSV(const string& exportFilename) const {
        ofstream file(exportFilename);
        if (!file.is_open()) {
            cout << "\n❌ Error: Could not create export file!" << endl;
            return;
        }

        file << "Name,Phone,Email,Address,Category" << endl;
        saveTreeToFile(root, file);
        file.close();

        cout << "\n✅ Contacts exported to: " << exportFilename << endl;
    }

    // Save to file
    void saveToFile() const {
        ofstream file(filename);
        if (!file.is_open()) {
            cout << "\n❌ Error: Could not open file for writing!" << endl;
            return;
        }

        saveTreeToFile(root, file);
        file.close();
    }

    // Load from file
    void loadFromFile() {
        ifstream file(filename);
        if (!file.is_open()) {
            return; // File doesn't exist yet
        }

        string line;
        while (getline(file, line)) {
            if (!line.empty()) {
                Contact c = Contact::fromCSV(line);
                root = insertHelper(root, c);
            }
        }

        file.close();
    }

    // Get total contacts
    int getTotalContacts() const {
        return totalContacts;
    }
};

#endif // CONTACTBOOK_H
