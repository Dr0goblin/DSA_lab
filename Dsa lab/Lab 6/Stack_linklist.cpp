#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Stack {
public:
    Node* top;

    Stack() {
        top = NULL;
    }

    void push(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (top == NULL) {
            cout << "Stack Underflow! (Empty Stack)\n";
            return;
        }
        Node* temp = top;
        cout << "Popped: " << top->data << endl;
        top = top->next;
        delete temp;
    }

    void display() {
        if (top == NULL) {
            cout << "Stack is empty!\n";
            return;
        }
        Node* temp = top;
        cout << "Stack (Top to Bottom): ";
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    Stack stack;
    int choice, value;

    do {
        cout << "\nMenu:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                stack.push(value);
                break;
            case 2:
                stack.pop();
                break;
            case 3:
                stack.display();
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 4);

    return 0;
}

