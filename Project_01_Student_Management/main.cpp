/*
 * ============================================================================
 * PROJECT #1: STUDENT RECORD MANAGEMENT SYSTEM
 * ============================================================================
 * Author: [Your Name]
 * Course: Data Structures & Algorithms
 * 
 * Description:
 *   A comprehensive student management system using linked list data structure.
 *   Supports CRUD operations, multiple sorting options, search functionality,
 *   and persistent file storage.
 * 
 * Features:
 *   ✅ Add new student records
 *   ✅ View all students
 *   ✅ Search by roll number, name, or department
 *   ✅ Update student information
 *   ✅ Delete student records
 *   ✅ Sort by roll number, name, or GPA
 *   ✅ Display statistics (average GPA, etc.)
 *   ✅ Automatic save/load from CSV file
 * 
 * Data Structure Used:
 *   Singly Linked List - for dynamic student storage
 * 
 * Time Complexity:
 *   Insert: O(1)
 *   Delete: O(n)
 *   Search: O(n)
 *   Sort: O(n²) - Bubble Sort
 * 
 * ============================================================================
 */

#include "StudentManager.h"
#include <iostream>
#include <limits>
using namespace std;

// Function to clear input buffer
void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Function to display main menu
void displayMenu() {
    cout << "\n";
    cout << "\n========================================================\n";
    cout << "        STUDENT RECORD MANAGEMENT SYSTEM                \n";
    cout << "========================================================\n";
    cout << "\n";
    cout << "  📝 STUDENT OPERATIONS:\n";
    cout << "    1. Add New Student\n";
    cout << "    2. Display All Students\n";
    cout << "    3. Search Student\n";
    cout << "    4. Update Student\n";
    cout << "    5. Delete Student\n";
    cout << "\n";
    cout << "  📊 SORTING & ANALYSIS:\n";
    cout << "    6. Sort by Roll Number\n";
    cout << "    7. Sort by Name\n";
    cout << "    8. Sort by GPA\n";
    cout << "    9. Display Statistics\n";
    cout << "\n";
    cout << "  💾 FILE OPERATIONS:\n";
    cout << "    10. Save & Exit\n";
    cout << "\n";
    cout << "  Enter your choice: ";
}

// Function to handle search submenu
void searchMenu(StudentManager& manager) {
    int searchChoice;
    cout << "\n";
    cout << "  🔍 SEARCH OPTIONS:\n";
    cout << "    1. Search by Roll Number\n";
    cout << "    2. Search by Name\n";
    cout << "    3. Search by Department\n";
    cout << "    4. Back to Main Menu\n";
    cout << "\n  Enter choice: ";
    cin >> searchChoice;

    switch(searchChoice) {
        case 1: {
            int roll;
            cout << "\n  Enter Roll Number: ";
            cin >> roll;
            auto node = manager.searchByRollNumber(roll);
            if (node != nullptr) {
                Student::displayHeader();
                node->data.display();
            } else {
                cout << "\n  ❌ Student not found!" << endl;
            }
            break;
        }
        case 2: {
            string name;
            cout << "\n  Enter Name (or part of name): ";
            cin.ignore();
            getline(cin, name);
            manager.searchByName(name);
            break;
        }
        case 3: {
            string dept;
            cout << "\n  Enter Department: ";
            cin.ignore();
            getline(cin, dept);
            manager.searchByDepartment(dept);
            break;
        }
        case 4:
            return;
        default:
            cout << "\n  ❌ Invalid choice!" << endl;
    }
}

// Function to add sample data for testing
void addSampleData(StudentManager& manager) {
    cout << "\n  📥 Adding sample student data..." << endl;
    
    manager.addStudent(Student(101, "Alice Johnson", "Computer Science", 3.8, "555-0101", "alice@university.edu"));
    manager.addStudent(Student(102, "Bob Smith", "Electrical Engineering", 3.5, "555-0102", "bob@university.edu"));
    manager.addStudent(Student(103, "Charlie Brown", "Computer Science", 3.9, "555-0103", "charlie@university.edu"));
    manager.addStudent(Student(104, "Diana Prince", "Mechanical Engineering", 3.7, "555-0104", "diana@university.edu"));
    manager.addStudent(Student(105, "Eve Wilson", "Computer Science", 4.0, "555-0105", "eve@university.edu"));
    
    cout << "\n  ✅ Sample data added successfully!" << endl;
}

int main() {
    StudentManager manager("students.csv");
    int choice;
    bool running = true;

    // Welcome message
    cout << "\n";
    cout << "╔════════════════════════════════════════════════════════╗\n";
    cout << "║                    WELCOME TO                          ║\n";
    cout << "║       STUDENT RECORD MANAGEMENT SYSTEM                ║\n";
    cout << "╚════════════════════════════════════════════════════════╝\n";

    // Check if there are existing students
    if (manager.getTotalStudents() > 0) {
        cout << "\n  ℹ️  Loaded " << manager.getTotalStudents() << " student(s) from file.\n";
    } else {
        char addSample;
        cout << "\n  No existing student records found.";
        cout << "\n  Would you like to add sample data for testing? (y/n): ";
        cin >> addSample;
        if (addSample == 'y' || addSample == 'Y') {
            addSampleData(manager);
        }
    }

    // Main application loop
    while (running) {
        displayMenu();
        cin >> choice;

        switch(choice) {
            case 1: {
                // Add New Student
                int roll;
                string name, dept, contact, email;
                float gpa;

                cout << "\n  ➕ ADD NEW STUDENT\n";
                cout << "  " << string(50, '-') << endl;
                
                cout << "  Roll Number: ";
                cin >> roll;
                
                cin.ignore();
                cout << "  Name: ";
                getline(cin, name);
                
                cout << "  Department: ";
                getline(cin, dept);
                
                cout << "  GPA (0.0 - 4.0): ";
                cin >> gpa;
                
                cin.ignore();
                cout << "  Contact Number: ";
                getline(cin, contact);
                
                cout << "  Email: ";
                getline(cin, email);

                Student newStudent(roll, name, dept, gpa, contact, email);
                manager.addStudent(newStudent);
                break;
            }

            case 2:
                // Display All Students
                cout << "\n  📋 ALL STUDENT RECORDS\n";
                manager.displayAll();
                break;

            case 3:
                // Search Student
                searchMenu(manager);
                break;

            case 4: {
                // Update Student
                int roll;
                cout << "\n  🔄 UPDATE STUDENT RECORD\n";
                cout << "  Enter Roll Number to update: ";
                cin >> roll;
                manager.updateStudent(roll);
                break;
            }

            case 5: {
                // Delete Student
                int roll;
                char confirm;
                cout << "\n  🗑️  DELETE STUDENT RECORD\n";
                cout << "  Enter Roll Number to delete: ";
                cin >> roll;
                
                // Show student before deleting
                auto node = manager.searchByRollNumber(roll);
                if (node != nullptr) {
                    Student::displayHeader();
                    node->data.display();
                    cout << "\n  Are you sure you want to delete this student? (y/n): ";
                    cin >> confirm;
                    if (confirm == 'y' || confirm == 'Y') {
                        manager.deleteStudent(roll);
                    } else {
                        cout << "\n  ❌ Deletion cancelled." << endl;
                    }
                } else {
                    cout << "\n  ❌ Student not found!" << endl;
                }
                break;
            }

            case 6:
                // Sort by Roll Number
                manager.sortByRollNumber();
                manager.displayAll();
                break;

            case 7:
                // Sort by Name
                manager.sortByName();
                manager.displayAll();
                break;

            case 8:
                // Sort by GPA
                manager.sortByGPA();
                manager.displayAll();
                break;

            case 9:
                // Display Statistics
                manager.displayStatistics();
                break;

            case 10:
                // Save & Exit
                cout << "\n  💾 Saving data..." << endl;
                manager.saveToFile();
                cout << "\n";
                cout << "  ╔════════════════════════════════════════════╗\n";
                cout << "  ║   Thank you for using the system!          ║\n";
                cout << "  ║   Data saved successfully.                 ║\n";
                cout << "  ╚════════════════════════════════════════════╝\n";
                cout << "\n";
                running = false;
                break;

            default:
                cout << "\n  ❌ Invalid choice! Please try again." << endl;
                clearInputBuffer();
        }

        // Pause before showing menu again (except on exit)
        if (running && choice >= 1 && choice <= 10) {
            cout << "\n  Press Enter to continue...";
            clearInputBuffer();
            cin.get();
        }
    }

    return 0;
}
