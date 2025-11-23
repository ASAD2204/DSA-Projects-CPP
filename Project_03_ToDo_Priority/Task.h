/*
 * ============================================================================
 * Task.h - Task Class Definition with Priority
 * ============================================================================
 */

#ifndef TASK_H
#define TASK_H

#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
using namespace std;

class Task {
private:
    int id;
    string description;
    int priority;        // 1=High, 2=Medium, 3=Low
    bool completed;
    string deadline;     // Format: YYYY-MM-DD
    string category;

public:
    static int nextId;

    Task() : id(nextId++), description(""), priority(3), completed(false), deadline(""), category("General") {}

    Task(string desc, int prio, string dead, string cat = "General")
        : id(nextId++), description(desc), priority(prio), completed(false), deadline(dead), category(cat) {}

    // Getters
    int getId() const { return id; }
    string getDescription() const { return description; }
    int getPriority() const { return priority; }
    bool isCompleted() const { return completed; }
    string getDeadline() const { return deadline; }
    string getCategory() const { return category; }

    // Setters
    void setDescription(string desc) { description = desc; }
    void setPriority(int prio) { priority = prio; }
    void setCompleted(bool comp) { completed = comp; }
    void setDeadline(string dead) { deadline = dead; }
    void setCategory(string cat) { category = cat; }

    string getPriorityString() const {
        switch(priority) {
            case 1: return "🔴 High";
            case 2: return "🟡 Medium";
            case 3: return "🟢 Low";
            default: return "Unknown";
        }
    }

    void display() const {
        cout << left << setw(6) << id
             << setw(10) << (completed ? "✅ Done" : "⏳ Pending")
             << setw(12) << getPriorityString()
             << setw(40) << description
             << setw(12) << deadline
             << setw(15) << category << endl;
    }

    static void displayHeader() {
        cout << "\n" << string(95, '=') << endl;
        cout << left << setw(6) << "ID"
             << setw(10) << "Status"
             << setw(12) << "Priority"
             << setw(40) << "Description"
             << setw(12) << "Deadline"
             << setw(15) << "Category" << endl;
        cout << string(95, '=') << endl;
    }

    string toCSV() const {
        return to_string(id) + "," + description + "," + to_string(priority) + "," +
               (completed ? "1" : "0") + "," + deadline + "," + category;
    }

    static Task fromCSV(const string& line) {
        Task t;
        size_t pos = 0, found;
        string data = line;
        int field = 0;

        while ((found = data.find(',')) != string::npos) {
            string token = data.substr(0, found);
            switch(field) {
                case 0: t.id = stoi(token); break;
                case 1: t.description = token; break;
                case 2: t.priority = stoi(token); break;
                case 3: t.completed = (token == "1"); break;
                case 4: t.deadline = token; break;
            }
            data.erase(0, found + 1);
            field++;
        }
        t.category = data;
        if (t.id >= nextId) nextId = t.id + 1;
        return t;
    }
};

int Task::nextId = 1;

#endif
