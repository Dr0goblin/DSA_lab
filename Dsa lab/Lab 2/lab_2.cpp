#include <iostream>
#define MAX_SIZE 100
using namespace std;
class Stack {
private:
    int arr[MAX_SIZE];
    int top; 
public:
    Stack() : top(-1) {} 
    void makeEmpty() {
        top = -1;
        cout << "Stack is now empty." <<endl;
    }
    void push(int value) {
        if (top >= MAX_SIZE - 1) {
           cout << "Stack overflow: Cannot push more elements." <<endl;
        } else {
            arr[++top] = value;
            cout << value << " has been pushed onto the stack." <<endl;
        }
    }
    void pop() {
        if (isEmpty()) {
           cout << "Stack underflow: Cannot pop from an empty stack." <<endl;
        } else {
            cout << arr[top--] << " has been popped from the stack." <<endl;
        }
    }
    void displayTop() const {
        if (isEmpty()) {
           cout << "Stack is empty: No top element." <<endl;
        } else {
           cout << "Top element: " << arr[top] <<endl;
        }
    }
    void traverse() const {
        if (isEmpty()) {
           cout << "Stack is empty: Nothing to traverse." <<endl;
        } else {
           cout << "Stack elements (top to bottom): ";
            for (int i = top; i >= 0; --i) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
    bool isEmpty() const {
        return top == -1;
    }
};

int main() {
    Stack myStack;
    int choice, value;

    do {
      cout << "\n--- Stack Menu ---\n";
      cout << "1. Make Empty Stack\n";
      cout << "2. Push\n";
      cout << "3. Pop\n";
      cout << "4. Traverse\n";
      cout << "5. Top\n";
      cout << "6. Exit\n";
      cout << "Enter your choice: ";
      cin >> choice;

        switch (choice) {
            case 1:
                myStack.makeEmpty();
                break;
            case 2:
                cout << "Enter value to push: ";
                cin >> value;
                myStack.push(value);
                break;
            case 3:
                myStack.pop();
                break;
            case 4:
                myStack.traverse();
                break;
            case 5:
                myStack.displayTop();
                break;
            case 6:
                cout << "Exiting program. Goodbye!" <<endl;
                break;
            default:
                cout << "Invalid choice. Please try again." <<endl;
                break;
        }
    } while (choice != 6);
     return 0;
}
