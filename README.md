# 🎓 Data Structures & Algorithms Projects Portfolio

A comprehensive collection of 10 beginner-to-intermediate DSA projects implemented in C++, demonstrating practical applications of fundamental data structures and algorithms.

[![Language](https://img.shields.io/badge/Language-C%2B%2B11-blue.svg)](https://en.cppreference.com/)
[![License](https://img.shields.io/badge/License-MIT-green.svg)](LICENSE)
[![Projects](https://img.shields.io/badge/Projects-10-orange.svg)]()

## 📚 Table of Contents
- [Overview](#overview)
- [Projects](#projects)
- [Technologies Used](#technologies-used)
- [Installation & Setup](#installation--setup)
- [How to Run](#how-to-run)
- [Project Structure](#project-structure)
- [Learning Outcomes](#learning-outcomes)
- [Contributing](#contributing)
- [Author](#author)

---

## 🌟 Overview

This repository contains **10 complete DSA projects** built from scratch in C++. Each project focuses on different data structures and algorithms, providing hands-on experience with:

- **Data Structures**: Linked Lists, Binary Search Trees, Heaps, Stacks, Queues, Graphs, Hash Maps
- **Algorithms**: Sorting (6 algorithms), Searching, Graph Traversal (BFS/DFS), Heapify operations
- **Real-world Applications**: Student management, contact books, task schedulers, maze solvers, and more

All projects feature:
- ✅ Menu-driven user interfaces
- ✅ Comprehensive comments and documentation
- ✅ Error handling and input validation
- ✅ File I/O for data persistence
- ✅ Clean, readable code structure

---

## 🚀 Projects

### 1. Student Management System
**Data Structure:** Singly Linked List  
**Features:**
- CRUD operations for student records
- Search by roll number, name, or department
- Sort by roll number, name, or GPA
- CSV file export/import
- Statistical analysis (average GPA, top performers)

**Key Concepts:** Linked List operations, File I/O, Sorting algorithms

[View Project →](./Project_01_Student_Management/)

---

### 2. Contact Book (Phonebook)
**Data Structure:** Binary Search Tree (BST)  
**Features:**
- Add/delete contacts (auto-sorted alphabetically)
- Search by name (exact or prefix matching)
- Display in alphabetical order
- Export to CSV
- Categorize contacts (Family, Friends, Work, etc.)

**Key Concepts:** BST operations, Tree traversal (Inorder), Prefix search

[View Project →](./Project_02_Contact_Book/)

---

### 3. ToDo List with Priority Management
**Data Structure:** Min Heap (Priority Queue)  
**Features:**
- Add tasks with priority levels (High/Medium/Low)
- Automatic priority-based sorting
- Mark tasks as complete
- View tasks by priority or status
- Deadline tracking

**Key Concepts:** Heap operations, Heapify, Priority Queue implementation

[View Project →](./Project_03_ToDo_Priority/)

---

### 4. Parentheses & Bracket Validator
**Data Structure:** Stack  
**Features:**
- Validate balanced parentheses/brackets/braces
- Support for `( ) { } [ ] < >`
- Error detection with position reporting
- Detailed error messages (missing, extra, or mismatched brackets)
- Built-in test cases

**Key Concepts:** Stack operations, Expression validation, String parsing

[View Project →](./Project_04_Parentheses_Checker/)

---

### 5. Text Editor with Undo/Redo
**Data Structure:** Two Stacks (Undo + Redo)  
**Features:**
- Insert/delete text at any position
- Unlimited undo/redo functionality
- Copy/paste with clipboard
- Display with line numbers
- Character and word count

**Key Concepts:** Stack-based state management, Undo/Redo pattern

[View Project →](./Project_05_Text_Editor/)

---

### 6. Playlist Manager
**Data Structure:** Queue + Stack  
**Features:**
- Play queue with FIFO behavior
- Recently played history (Stack)
- Shuffle mode with randomization
- Repeat mode
- Song library management
- Next/Previous navigation

**Key Concepts:** Queue operations, Combining multiple data structures

[View Project →](./Project_06_Playlist_Manager/)

---

### 7. Library Book Management System
**Data Structure:** BST (Catalog) + Priority Queue (Issue Requests)  
**Features:**
- Book catalog with search by ID/title
- Issue/return books with copy tracking
- Priority-based waiting list
- Auto-issue when books are returned
- Availability status

**Key Concepts:** Combining BST with Priority Queue, Inventory management

[View Project →](./Project_07_Library_Management/)

---

### 8. Maze Solver & Generator
**Data Structure:** Graph (Adjacency Matrix), BFS, DFS  
**Features:**
- Random maze generation
- Solve using BFS (shortest path)
- Solve using DFS (depth-first exploration)
- Path visualization
- Custom maze input
- Compare algorithm performance

**Key Concepts:** Graph representation, BFS/DFS traversal, Pathfinding

[View Project →](./Project_08_Maze_Solver/)

---

### 9. Sorting Algorithm Visualizer
**Data Structure:** Arrays  
**Features:**
- **6 Sorting Algorithms:**
  - Bubble Sort
  - Selection Sort
  - Insertion Sort
  - Merge Sort
  - Quick Sort
  - Heap Sort
- Step-by-step visualization
- Performance metrics (comparisons, swaps)
- Random array generation
- Algorithm comparison

**Key Concepts:** All major sorting algorithms, Time complexity analysis

[View Project →](./Project_09_Sorting_Visualizer/)

---

### 10. Word Frequency Counter & Analyzer
**Data Structure:** Hash Map (unordered_map) + Priority Queue  
**Features:**
- Word frequency counting
- Top K most/least frequent words
- Text file loading
- Search with percentage
- Statistical analysis
- Case-insensitive processing

**Key Concepts:** Hash Maps, Top-K problems, Text processing

[View Project →](./Project_10_Word_Analyzer/)

---

## 🛠️ Technologies Used

- **Language:** C++11
- **Compiler:** g++ (GCC/MinGW)
- **Standard Libraries:**
  - `<iostream>` - Input/Output
  - `<fstream>` - File handling
  - `<string>` - String operations
  - `<vector>` - Dynamic arrays
  - `<queue>` - Queue/Priority Queue
  - `<stack>` - Stack operations
  - `<unordered_map>` - Hash Map
  - `<algorithm>` - Sorting/Searching

---

## 💻 Installation & Setup

### Prerequisites
- **C++ Compiler:** GCC/g++ or MinGW (Windows) or Clang (macOS/Linux)
- **C++11 or higher**

### Windows (MinGW)
```bash
# Install MinGW from: https://sourceforge.net/projects/mingw/
# Add to PATH: C:\MinGW\bin

# Verify installation
g++ --version
```

### Linux
```bash
# Install g++
sudo apt-get update
sudo apt-get install g++

# Verify installation
g++ --version
```

### macOS
```bash
# Install Xcode Command Line Tools
xcode-select --install

# Verify installation
g++ --version
```

---

## ▶️ How to Run

### Clone the Repository
```bash
git clone https://github.com/ASAD2204/DSA_Projects.git
cd DSA_Projects
```

### Compile and Run Individual Projects

#### Windows (PowerShell/CMD)
```bash
# Navigate to project folder
cd Project_01_Student_Management

# Compile
g++ -std=c++11 main.cpp -o student_manager.exe

# Run
student_manager.exe
```

#### Linux/macOS
```bash
# Navigate to project folder
cd Project_01_Student_Management

# Compile
g++ -std=c++11 main.cpp -o student_manager

# Run
./student_manager
```

### Compile All Projects (Batch Script)

**Windows (PowerShell):**
```powershell
# Save as compile_all.ps1
$projects = @(
    "Project_01_Student_Management",
    "Project_02_Contact_Book",
    "Project_03_ToDo_Priority",
    "Project_04_Parentheses_Checker",
    "Project_05_Text_Editor",
    "Project_06_Playlist_Manager",
    "Project_07_Library_Management",
    "Project_08_Maze_Solver",
    "Project_09_Sorting_Visualizer",
    "Project_10_Word_Analyzer"
)

foreach ($project in $projects) {
    Write-Host "Compiling $project..." -ForegroundColor Green
    cd $project
    g++ -std=c++11 main.cpp -o app.exe
    cd ..
}

Write-Host "All projects compiled successfully!" -ForegroundColor Cyan
```

**Linux/macOS (Bash):**
```bash
#!/bin/bash
# Save as compile_all.sh

projects=(
    "Project_01_Student_Management"
    "Project_02_Contact_Book"
    "Project_03_ToDo_Priority"
    "Project_04_Parentheses_Checker"
    "Project_05_Text_Editor"
    "Project_06_Playlist_Manager"
    "Project_07_Library_Management"
    "Project_08_Maze_Solver"
    "Project_09_Sorting_Visualizer"
    "Project_10_Word_Analyzer"
)

for project in "${projects[@]}"; do
    echo "Compiling $project..."
    cd "$project"
    g++ -std=c++11 main.cpp -o app
    cd ..
done

echo "All projects compiled successfully!"
```

---

## 📂 Project Structure

```
DSA_Projects/
│
├── README.md                           # This file
├── PROJECT_SUMMARY.md                  # Detailed project documentation
├── LICENSE                             # MIT License
├── CONTRIBUTING.md                     # Contribution guidelines
├── .gitignore                          # Git ignore rules
│
├── dsa.h                               # Comprehensive DSA library
├── test_dsa.cpp                        # Test suite for dsa.h
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

## 📊 Data Structures & Algorithms Coverage

### Data Structures Implemented
| Data Structure | Projects |
|----------------|----------|
| Singly Linked List | #1 |
| Binary Search Tree | #2, #7 |
| Min Heap | #3, #7 |
| Max Heap | #9 |
| Stack | #4, #5, #6 |
| Queue | #6 |
| Priority Queue | #3, #7, #10 |
| Graph (Adjacency Matrix) | #8 |
| Hash Map | #10 |
| Arrays | #9 |

### Algorithms Implemented
| Algorithm | Time Complexity | Projects |
|-----------|----------------|----------|
| Bubble Sort | O(n²) | #1, #9 |
| Selection Sort | O(n²) | #9 |
| Insertion Sort | O(n²) | #9 |
| Merge Sort | O(n log n) | #9 |
| Quick Sort | O(n log n) avg | #9 |
| Heap Sort | O(n log n) | #9 |
| Binary Search | O(log n) | #2 |
| BFS | O(V + E) | #8 |
| DFS | O(V + E) | #8 |
| Heapify | O(log n) | #3, #9 |

---

## 🎯 Learning Outcomes

By exploring these projects, you will gain:

1. **Data Structure Mastery**
   - Understanding when to use each data structure
   - Implementation from scratch
   - Trade-offs and performance characteristics

2. **Algorithm Design**
   - Sorting and searching techniques
   - Graph traversal algorithms
   - Problem-solving patterns

3. **Software Engineering**
   - Clean code principles
   - Modular design
   - File I/O and data persistence
   - Error handling

4. **Interview Preparation**
   - Common DSA interview questions
   - Time/space complexity analysis
   - Real-world application of concepts

---

## 💡 Interview Questions These Projects Help Answer

| Interview Question | Relevant Project |
|--------------------|------------------|
| "Implement an LRU Cache" | #5 (Text Editor - similar stack pattern) |
| "Design a task scheduler with priorities" | #3 (ToDo Priority) |
| "Find top K frequent elements" | #10 (Word Analyzer) |
| "Validate balanced parentheses" | #4 (Parentheses Checker) |
| "Find shortest path in a maze" | #8 (Maze Solver - BFS) |
| "Implement autocomplete/prefix search" | #2 (Contact Book) |
| "Design a music player queue" | #6 (Playlist Manager) |
| "Implement undo/redo functionality" | #5 (Text Editor) |

---

## 🤝 Contributing

Contributions are welcome! Please read [CONTRIBUTING.md](CONTRIBUTING.md) for details on how to contribute to this project.

---

## 📝 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---

## 👨‍💻 Author

**Asad**  
- GitHub: [@ASAD2204](https://github.com/ASAD2204)
- Institution: BS IT (4th Semester)

---

## 🌟 Acknowledgments

- Inspired by classic DSA problems and interview questions
- Built for educational purposes and portfolio development
- All implementations are original and created from scratch

---

## 📈 Project Stats

- **Total Projects:** 10
- **Total Lines of Code:** ~3000+
- **Data Structures Covered:** 10+
- **Algorithms Implemented:** 15+
- **Time Investment:** 40+ hours

---

## 🔗 Quick Links

- [Detailed Project Summary](./PROJECT_SUMMARY.md)
- [Compilation Guide](#how-to-run)
- [Interview Prep Tips](./PROJECT_SUMMARY.md#interview-preparation-tips)

---

### ⭐ If you found this helpful, please star the repository!

**Happy Coding! 🚀**
