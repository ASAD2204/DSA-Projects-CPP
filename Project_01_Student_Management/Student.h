/*
 * ============================================================================
 * Student.h - Student Record Class Definition
 * ============================================================================
 * Defines the Student class with all student attributes and operations
 * ============================================================================
 */

#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Student {
private:
    int rollNumber;
    string name;
    string department;
    float gpa;
    string contactNumber;
    string email;

public:
    // Constructor - Initialize student with default values
    Student() : rollNumber(0), name(""), department(""), gpa(0.0), contactNumber(""), email("") {}

    // Parameterized Constructor - Create student with provided details
    Student(int roll, string n, string dept, float g, string contact, string mail) 
        : rollNumber(roll), name(n), department(dept), gpa(g), contactNumber(contact), email(mail) {}

    // Getters - Retrieve student information
    int getRollNumber() const { return rollNumber; }
    string getName() const { return name; }
    string getDepartment() const { return department; }
    float getGPA() const { return gpa; }
    string getContactNumber() const { return contactNumber; }
    string getEmail() const { return email; }

    // Setters - Update student information
    void setRollNumber(int roll) { rollNumber = roll; }
    void setName(string n) { name = n; }
    void setDepartment(string dept) { department = dept; }
    void setGPA(float g) { gpa = g; }
    void setContactNumber(string contact) { contactNumber = contact; }
    void setEmail(string mail) { email = mail; }

    // Display student details in formatted way
    void display() const {
        cout << left << setw(10) << rollNumber 
             << setw(20) << name 
             << setw(15) << department 
             << setw(8) << fixed << setprecision(2) << gpa 
             << setw(15) << contactNumber 
             << setw(25) << email << endl;
    }

    // Display header for student table
    static void displayHeader() {
        cout << "\n" << string(95, '=') << endl;
        cout << left << setw(10) << "Roll No" 
             << setw(20) << "Name" 
             << setw(15) << "Department" 
             << setw(8) << "GPA" 
             << setw(15) << "Contact" 
             << setw(25) << "Email" << endl;
        cout << string(95, '=') << endl;
    }

    // Convert student data to CSV format for file storage
    string toCSV() const {
        return to_string(rollNumber) + "," + name + "," + department + "," + 
               to_string(gpa) + "," + contactNumber + "," + email;
    }

    // Create student object from CSV string
    static Student fromCSV(const string& csvLine) {
        Student s;
        size_t pos = 0;
        size_t found;
        string token;
        int field = 0;

        string line = csvLine;
        while ((found = line.find(',')) != string::npos) {
            token = line.substr(0, found);
            switch(field) {
                case 0: s.rollNumber = stoi(token); break;
                case 1: s.name = token; break;
                case 2: s.department = token; break;
                case 3: s.gpa = stof(token); break;
                case 4: s.contactNumber = token; break;
            }
            line.erase(0, found + 1);
            field++;
        }
        s.email = line; // Last field
        return s;
    }
};

#endif // STUDENT_H
