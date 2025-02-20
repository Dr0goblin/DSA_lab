#include <iostream>
using namespace std;

#define MAX 100

class PriorityQueueADT {
private:
    int values[MAX], priorities[MAX], size;

public:
    PriorityQueueADT() : size(0) {}

    void Enqueue(int value, int priority) {
        if (size >= MAX) {
            cout << "Queue is full!\n";
            return;
        }

        int i;
        for (i = size - 1; i >= 0 && priorities[i] < priority; i--) {
            values[i + 1] = values[i];
            priorities[i + 1] = priorities[i];
        }

        values[i + 1] = value;
        priorities[i + 1] = priority;
        size++;
        cout << "Enqueued: " << value << " (Priority: " << priority << ")\n";
    }

    void Dequeue() {
        if (size == 0) {
            cout << "Queue is empty!\n";
            return;
        }

        cout << "Dequeued: " << values[0] << " (Priority: " << priorities[0] << ")\n";
        for (int i = 0; i < size - 1; i++) {
            values[i] = values[i + 1];
            priorities[i] = priorities[i + 1];
        }
        size--;
    }

    void Traverse() {
        if (size == 0) {
            cout << "Queue is empty!\n";
            return;
        }

        for (int i = 0; i < size; i++)
            cout << values[i] << " (Priority: " << priorities[i] << ")\n";
    }
};

int main() {
    PriorityQueueADT pq;
    int choice, value, priority;

    do {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Traverse\n4. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value & priority: ";
            cin >> value >> priority;
            pq.Enqueue(value, priority);
            break;
        case 2:
            pq.Dequeue();
            break;
        case 3:
            pq.Traverse();
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

