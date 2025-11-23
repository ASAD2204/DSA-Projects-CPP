/*
 * ============================================================================
 * PROJECT #3: TO-DO LIST WITH PRIORITY
 * ============================================================================
 * Data Structure: Min Heap (Priority Queue)
 * Features: Priority-based tasks, deadlines, filtering, auto-save
 * ============================================================================
 */

#include "ToDoManager.h"

void displayMenu() {
    cout << "\n========================================================\n";
    cout << "           TO-DO LIST WITH PRIORITY                     \n";
    cout << "========================================================\n";
    cout << "  1. Add New Task\n";
    cout << "  2. View All Tasks\n";
    cout << "  3. View by Priority\n";
    cout << "  4. View Pending Tasks\n";
    cout << "  5. View Completed Tasks\n";
    cout << "  6. Mark Task as Complete\n";
    cout << "  7. Delete Task\n";
    cout << "  8. Save & Exit\n";
    cout << "  Choice: ";
}

int main() {
    ToDoManager manager;
    int choice;

    cout << "\n╔════════════════════════════════════════════════════════╗\n";
    cout << "║          WELCOME TO TO-DO MANAGER                      ║\n";
    cout << "╚════════════════════════════════════════════════════════╝\n";

    if (manager.getTotalTasks() > 0) {
        cout << "\n  ℹ️  Loaded " << manager.getTotalTasks() << " task(s).\n";
    }

    while (true) {
        displayMenu();
        cin >> choice;

        if (choice == 1) {
            string desc, deadline, category;
            int priority;

            cin.ignore();
            cout << "\n  Description: ";
            getline(cin, desc);
            cout << "  Priority (1=High, 2=Medium, 3=Low): ";
            cin >> priority;
            cin.ignore();
            cout << "  Deadline (YYYY-MM-DD): ";
            getline(cin, deadline);
            cout << "  Category: ";
            getline(cin, category);

            manager.addTask(Task(desc, priority, deadline, category));
        }
        else if (choice == 2) {
            manager.displayAll();
        }
        else if (choice == 3) {
            manager.displayByPriority();
        }
        else if (choice == 4) {
            manager.displayPending();
        }
        else if (choice == 5) {
            manager.displayCompleted();
        }
        else if (choice == 6) {
            int id;
            cout << "  Enter Task ID: ";
            cin >> id;
            manager.markComplete(id);
        }
        else if (choice == 7) {
            int id;
            cout << "  Enter Task ID: ";
            cin >> id;
            manager.deleteTask(id);
        }
        else if (choice == 8) {
            manager.saveToFile();
            cout << "\n  ✅ Tasks saved. Goodbye!\n";
            break;
        }

        if (choice >= 1 && choice <= 8) {
            cout << "\n  Press Enter...";
            cin.ignore();
            cin.get();
        }
    }

    return 0;
}
