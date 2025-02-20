#include <iostream>
using namespace std;

class CircularQueue {
private:
    int *queue;
    int front, rear, size;

public:
    CircularQueue(int size) {
        this->size = size;
        queue = new int[size];
        front = rear = -1;
    }
    bool isFull() {
        return (rear + 1) % size == front;
    }
    bool isEmpty() {
        return front == -1;
    }
    void Enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue!" << endl;
        } else {
            if (front == -1) {
                front = 0; 
            }
            rear = (rear + 1) % size; 
            queue[rear] = value;
            cout << "Enqueued " << value << endl;
        }
    }

    void Dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue!" << endl;
        } else {
            cout << "Dequeued " << queue[front] << endl;
            if (front == rear) {
                front = rear = -1; 
            } else {
                front = (front + 1) % size; 
            }
        }
    }

    void Traverse() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
        } else {
            cout << "Queue elements: ";
            int i = front;
            while (i != rear) {
                cout << queue[i] << " ";
                i = (i + 1) % size;
            }
            cout << queue[rear] << endl; 
        }
    }
};

int main() {
    int size;
    cout << "Enter size of Circular Queue: ";
    cin >> size;

    CircularQueue cq(size);

    int choice, value;
    do {
        cout << "\nMenu: \n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Traverse\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to enqueue: ";
            cin >> value;
            cq.Enqueue(value);
            break;
        case 2:
            cq.Dequeue();
            break;
        case 3:
            cq.Traverse();
            break;
        case 4:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}

