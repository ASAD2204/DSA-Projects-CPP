/*
 * ============================================================================
 * StudentManager.h - Student Management System using Linked List
 * ============================================================================
 * Implements CRUD operations, sorting, searching, and file persistence
 * Data Structure: Singly Linked List for dynamic student storage
 * ============================================================================
 */

#ifndef STUDENT_MANAGER_H
#define STUDENT_MANAGER_H

#include "Student.h"
#include <fstream>
#include <algorithm>
#include <vector>

class StudentManager {
private:
    // Node structure for linked list
    struct Node {
        Student data;
        Node* next;
        
        Node(Student s) : data(s), next(nullptr) {}
    };

    Node* head;           // Pointer to first student in list
    int totalStudents;    // Counter for total students
    string filename;      // File for data persistence

public:
    // Constructor - Initialize empty student list
    StudentManager(string file = "students.csv") : head(nullptr), totalStudents(0), filename(file) {
        loadFromFile();
    }

    // Destructor - Clean up memory and save data
    ~StudentManager() {
        saveToFile();
        clearAll();
    }

    // ========== CREATE OPERATION ==========
    // Add new student to the system
    bool addStudent(const Student& student) {
        // Check if roll number already exists
        if (searchByRollNumber(student.getRollNumber()) != nullptr) {
            cout << "\n❌ Error: Student with Roll Number " << student.getRollNumber() 
                 << " already exists!" << endl;
            return false;
        }

        Node* newNode = new Node(student);
        
        // Insert at head for O(1) insertion
        if (head == nullptr) {
            head = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
        
        totalStudents++;
        cout << "\n✅ Student added successfully!" << endl;
        return true;
    }

    // ========== READ OPERATIONS ==========
    // Display all students
    void displayAll() const {
        if (head == nullptr) {
            cout << "\n⚠️  No students in the system!" << endl;
            return;
        }

        Student::displayHeader();
        Node* temp = head;
        while (temp != nullptr) {
            temp->data.display();
            temp = temp->next;
        }
        cout << string(95, '=') << endl;
        cout << "Total Students: " << totalStudents << endl;
    }

    // Search student by roll number
    Node* searchByRollNumber(int rollNumber) const {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data.getRollNumber() == rollNumber) {
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }

    // Search students by name (partial match)
    void searchByName(const string& name) const {
        bool found = false;
        Node* temp = head;

        Student::displayHeader();
        while (temp != nullptr) {
            // Case-insensitive search
            string studentName = temp->data.getName();
            transform(studentName.begin(), studentName.end(), studentName.begin(), ::tolower);
            string searchName = name;
            transform(searchName.begin(), searchName.end(), searchName.begin(), ::tolower);

            if (studentName.find(searchName) != string::npos) {
                temp->data.display();
                found = true;
            }
            temp = temp->next;
        }

        if (!found) {
            cout << "\n⚠️  No student found with name: " << name << endl;
        }
    }

    // Search students by department
    void searchByDepartment(const string& dept) const {
        bool found = false;
        Node* temp = head;

        Student::displayHeader();
        while (temp != nullptr) {
            if (temp->data.getDepartment() == dept) {
                temp->data.display();
                found = true;
            }
            temp = temp->next;
        }

        if (!found) {
            cout << "\n⚠️  No student found in department: " << dept << endl;
        }
    }

    // ========== UPDATE OPERATION ==========
    // Update student information
    bool updateStudent(int rollNumber) {
        Node* node = searchByRollNumber(rollNumber);
        
        if (node == nullptr) {
            cout << "\n❌ Student with Roll Number " << rollNumber << " not found!" << endl;
            return false;
        }

        cout << "\n📝 Current Student Details:" << endl;
        Student::displayHeader();
        node->data.display();

        cout << "\n🔄 Enter new details (press Enter to keep current value):" << endl;
        
        string input;
        cin.ignore();

        cout << "Name [" << node->data.getName() << "]: ";
        getline(cin, input);
        if (!input.empty()) node->data.setName(input);

        cout << "Department [" << node->data.getDepartment() << "]: ";
        getline(cin, input);
        if (!input.empty()) node->data.setDepartment(input);

        cout << "GPA [" << node->data.getGPA() << "]: ";
        getline(cin, input);
        if (!input.empty()) node->data.setGPA(stof(input));

        cout << "Contact [" << node->data.getContactNumber() << "]: ";
        getline(cin, input);
        if (!input.empty()) node->data.setContactNumber(input);

        cout << "Email [" << node->data.getEmail() << "]: ";
        getline(cin, input);
        if (!input.empty()) node->data.setEmail(input);

        cout << "\n✅ Student record updated successfully!" << endl;
        return true;
    }

    // ========== DELETE OPERATION ==========
    // Delete student by roll number
    bool deleteStudent(int rollNumber) {
        if (head == nullptr) {
            cout << "\n⚠️  No students to delete!" << endl;
            return false;
        }

        // Special case: deleting head node
        if (head->data.getRollNumber() == rollNumber) {
            Node* temp = head;
            head = head->next;
            delete temp;
            totalStudents--;
            cout << "\n✅ Student deleted successfully!" << endl;
            return true;
        }

        // Search for node to delete
        Node* current = head;
        Node* previous = nullptr;

        while (current != nullptr && current->data.getRollNumber() != rollNumber) {
            previous = current;
            current = current->next;
        }

        if (current == nullptr) {
            cout << "\n❌ Student with Roll Number " << rollNumber << " not found!" << endl;
            return false;
        }

        previous->next = current->next;
        delete current;
        totalStudents--;
        cout << "\n✅ Student deleted successfully!" << endl;
        return true;
    }

    // ========== SORTING OPERATIONS ==========
    // Sort students by roll number using Bubble Sort
    void sortByRollNumber() {
        if (head == nullptr || head->next == nullptr) return;

        bool swapped;
        Node* ptr;
        Node* lptr = nullptr;

        do {
            swapped = false;
            ptr = head;

            while (ptr->next != lptr) {
                if (ptr->data.getRollNumber() > ptr->next->data.getRollNumber()) {
                    swap(ptr->data, ptr->next->data);
                    swapped = true;
                }
                ptr = ptr->next;
            }
            lptr = ptr;
        } while (swapped);

        cout << "\n✅ Students sorted by Roll Number!" << endl;
    }

    // Sort students by name using Bubble Sort
    void sortByName() {
        if (head == nullptr || head->next == nullptr) return;

        bool swapped;
        Node* ptr;
        Node* lptr = nullptr;

        do {
            swapped = false;
            ptr = head;

            while (ptr->next != lptr) {
                if (ptr->data.getName() > ptr->next->data.getName()) {
                    swap(ptr->data, ptr->next->data);
                    swapped = true;
                }
                ptr = ptr->next;
            }
            lptr = ptr;
        } while (swapped);

        cout << "\n✅ Students sorted by Name!" << endl;
    }

    // Sort students by GPA (descending) using Bubble Sort
    void sortByGPA() {
        if (head == nullptr || head->next == nullptr) return;

        bool swapped;
        Node* ptr;
        Node* lptr = nullptr;

        do {
            swapped = false;
            ptr = head;

            while (ptr->next != lptr) {
                if (ptr->data.getGPA() < ptr->next->data.getGPA()) {
                    swap(ptr->data, ptr->next->data);
                    swapped = true;
                }
                ptr = ptr->next;
            }
            lptr = ptr;
        } while (swapped);

        cout << "\n✅ Students sorted by GPA (Highest to Lowest)!" << endl;
    }

    // ========== STATISTICS ==========
    // Display statistics about students
    void displayStatistics() const {
        if (head == nullptr) {
            cout << "\n⚠️  No students to analyze!" << endl;
            return;
        }

        float totalGPA = 0;
        float maxGPA = 0;
        float minGPA = 4.0;
        Node* temp = head;

        while (temp != nullptr) {
            float gpa = temp->data.getGPA();
            totalGPA += gpa;
            if (gpa > maxGPA) maxGPA = gpa;
            if (gpa < minGPA) minGPA = gpa;
            temp = temp->next;
        }

        cout << "\n📊 Student Statistics:" << endl;
        cout << string(50, '=') << endl;
        cout << "Total Students: " << totalStudents << endl;
        cout << "Average GPA: " << fixed << setprecision(2) << (totalGPA / totalStudents) << endl;
        cout << "Highest GPA: " << maxGPA << endl;
        cout << "Lowest GPA: " << minGPA << endl;
        cout << string(50, '=') << endl;
    }

    // ========== FILE OPERATIONS ==========
    // Save all students to file
    void saveToFile() const {
        ofstream file(filename);
        if (!file.is_open()) {
            cout << "\n❌ Error: Could not open file for writing!" << endl;
            return;
        }

        Node* temp = head;
        while (temp != nullptr) {
            file << temp->data.toCSV() << endl;
            temp = temp->next;
        }

        file.close();
    }

    // Load students from file
    void loadFromFile() {
        ifstream file(filename);
        if (!file.is_open()) {
            // File doesn't exist yet, that's okay
            return;
        }

        string line;
        while (getline(file, line)) {
            if (!line.empty()) {
                Student s = Student::fromCSV(line);
                Node* newNode = new Node(s);
                newNode->next = head;
                head = newNode;
                totalStudents++;
            }
        }

        file.close();
    }

    // Get total number of students
    int getTotalStudents() const {
        return totalStudents;
    }

private:
    // Clear all students from memory
    void clearAll() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        totalStudents = 0;
    }
};

#endif // STUDENT_MANAGER_H
