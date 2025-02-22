#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Queue {
public:
    Node *front, *rear;

    Queue() {
        front = rear = NULL;
    }

    void enqueue(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;
        if (rear == NULL) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue() {
        if (front == NULL) {
            cout << "Queue Underflow! (Empty Queue)\n";
            return;
        }
        Node* temp = front;
        cout << "Dequeued: " << front->data << endl;
        front = front->next;
        if (front == NULL) rear = NULL;  // If queue becomes empty
        delete temp;
    }

    void display() {
        if (front == NULL) {
            cout << "Queue is empty!\n";
            return;
        }
        Node* temp = front;
        cout << "Queue (Front to Rear): ";
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    Queue queue;
    int choice, value;

    do {
        cout << "\nMenu:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                queue.enqueue(value);
                break;
            case 2:
                queue.dequeue();
                break;
            case 3:
                queue.display();
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

