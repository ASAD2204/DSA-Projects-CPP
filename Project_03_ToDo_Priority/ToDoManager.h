/*
 * ============================================================================
 * ToDoManager.h - Task Management using Min Heap (Priority Queue)
 * ============================================================================
 */

#ifndef TODO_MANAGER_H
#define TODO_MANAGER_H

#include "Task.h"
#include <fstream>
#include <vector>
#include <algorithm>

class ToDoManager {
private:
    vector<Task> tasks;
    string filename;

    // Min heap operations based on priority
    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (tasks[index].getPriority() < tasks[parent].getPriority()) {
                swap(tasks[index], tasks[parent]);
                index = parent;
            } else {
                break;
            }
        }
    }

    void heapifyDown(int index) {
        int size = tasks.size();
        while (true) {
            int smallest = index;
            int left = 2 * index + 1;
            int right = 2 * index + 2;

            if (left < size && tasks[left].getPriority() < tasks[smallest].getPriority())
                smallest = left;
            if (right < size && tasks[right].getPriority() < tasks[smallest].getPriority())
                smallest = right;

            if (smallest != index) {
                swap(tasks[index], tasks[smallest]);
                index = smallest;
            } else {
                break;
            }
        }
    }

public:
    ToDoManager(string file = "tasks.csv") : filename(file) {
        loadFromFile();
    }

    ~ToDoManager() {
        saveToFile();
    }

    void addTask(const Task& task) {
        tasks.push_back(task);
        heapifyUp(tasks.size() - 1);
        cout << "\n✅ Task added successfully! (ID: " << task.getId() << ")" << endl;
    }

    void displayAll() const {
        if (tasks.empty()) {
            cout << "\n⚠️  No tasks found!" << endl;
            return;
        }

        Task::displayHeader();
        for (const auto& task : tasks) {
            task.display();
        }
        cout << string(95, '=') << endl;
        cout << "Total Tasks: " << tasks.size() << endl;
    }

    void displayByPriority() const {
        vector<Task> sorted = tasks;
        sort(sorted.begin(), sorted.end(), [](const Task& a, const Task& b) {
            return a.getPriority() < b.getPriority();
        });

        Task::displayHeader();
        for (const auto& task : sorted) {
            task.display();
        }
    }

    void displayPending() const {
        bool found = false;
        Task::displayHeader();
        for (const auto& task : tasks) {
            if (!task.isCompleted()) {
                task.display();
                found = true;
            }
        }
        if (!found) {
            cout << "No pending tasks! 🎉" << endl;
        }
    }

    void displayCompleted() const {
        bool found = false;
        Task::displayHeader();
        for (const auto& task : tasks) {
            if (task.isCompleted()) {
                task.display();
                found = true;
            }
        }
        if (!found) {
            cout << "No completed tasks yet." << endl;
        }
    }

    bool markComplete(int id) {
        for (auto& task : tasks) {
            if (task.getId() == id) {
                task.setCompleted(true);
                cout << "\n✅ Task marked as complete!" << endl;
                return true;
            }
        }
        cout << "\n❌ Task not found!" << endl;
        return false;
    }

    bool deleteTask(int id) {
        for (size_t i = 0; i < tasks.size(); i++) {
            if (tasks[i].getId() == id) {
                tasks.erase(tasks.begin() + i);
                // Rebuild heap
                for (int j = tasks.size() / 2 - 1; j >= 0; j--) {
                    heapifyDown(j);
                }
                cout << "\n✅ Task deleted successfully!" << endl;
                return true;
            }
        }
        cout << "\n❌ Task not found!" << endl;
        return false;
    }

    void saveToFile() const {
        ofstream file(filename);
        if (!file.is_open()) return;

        for (const auto& task : tasks) {
            file << task.toCSV() << endl;
        }
        file.close();
    }

    void loadFromFile() {
        ifstream file(filename);
        if (!file.is_open()) return;

        string line;
        while (getline(file, line)) {
            if (!line.empty()) {
                tasks.push_back(Task::fromCSV(line));
            }
        }
        file.close();

        // Build heap
        for (int i = tasks.size() / 2 - 1; i >= 0; i--) {
            heapifyDown(i);
        }
    }

    int getTotalTasks() const { return tasks.size(); }
};

#endif
