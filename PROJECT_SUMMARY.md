# 🎓 DSA PROJECTS - COMPLETE SUMMARY
**10 Beginner to Intermediate Data Structures & Algorithms Projects**

---

## 📋 PROJECT OVERVIEW

All projects are implemented in **C++** with proper comments, menu-driven interfaces, and real-world applications. Each project demonstrates specific data structures and algorithms that are commonly asked in technical interviews.

---

## ✅ ALL PROJECTS COMPLETED

### **Project #1: Student Management System**
- **📁 Folder:** `Project_01_Student_Management/`
- **📊 Data Structure:** Singly Linked List
- **✨ Features:**
  - Add, update, delete students
  - Search by ID or name
  - Sort students by marks (Bubble Sort)
  - Save/load from CSV file
  - Display all students
- **🎯 Learning Outcomes:**
  - Linked list operations (insert, delete, traverse)
  - File I/O in C++
  - Sorting algorithms
- **⏱️ Time Complexity:**
  - Insert: O(1)
  - Search: O(n)
  - Delete: O(n)
  - Sort: O(n²)
- **🔨 Compile:** `g++ -std=c++11 main.cpp -o student_manager`

---

### **Project #2: Contact Book**
- **📁 Folder:** `Project_02_Contact_Book/`
- **📊 Data Structure:** Binary Search Tree (BST)
- **✨ Features:**
  - Add contacts (auto-sorted alphabetically)
  - Search by name (exact or prefix)
  - Display in alphabetical order (Inorder Traversal)
  - Export to CSV
  - Delete contacts
- **🎯 Learning Outcomes:**
  - BST implementation
  - Tree traversal (inorder, preorder, postorder)
  - Prefix-based searching
- **⏱️ Time Complexity:**
  - Insert: O(log n) average, O(n) worst
  - Search: O(log n) average, O(n) worst
  - Delete: O(log n) average, O(n) worst
- **🔨 Compile:** `g++ -std=c++11 main.cpp -o contact_book`

---

### **Project #3: ToDo List with Priority**
- **📁 Folder:** `Project_03_ToDo_Priority/`
- **📊 Data Structure:** Min Heap (Priority Queue)
- **✨ Features:**
  - Add tasks with priority (1=High, 2=Med, 3=Low)
  - View next task (highest priority)
  - Complete task (removes from heap)
  - View all pending tasks
  - Tasks auto-sorted by priority
- **🎯 Learning Outcomes:**
  - Min Heap implementation
  - Heapify operations (bubble up, bubble down)
  - Priority queue applications
- **⏱️ Time Complexity:**
  - Insert: O(log n)
  - Extract Min: O(log n)
  - Peek: O(1)
- **🔨 Compile:** `g++ -std=c++11 main.cpp -o todo_manager`

---

### **Project #4: Parentheses Checker**
- **📁 Folder:** `Project_04_Parentheses_Checker/`
- **📊 Data Structure:** Stack
- **✨ Features:**
  - Validate balanced parentheses/brackets/braces
  - Detects mismatched, missing, or extra brackets
  - Shows error position
  - Supports: `( ) { } [ ]`
  - Test with sample expressions
- **🎯 Learning Outcomes:**
  - Stack operations (push, pop, peek)
  - Expression validation
  - String parsing
- **⏱️ Time Complexity:**
  - Validation: O(n)
  - Space: O(n)
- **🔨 Compile:** `g++ -std=c++11 main.cpp -o paren_checker`

---

### **Project #5: Text Editor with Undo/Redo**
- **📁 Folder:** `Project_05_Text_Editor/`
- **📊 Data Structure:** Two Stacks (Undo Stack + Redo Stack)
- **✨ Features:**
  - Insert text at any position
  - Delete text (characters or ranges)
  - Undo/Redo functionality
  - Copy/Paste (clipboard)
  - Clear document
  - Display text with line numbers
- **🎯 Learning Outcomes:**
  - Stack-based state management
  - Undo/Redo pattern implementation
  - String manipulation
- **⏱️ Time Complexity:**
  - Insert/Delete: O(n)
  - Undo/Redo: O(1)
- **🔨 Compile:** `g++ -std=c++11 main.cpp -o text_editor`

---

### **Project #6: Playlist Manager**
- **📁 Folder:** `Project_06_Playlist_Manager/`
- **📊 Data Structure:** Queue + Stack
- **✨ Features:**
  - Play queue (FIFO)
  - Recently played history (Stack)
  - Shuffle mode
  - Repeat mode
  - Next/Previous song navigation
  - Song library management
- **🎯 Learning Outcomes:**
  - Queue operations (enqueue, dequeue)
  - Combining multiple data structures
  - Music player algorithms
- **⏱️ Time Complexity:**
  - Enqueue/Dequeue: O(1)
  - Shuffle: O(n)
- **🔨 Compile:** `g++ -std=c++11 main.cpp -o playlist_manager`

---

### **Project #7: Library Book Management**
- **📁 Folder:** `Project_07_Library_Management/`
- **📊 Data Structure:** BST (catalog) + Priority Queue (issue requests)
- **✨ Features:**
  - Add books to catalog
  - Search by title or ID
  - Issue/return books
  - Track available copies
  - Priority-based waiting list
  - Auto-issue when book returned
- **🎯 Learning Outcomes:**
  - Combining BST with Priority Queue
  - Real-world inventory management
  - Request queuing system
- **⏱️ Time Complexity:**
  - Add/Search: O(log n)
  - Issue/Return: O(log n)
- **🔨 Compile:** `g++ -std=c++11 main.cpp -o library_manager`

---

### **Project #8: Maze Solver & Generator**
- **📁 Folder:** `Project_08_Maze_Solver/`
- **📊 Data Structure:** Graph (Adjacency Matrix), BFS, DFS
- **✨ Features:**
  - Generate random mazes
  - Solve using BFS (shortest path)
  - Solve using DFS (depth-first exploration)
  - Visualize solution path
  - Custom maze input
  - Compare BFS vs DFS performance
- **🎯 Learning Outcomes:**
  - Graph representation
  - BFS and DFS algorithms
  - Path finding algorithms
  - Visual representation of algorithms
- **⏱️ Time Complexity:**
  - BFS: O(V + E)
  - DFS: O(V + E)
  - Space: O(V)
- **🔨 Compile:** `g++ -std=c++11 main.cpp -o maze_solver`

---

### **Project #9: Sorting Algorithm Visualizer**
- **📁 Folder:** `Project_09_Sorting_Visualizer/`
- **📊 Data Structure:** Arrays
- **✨ Features:**
  - 6 Sorting Algorithms:
    1. Bubble Sort
    2. Selection Sort
    3. Insertion Sort
    4. Merge Sort
    5. Quick Sort
    6. Heap Sort
  - Step-by-step visualization
  - Performance metrics (comparisons, swaps)
  - Random array generation
  - Manual input option
- **🎯 Learning Outcomes:**
  - All major sorting algorithms
  - Time complexity analysis
  - Algorithm visualization
  - Performance comparison
- **⏱️ Time Complexity:**
  - Bubble/Selection/Insertion: O(n²)
  - Merge/Heap: O(n log n)
  - Quick: O(n log n) average, O(n²) worst
- **🔨 Compile:** `g++ -std=c++11 main.cpp -o sorting_visualizer`

---

### **Project #10: Word Frequency Counter & Analyzer**
- **📁 Folder:** `Project_10_Word_Analyzer/`
- **📊 Data Structure:** Hash Map (unordered_map) + Priority Queue (Heap)
- **✨ Features:**
  - Count word frequencies
  - Top K most frequent words
  - Least K frequent words
  - Word search with percentage
  - Load from text file
  - Statistics (total words, unique words, averages)
  - Case-insensitive, removes punctuation
- **🎯 Learning Outcomes:**
  - Hash Map for O(1) lookups
  - Heap for top-K problems
  - Text processing algorithms
  - Statistical analysis
- **⏱️ Time Complexity:**
  - Insert/Search: O(1) average
  - Top K: O(n log k)
- **🔨 Compile:** `g++ -std=c++11 main.cpp -o word_analyzer`

---

## 📚 DATA STRUCTURES COVERED

| Data Structure | Projects |
|----------------|----------|
| Singly Linked List | #1 Student Management |
| Binary Search Tree | #2 Contact Book, #7 Library |
| Min Heap | #3 ToDo Priority, #7 Library |
| Stack | #4 Parentheses, #5 Text Editor, #6 Playlist |
| Queue | #6 Playlist Manager |
| Priority Queue | #3, #7, #10 |
| Graph (Matrix) | #8 Maze Solver |
| Arrays | #9 Sorting Visualizer |
| Hash Map | #10 Word Analyzer |

---

## 🔍 ALGORITHMS COVERED

| Algorithm | Projects |
|-----------|----------|
| Bubble Sort | #1, #9 |
| Selection Sort | #9 |
| Insertion Sort | #9 |
| Merge Sort | #9 |
| Quick Sort | #9 |
| Heap Sort | #9 |
| BFS (Breadth-First) | #8 |
| DFS (Depth-First) | #8 |
| Heapify | #3, #9 |
| BST Operations | #2, #7 |
| Hashing | #10 |

---

## 🚀 HOW TO COMPILE & RUN

### Compile Individual Project:
```bash
cd Project_XX_Name
g++ -std=c++11 main.cpp -o output_name
./output_name
```

### Compile All Projects (PowerShell):
```powershell
# Navigate to project directory
cd "F:\BS IT\4th Semester\DSA_Projects"

# Compile each project
cd Project_01_Student_Management; g++ -std=c++11 main.cpp -o student_manager; cd ..
cd Project_02_Contact_Book; g++ -std=c++11 main.cpp -o contact_book; cd ..
cd Project_03_ToDo_Priority; g++ -std=c++11 main.cpp -o todo_manager; cd ..
cd Project_04_Parentheses_Checker; g++ -std=c++11 main.cpp -o paren_checker; cd ..
cd Project_05_Text_Editor; g++ -std=c++11 main.cpp -o text_editor; cd ..
cd Project_06_Playlist_Manager; g++ -std=c++11 main.cpp -o playlist_manager; cd ..
cd Project_07_Library_Management; g++ -std=c++11 main.cpp -o library_manager; cd ..
cd Project_08_Maze_Solver; g++ -std=c++11 main.cpp -o maze_solver; cd ..
cd Project_09_Sorting_Visualizer; g++ -std=c++11 main.cpp -o sorting_visualizer; cd ..
cd Project_10_Word_Analyzer; g++ -std=c++11 main.cpp -o word_analyzer; cd ..
```

---


## 📊 DIFFICULTY PROGRESSION

| Level | Projects |
|-------|----------|
| **Beginner** | #1, #4, #5 |
| **Intermediate** | #2, #3, #6, #9 |
| **Advanced** | #7, #8, #10 |

---

## 🛠️ TECH STACK

- **Language:** C++11
- **Compiler:** g++ (MinGW/GCC)
- **Libraries Used:**
  - `<iostream>` - Input/Output
  - `<fstream>` - File handling
  - `<string>` - String operations
  - `<vector>` - Dynamic arrays
  - `<queue>` - Queue/Priority Queue
  - `<stack>` - Stack operations
  - `<unordered_map>` - Hash Map
  - `<algorithm>` - Sorting/Searching
  - `<ctime>` - Random generation

---

## 📂 PROJECT STRUCTURE

```
DSA_Projects/
├── dsa.h (Comprehensive DSA library)
├── test_dsa.cpp (Test suite for dsa.h)
├── README.md (Library documentation)
├── PROJECT_SUMMARY.md (This file)
│
├── Project_01_Student_Management/
│   ├── Student.h
│   ├── StudentManager.h
│   └── main.cpp
│
├── Project_02_Contact_Book/
│   ├── Contact.h
│   ├── ContactBook.h
│   └── main.cpp
│
├── Project_03_ToDo_Priority/
│   ├── Task.h
│   ├── ToDoManager.h
│   └── main.cpp
│
├── Project_04_Parentheses_Checker/
│   └── main.cpp
│
├── Project_05_Text_Editor/
│   └── main.cpp
│
├── Project_06_Playlist_Manager/
│   └── main.cpp
│
├── Project_07_Library_Management/
│   ├── Book.h
│   ├── LibraryCatalog.h
│   └── main.cpp
│
├── Project_08_Maze_Solver/
│   └── main.cpp
│
├── Project_09_Sorting_Visualizer/
│   └── main.cpp
│
└── Project_10_Word_Analyzer/
    └── main.cpp
```

---


