#include <iostream>
using namespace std;

void towerOfHanoi(int n, char fromPeg, char toPeg, char auxPeg) {
    if (n == 1) {
        cout << "Move disk 1 from " << fromPeg << " to " << toPeg << endl;
        return;
    }
    towerOfHanoi(n - 1, fromPeg, auxPeg, toPeg);
    cout << "Move disk " << n << " from " << fromPeg << " to " << toPeg << endl;
    towerOfHanoi(n - 1, auxPeg, toPeg, fromPeg);
}

int main() {
    int n;
    cout << "Enter the number of disks: ";
    cin >> n;
    towerOfHanoi(n, 'A', 'C', 'B');
    return 0;
}

