#include <iostream>
using namespace std;

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void maxHeapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, n, largest);
    }
}
void minHeapify(int arr[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}

void heapSortMax(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        maxHeapify(arr, i, 0);
    }
}

void heapSortMin(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        minHeapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        minHeapify(arr, i, 0);
    }
}

int main() {
    int n, choice;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Choose Sorting Type:\n";
    cout << "1. Max Heap (Sort in Ascending Order)\n";
    cout << "2. Min Heap (Sort in Descending Order)\n";
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;

    if (choice == 1) {
        heapSortMax(arr, n);
        cout << "Sorted Array (Ascending Order): ";
        printArray(arr, n);
        cout << "Minimum Element: " << arr[0] << endl;
        cout << "Maximum Element: " << arr[n - 1] << endl;
    } 
    else if (choice == 2) {
        heapSortMin(arr, n);
        cout << "Sorted Array (Descending Order): ";
        printArray(arr, n);
        cout << "Minimum Element: " << arr[n - 1] << endl;
        cout << "Maximum Element: " << arr[0] << endl;
    } 
    else {
        cout << "Invalid choice! Please enter 1 or 2." << endl;
    }

    return 0;
}
