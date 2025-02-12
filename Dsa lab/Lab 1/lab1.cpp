#include <iostream>
#include <algorithm>
using namespace std;

void displayArray(int Arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << Arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int Arr[100]; 
    int size = 0;

    cout << "Enter numbers to fill the array (enter -1 to stop):" << endl;
    while (true) {
        int n;
        cin >> n;
        if (n == -1) break; 
        if (size < 100) {
            Arr[size++] = n; 
        } else {
            cout << "Array is full, cannot insert more numbers." << endl;
            break;
        }
    }

    while (true) {
        int option;
        cout << "\nChoose an option:\n1. Insert\n2. Delete\n3. Search\n4. Sort\n5. Display\n6. Merge\n7. Exit\n";
        cin >> option;

        switch (option) {
            case 1: {
                if (size < 100) {
                    int n;
                    cout << "Enter the number to insert: ";
                    cin >> n;
                    Arr[size++] = n;
                    cout << "New Array: ";
                    displayArray(Arr, size);
                } else {
                    cout << "Array is full, cannot insert." << endl;
                }
                break;
            }
            case 2: {
                int p;
                cout << "Enter index to delete (0 to " << size - 1 << "): ";
                cin >> p;
                if (p >= 0 && p < size) {
                    for (int j = p; j < size - 1; j++) {
                        Arr[j] = Arr[j + 1];
                    }
                    size--;
                    cout << "Updated array: ";
                    displayArray(Arr, size);
                } else {
                    cout << "Invalid index." << endl;
                }
                break;
            }
            case 3: { 
                int p;
                cout << "Enter number to search: ";
                cin >> p;
                auto it = find(Arr, Arr + size, p);
                if (it != Arr + size) {
                    cout << "Number " << p << " found at index: " << distance(Arr, it) << endl;
                } else {
                    cout << "Number not found." << endl;
                }
                break;
            }
            case 4: { 
                sort(Arr, Arr + size);
                cout << "Sorted Array: ";
                displayArray(Arr, size);
                break;
            }
            case 5: {
                cout << "Array Elements: ";
                displayArray(Arr, size);
                break;
            }
            case 6: { 
                int Arr1[] = {8, 12, 23, 45, 12, 45, 66};
                int size1 = sizeof(Arr1) / sizeof(Arr1[0]);
                int merged[100];
                copy(Arr, Arr + size, merged);
                copy(Arr1, Arr1 + size1, merged + size);
                sort(merged, merged + size + size1);
                cout << "Merged array: ";
                displayArray(merged, size + size1);
                break;
            }
            case 7:
                cout << "Exiting the program." << endl;
                return 0;
            default:
                cout << "Invalid option selected." << endl;
                break;
        }
        
        char choice;
        cout << "Do you want to perform another operation? (y/n): ";
        cin >> choice;
        if (choice != 'y' && choice != 'Y') {
            cout << "Exiting the program." << endl;
            break;
        }
    }
    
    return 0;
}