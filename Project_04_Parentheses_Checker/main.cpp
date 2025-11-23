/*
 * ============================================================================
 * PROJECT #4: BALANCED PARENTHESES CHECKER & EXPRESSION VALIDATOR
 * ============================================================================
 * Data Structure: Stack
 * Features: Multi-bracket validation, error position detection, suggestions
 * ============================================================================
 */

#include <iostream>
#include <stack>
#include <string>
using namespace std;

class ParenthesesChecker {
private:
    stack<char> brackets;
    stack<int> positions;

    bool isOpening(char ch) {
        return ch == '(' || ch == '{' || ch == '[' || ch == '<';
    }

    bool isClosing(char ch) {
        return ch == ')' || ch == '}' || ch == ']' || ch == '>';
    }

    bool matches(char open, char close) {
        return (open == '(' && close == ')') ||
               (open == '{' && close == '}') ||
               (open == '[' && close == ']') ||
               (open == '<' && close == '>');
    }

public:
    bool validate(const string& expression) {
        // Clear stacks
        while (!brackets.empty()) brackets.pop();
        while (!positions.empty()) positions.pop();

        for (size_t i = 0; i < expression.length(); i++) {
            char ch = expression[i];

            if (isOpening(ch)) {
                brackets.push(ch);
                positions.push(i);
            }
            else if (isClosing(ch)) {
                if (brackets.empty()) {
                    cout << "\n❌ Error at position " << i << ": Unexpected closing bracket '" << ch << "'" << endl;
                    cout << "   " << expression << endl;
                    cout << "   " << string(i, ' ') << "^" << endl;
                    return false;
                }

                char top = brackets.top();
                if (!matches(top, ch)) {
                    cout << "\n❌ Error at position " << i << ": Mismatched brackets!" << endl;
                    cout << "   Expected '" << getClosing(top) << "' but found '" << ch << "'" << endl;
                    cout << "   " << expression << endl;
                    cout << "   " << string(positions.top(), ' ') << "^" << string(i - positions.top() - 1, ' ') << "^" << endl;
                    return false;
                }

                brackets.pop();
                positions.pop();
            }
        }

        if (!brackets.empty()) {
            cout << "\n❌ Error: Unclosed bracket '" << brackets.top() << "' at position " << positions.top() << endl;
            cout << "   " << expression << endl;
            cout << "   " << string(positions.top(), ' ') << "^" << endl;
            cout << "   Suggestion: Add '" << getClosing(brackets.top()) << "' at the end" << endl;
            return false;
        }

        cout << "\n✅ Expression is perfectly balanced!" << endl;
        return true;
    }

    char getClosing(char open) {
        switch(open) {
            case '(': return ')';
            case '{': return '}';
            case '[': return ']';
            case '<': return '>';
            default: return ' ';
        }
    }

    void displayMenu() {
        cout << "\n========================================================\n";
        cout << "      PARENTHESES & BRACKET VALIDATOR                   \n";
        cout << "========================================================\n";
        cout << "\n  Supported brackets: ( ) { } [ ] < >\n";
        cout << "\n  Examples:\n";
        cout << "    Valid:   {[()]}  ((a+b)*c)  <div>{content}</div>\n";
        cout << "    Invalid: {[(])   ((a+b)     {[}]\n";
        cout << "\n" << string(56, '=') << endl;
    }

    void runTests() {
        cout << "\n🧪 Running Test Cases...\n";
        
        string tests[] = {
            "()",
            "{}[]",
            "{[()]}",
            "((a+b)*(c-d))",
            "{[(])}",
            "(()",
            "())",
            "<div>{content[0]}</div>"
        };

        for (const string& test : tests) {
            cout << "\nTest: " << test << endl;
            validate(test);
        }
    }
};

int main() {
    ParenthesesChecker checker;
    checker.displayMenu();

    int choice;
    while (true) {
        cout << "\n  1. Validate Expression\n";
        cout << "  2. Run Test Cases\n";
        cout << "  3. Exit\n";
        cout << "  Choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            string expr;
            cout << "\n  Enter expression: ";
            getline(cin, expr);
            checker.validate(expr);
        }
        else if (choice == 2) {
            checker.runTests();
        }
        else if (choice == 3) {
            cout << "\n  Goodbye!\n";
            break;
        }
    }

    return 0;
}
