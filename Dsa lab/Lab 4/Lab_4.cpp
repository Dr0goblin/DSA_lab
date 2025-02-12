#include <iostream>
using namespace std;

#define SIZE 5 

class Queue {
private:
    int arr[SIZE];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    void MakeEmpty() {
        front = -1;
        rear = -1;
        cout << "Queue is reset to empty.\n";
    }

    bool IsFull() {
        return (rear == SIZE - 1);
    }

    bool IsEmpty() {
        return (front == -1 || front > rear);
    }

    void Enqueue(int value) {
        if (IsFull()) {
            cout << "Queue is full. Cannot enqueue.\n";
            return;
        }
        if (IsEmpty()) {
            front = 0;
        }
        arr[++rear] = value;
        cout << "Enqueued: " << value << "\n";
    }

    void Dequeue() {
        if (IsEmpty()) {
            cout << "Queue is empty. Cannot dequeue.\n";
            return;
        }
        cout << "Dequeued: " << arr[front] << "\n";
        front++;
        if (front > rear) {
            MakeEmpty();
        }
    }

    void Traverse() {
        if (IsEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
};

int main() {
    Queue q;
    int choice, value;

    do {
        cout << "\nQueue Menu:\n";
        cout << "1. MakeEmpty()\n";
        cout << "2. IsFull()\n";
        cout << "3. IsEmpty()\n";
        cout << "4. Enqueue()\n";
        cout << "5. Dequeue()\n";
        cout << "6. Traverse()\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            q.MakeEmpty();
            break;
        case 2:
            cout << (q.IsFull() ? "Queue is full.\n" : "Queue is not full.\n");
            break;
        case 3:
            cout << (q.IsEmpty() ? "Queue is empty.\n" : "Queue is not empty.\n");
            break;
        case 4:
            cout << "Enter value to enqueue: ";
            cin >> value;
            q.Enqueue(value);
            break;
        case 5:
            q.Dequeue();
            break;
        case 6:
            q.Traverse();
            break;
        case 7:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 7);

    return 0;
}

