# Compile All Projects - Windows PowerShell Script
# Run: .\compile_all.ps1

Write-Host "`n========================================" -ForegroundColor Cyan
Write-Host "  DSA Projects - Compile All Script" -ForegroundColor Cyan
Write-Host "========================================`n" -ForegroundColor Cyan

$projects = @(
    @{Name="Project_01_Student_Management"; Output="student_manager"},
    @{Name="Project_02_Contact_Book"; Output="contact_book"},
    @{Name="Project_03_ToDo_Priority"; Output="todo_manager"},
    @{Name="Project_04_Parentheses_Checker"; Output="paren_checker"},
    @{Name="Project_05_Text_Editor"; Output="text_editor"},
    @{Name="Project_06_Playlist_Manager"; Output="playlist_manager"},
    @{Name="Project_07_Library_Management"; Output="library_manager"},
    @{Name="Project_08_Maze_Solver"; Output="maze_solver"},
    @{Name="Project_09_Sorting_Visualizer"; Output="sorting_visualizer"},
    @{Name="Project_10_Word_Analyzer"; Output="word_analyzer"}
)

$success = 0
$failed = 0

foreach ($project in $projects) {
    Write-Host "Compiling $($project.Name)..." -NoNewline
    
    Push-Location $project.Name
    
    $result = g++ -std=c++11 main.cpp -o "$($project.Output).exe" 2>&1
    
    if ($LASTEXITCODE -eq 0) {
        Write-Host " [OK]" -ForegroundColor Green
        $success++
    } else {
        Write-Host " [FAILED]" -ForegroundColor Red
        Write-Host "  Error: $result" -ForegroundColor Yellow
        $failed++
    }
    
    Pop-Location
}

Write-Host "`n========================================" -ForegroundColor Cyan
Write-Host "  Compilation Summary" -ForegroundColor Cyan
Write-Host "========================================" -ForegroundColor Cyan
Write-Host "  Success: $success" -ForegroundColor Green
Write-Host "  Failed:  $failed" -ForegroundColor $(if($failed -eq 0){"Green"}else{"Red"})
Write-Host "========================================`n" -ForegroundColor Cyan

if ($success -eq 10) {
    Write-Host "All projects compiled successfully!" -ForegroundColor Green
    Write-Host "You can now run any project executable.`n" -ForegroundColor Cyan
}
