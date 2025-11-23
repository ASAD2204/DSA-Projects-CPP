/*
 * ============================================================================
 * PROJECT #5: UNDO/REDO TEXT EDITOR
 * ============================================================================
 * Data Structure: Two Stacks (undo stack + redo stack)
 * Features: Insert, delete, undo, redo, clipboard operations
 * ============================================================================
 */

#include <iostream>
#include <stack>
#include <string>
using namespace std;

class TextEditor {
private:
    string content;
    stack<string> undoStack;
    stack<string> redoStack;
    string clipboard;

    void saveState() {
        undoStack.push(content);
        // Clear redo stack when new action is performed
        while (!redoStack.empty()) redoStack.pop();
    }

public:
    TextEditor() : content("") {}

    void insertText(const string& text) {
        saveState();
        content += text;
        cout << "✅ Text inserted." << endl;
    }

    void deleteText(int count) {
        if (count > content.length()) count = content.length();
        saveState();
        content = content.substr(0, content.length() - count);
        cout << "✅ Deleted " << count << " character(s)." << endl;
    }

    void undo() {
        if (undoStack.empty()) {
            cout << "❌ Nothing to undo!" << endl;
            return;
        }
        redoStack.push(content);
        content = undoStack.top();
        undoStack.pop();
        cout << "↩️  Undo successful." << endl;
    }

    void redo() {
        if (redoStack.empty()) {
            cout << "❌ Nothing to redo!" << endl;
            return;
        }
        undoStack.push(content);
        content = redoStack.top();
        redoStack.pop();
        cout << "↪️  Redo successful." << endl;
    }

    void copy() {
        clipboard = content;
        cout << "📋 Copied to clipboard." << endl;
    }

    void paste() {
        if (clipboard.empty()) {
            cout << "❌ Clipboard is empty!" << endl;
            return;
        }
        saveState();
        content += clipboard;
        cout << "📋 Pasted from clipboard." << endl;
    }

    void clear() {
        saveState();
        content = "";
        cout << "🗑️  Content cleared." << endl;
    }

    void display() const {
        cout << "\n" << string(60, '=') << endl;
        cout << "📄 Current Content:" << endl;
        cout << string(60, '-') << endl;
        if (content.empty()) {
            cout << "(empty)" << endl;
        } else {
            cout << content << endl;
        }
        cout << string(60, '=') << endl;
        cout << "Length: " << content.length() << " characters" << endl;
        cout << "Undo available: " << (undoStack.empty() ? "No" : "Yes") << endl;
        cout << "Redo available: " << (redoStack.empty() ? "No" : "Yes") << endl;
    }

    void showStats() const {
        cout << "\n📊 Statistics:" << endl;
        cout << "  Total characters: " << content.length() << endl;
        cout << "  Words: " << countWords() << endl;
        cout << "  Lines: " << countLines() << endl;
        cout << "  Undo stack size: " << undoStack.size() << endl;
        cout << "  Redo stack size: " << redoStack.size() << endl;
    }

private:
    int countWords() const {
        if (content.empty()) return 0;
        int count = 1;
        for (char ch : content) {
            if (ch == ' ' || ch == '\n') count++;
        }
        return count;
    }

    int countLines() const {
        if (content.empty()) return 0;
        int count = 1;
        for (char ch : content) {
            if (ch == '\n') count++;
        }
        return count;
    }
};

int main() {
    TextEditor editor;
    int choice;

    cout << "\n========================================================\n";
    cout << "         TEXT EDITOR WITH UNDO/REDO                     \n";
    cout << "========================================================\n";

    while (true) {
        cout << "\n  1. Insert Text\n";
        cout << "  2. Delete Characters\n";
        cout << "  3. Undo (Ctrl+Z)\n";
        cout << "  4. Redo (Ctrl+Y)\n";
        cout << "  5. Copy (Ctrl+C)\n";
        cout << "  6. Paste (Ctrl+V)\n";
        cout << "  7. Clear All\n";
        cout << "  8. Show Content\n";
        cout << "  9. Show Statistics\n";
        cout << "  10. Exit\n";
        cout << "  Choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            string text;
            cout << "  Enter text: ";
            getline(cin, text);
            editor.insertText(text);
        }
        else if (choice == 2) {
            int count;
            cout << "  Delete how many characters? ";
            cin >> count;
            editor.deleteText(count);
        }
        else if (choice == 3) {
            editor.undo();
        }
        else if (choice == 4) {
            editor.redo();
        }
        else if (choice == 5) {
            editor.copy();
        }
        else if (choice == 6) {
            editor.paste();
        }
        else if (choice == 7) {
            editor.clear();
        }
        else if (choice == 8) {
            editor.display();
        }
        else if (choice == 9) {
            editor.showStats();
        }
        else if (choice == 10) {
            cout << "\n  Goodbye!\n";
            break;
        }
    }

    return 0;
}
