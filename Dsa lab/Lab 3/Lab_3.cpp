#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

class ExpressionConverter {
public:
    int precedence(char op) {
        if (op == '+' || op == '-') return 1;
        if (op == '*' || op == '/') return 2;
        if (op == '^') return 3;
        return 0;
    }

    bool isOperator(char c) {
        return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
    }

    string infixToPostfix(string infix) {
        stack<char> s;
        string postfix;

        for (size_t i = 0; i < infix.length(); ++i) {
            char c = infix[i];
            if (isalnum(c)) {
                postfix += c;
            } else if (c == '(') {
                s.push(c);
            } else if (c == ')') {
                while (!s.empty() && s.top() != '(') {
                    postfix += s.top();
                    s.pop();
                }
                s.pop();
            } else if (isOperator(c)) {
                while (!s.empty() && precedence(s.top()) >= precedence(c)) {
                    postfix += s.top();
                    s.pop();
                }
                s.push(c);
            }
        }

        while (!s.empty()) {
            postfix += s.top();
            s.pop();
        }

        return postfix;
    }

    string infixToPrefix(string infix) {
        reverse(infix.begin(), infix.end());
        for (size_t i = 0; i < infix.length(); ++i) {
            if (infix[i] == '(') infix[i] = ')';
            else if (infix[i] == ')') infix[i] = '(';
        }
        string postfix = infixToPostfix(infix);
        reverse(postfix.begin(), postfix.end());
        return postfix;
    }

    int evaluatePostfix(string postfix) {
        stack<int> s;
        for (size_t i = 0; i < postfix.length(); ++i) {
            char c = postfix[i];
            if (isdigit(c)) {
                s.push(c - '0');
            } else if (isOperator(c)) {
                int b = s.top(); s.pop();
                int a = s.top(); s.pop();
                if (c == '+') s.push(a + b);
                if (c == '-') s.push(a - b);
                if (c == '*') s.push(a * b);
                if (c == '/') s.push(a / b);
                if (c == '^') s.push(static_cast<int>(pow(a, b)));
            }
        }
        return s.top();
    }
};

int main() {
    ExpressionConverter converter;
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Convert Infix to Postfix\n";
        cout << "2. Convert Infix to Prefix\n";
        cout << "3. Evaluate Postfix Expression\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            string infix;
            cout << "Enter infix expression: ";
            getline(cin, infix);
            cout << "Postfix: " << converter.infixToPostfix(infix) << "\n";
        } else if (choice == 2) {
            string infix;
            cout << "Enter infix expression: ";
            getline(cin, infix);
            cout << "Prefix: " << converter.infixToPrefix(infix) << "\n";
        } else if (choice == 3) {
            string postfix;
            cout << "Enter postfix expression: ";
            getline(cin, postfix);
            cout << "Result: " << converter.evaluatePostfix(postfix) << "\n";
        } else if (choice == 4) {
            cout << "Exiting program.\n";
        } else {
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);

    return 0;
}

