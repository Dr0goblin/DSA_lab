#include <iostream>
using namespace std;

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    int n;
    cout << "Enter the position (n) to find the nth term of Fibonacci series: ";
    cin >> n;
    cout << "Fibonacci term at position " << n << " is: " << fibonacci(n) << endl;
    return 0;
}

