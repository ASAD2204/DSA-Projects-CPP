# 📚 Project #1: Student Record Management System

A comprehensive command-line application for managing student records using **Singly Linked List** data structure.

## 🎯 Project Overview

This system demonstrates efficient CRUD (Create, Read, Update, Delete) operations on student records with additional features like sorting, searching, and persistent file storage.

## ✨ Features

### Core Operations
- ✅ **Add Student** - Insert new student records
- ✅ **View All Students** - Display complete student list
- ✅ **Search Student** - Find by roll number, name, or department
- ✅ **Update Student** - Modify existing student information
- ✅ **Delete Student** - Remove student records with confirmation

### Advanced Features
- 📊 **Multiple Sorting Options**
  - Sort by Roll Number
  - Sort by Name (Alphabetical)
  - Sort by GPA (Descending)
- 📈 **Statistics Dashboard**
  - Total students count
  - Average GPA calculation
  - Highest/Lowest GPA tracking
- 💾 **File Persistence**
  - Auto-save to CSV file
  - Auto-load on startup
  - Data preservation between sessions

## 🗂️ Data Structure Used

**Singly Linked List**
- Dynamic memory allocation
- Efficient insertion at head: O(1)
- Flexible size management
- No pre-defined capacity limit

## ⚡ Time Complexity Analysis

| Operation | Time Complexity | Space Complexity |
|-----------|----------------|------------------|
| Insert (Add Student) | O(1) | O(1) |
| Search by Roll Number | O(n) | O(1) |
| Delete Student | O(n) | O(1) |
| Display All | O(n) | O(1) |
| Sort (Bubble Sort) | O(n²) | O(1) |
| Update Student | O(n) | O(1) |

## 📁 File Structure

```
Project_01_Student_Management/
├── Student.h              # Student class definition
├── StudentManager.h       # Student management with linked list
├── main.cpp              # Main application with menu interface
├── README.md             # This file
└── students.csv          # Data file (auto-generated)
```

## 🚀 Compilation & Execution

### Windows (PowerShell)
```powershell
cd "Project_01_Student_Management"
g++ -o student_system main.cpp -std=c++11
.\student_system.exe
```

### Linux/Mac
```bash
cd Project_01_Student_Management
g++ -o student_system main.cpp -std=c++11
./student_system
```

## 📖 Usage Guide

### Adding a Student
1. Select option `1` from main menu
2. Enter student details:
   - Roll Number (unique)
   - Name
   - Department
   - GPA (0.0 - 4.0)
   - Contact Number
   - Email

### Searching for Students
1. Select option `3` - Search Student
2. Choose search type:
   - By Roll Number (exact match)
   - By Name (partial match supported)
   - By Department (exact match)

### Updating Student Records
1. Select option `4` - Update Student
2. Enter roll number
3. Enter new values (press Enter to keep current value)

### Sorting Options
- **Option 6**: Sort by Roll Number (ascending)
- **Option 7**: Sort by Name (alphabetical)
- **Option 8**: Sort by GPA (highest to lowest)

## 💡 Sample Data

The system includes sample data for testing:
- 5 pre-defined students
- Different departments (CS, EE, ME)
- Varied GPA ranges (3.5 - 4.0)

## 🎓 Learning Outcomes

### Data Structures Concepts
- ✅ Linked List implementation
- ✅ Node creation and manipulation
- ✅ Dynamic memory management
- ✅ Pointer traversal

### Algorithm Concepts
- ✅ Bubble Sort implementation
- ✅ Linear search
- ✅ CRUD operations
- ✅ File I/O operations

### Software Engineering
- ✅ Class design and encapsulation
- ✅ Separation of concerns
- ✅ User input validation
- ✅ Error handling

## 🔍 Code Highlights

### Efficient Insertion (O(1))
```cpp
// Insert at head for constant time
Node* newNode = new Node(student);
newNode->next = head;
head = newNode;
```

### Bubble Sort for Linked List
```cpp
// In-place sorting without extra array
while (ptr->next != lptr) {
    if (ptr->data.getRollNumber() > ptr->next->data.getRollNumber()) {
        swap(ptr->data, ptr->next->data);
    }
    ptr = ptr->next;
}
```

### CSV File Format
```csv
101,Alice Johnson,Computer Science,3.80,555-0101,alice@university.edu
102,Bob Smith,Electrical Engineering,3.50,555-0102,bob@university.edu
```

## 🐛 Error Handling

- ✅ Duplicate roll number prevention
- ✅ Invalid input validation
- ✅ File I/O error handling
- ✅ Empty list operations
- ✅ Confirmation prompts for destructive operations

## 🎯 Future Enhancements

- [ ] Add GPA validation (0.0 - 4.0 range)
- [ ] Implement export to different formats (JSON, XML)
- [ ] Add course enrollment tracking
- [ ] Implement attendance management
- [ ] Add photo upload support
- [ ] Generate student report cards
- [ ] Add bulk import from CSV
- [ ] Implement undo/redo functionality

## 📊 Testing Checklist

- [x] Add student with valid data
- [x] Add student with duplicate roll number (should fail)
- [x] Search by roll number
- [x] Search by partial name
- [x] Update student information
- [x] Delete student with confirmation
- [x] Sort by all three criteria
- [x] View statistics
- [x] Save and reload data
- [x] Handle empty database

## 🏆 Interview Relevance

This project demonstrates:
- **Linked List mastery** - Common interview data structure
- **CRUD operations** - Real-world application development
- **File handling** - Data persistence
- **Sorting algorithms** - Algorithm implementation
- **Menu-driven programming** - User interface design
- **Memory management** - Pointer handling and cleanup

## 👨‍💻 Author

Created as part of DSA course - 4th Semester BS IT

## 📄 License

Free to use for educational purposes.

---

**Last Updated**: November 2025
