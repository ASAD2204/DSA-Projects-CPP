/*
 * ============================================================================
 * Contact.h - Contact Class Definition
 * ============================================================================
 * Defines the Contact class with all contact attributes and operations
 * ============================================================================
 */

#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Contact {
private:
    string name;
    string phoneNumber;
    string email;
    string address;
    string category;  // Family, Friends, Work, etc.

public:
    // Default Constructor
    Contact() : name(""), phoneNumber(""), email(""), address(""), category("General") {}

    // Parameterized Constructor
    Contact(string n, string phone, string mail, string addr, string cat = "General")
        : name(n), phoneNumber(phone), email(mail), address(addr), category(cat) {}

    // Getters
    string getName() const { return name; }
    string getPhoneNumber() const { return phoneNumber; }
    string getEmail() const { return email; }
    string getAddress() const { return address; }
    string getCategory() const { return category; }

    // Setters
    void setName(string n) { name = n; }
    void setPhoneNumber(string phone) { phoneNumber = phone; }
    void setEmail(string mail) { email = mail; }
    void setAddress(string addr) { address = addr; }
    void setCategory(string cat) { category = cat; }

    // Display contact in formatted way
    void display() const {
        cout << left << setw(20) << name
             << setw(15) << phoneNumber
             << setw(25) << email
             << setw(30) << address
             << setw(12) << category << endl;
    }

    // Display header for contact table
    static void displayHeader() {
        cout << "\n" << string(102, '=') << endl;
        cout << left << setw(20) << "Name"
             << setw(15) << "Phone"
             << setw(25) << "Email"
             << setw(30) << "Address"
             << setw(12) << "Category" << endl;
        cout << string(102, '=') << endl;
    }

    // Convert to CSV format
    string toCSV() const {
        return name + "," + phoneNumber + "," + email + "," + address + "," + category;
    }

    // Create Contact from CSV string
    static Contact fromCSV(const string& csvLine) {
        Contact c;
        size_t found;
        string line = csvLine;
        int field = 0;

        while ((found = line.find(',')) != string::npos) {
            string token = line.substr(0, found);
            switch(field) {
                case 0: c.name = token; break;
                case 1: c.phoneNumber = token; break;
                case 2: c.email = token; break;
                case 3: c.address = token; break;
            }
            line.erase(0, found + 1);
            field++;
        }
        c.category = line; // Last field
        return c;
    }
};

#endif // CONTACT_H
