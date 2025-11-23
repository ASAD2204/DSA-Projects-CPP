#!/bin/bash
# Compile All Projects - Linux/macOS Bash Script
# Run: chmod +x compile_all.sh && ./compile_all.sh

echo ""
echo "========================================"
echo "  DSA Projects - Compile All Script"
echo "========================================"
echo ""

projects=(
    "Project_01_Student_Management:student_manager"
    "Project_02_Contact_Book:contact_book"
    "Project_03_ToDo_Priority:todo_manager"
    "Project_04_Parentheses_Checker:paren_checker"
    "Project_05_Text_Editor:text_editor"
    "Project_06_Playlist_Manager:playlist_manager"
    "Project_07_Library_Management:library_manager"
    "Project_08_Maze_Solver:maze_solver"
    "Project_09_Sorting_Visualizer:sorting_visualizer"
    "Project_10_Word_Analyzer:word_analyzer"
)

success=0
failed=0

for project in "${projects[@]}"; do
    IFS=':' read -r folder output <<< "$project"
    
    echo -n "Compiling $folder..."
    
    cd "$folder" || exit
    
    if g++ -std=c++11 main.cpp -o "$output" 2>/dev/null; then
        echo " [OK]"
        ((success++))
    else
        echo " [FAILED]"
        ((failed++))
    fi
    
    cd ..
done

echo ""
echo "========================================"
echo "  Compilation Summary"
echo "========================================"
echo "  Success: $success"
echo "  Failed:  $failed"
echo "========================================"
echo ""

if [ $success -eq 10 ]; then
    echo "All projects compiled successfully!"
    echo "You can now run any project executable."
    echo ""
fi
