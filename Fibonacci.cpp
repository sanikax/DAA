#include <iostream>
using namespace std;

// Recursive: returns the nth Fibonacci number
int fibRecursive(int n) {
    if (n <= 1)
        return n;
    return fibRecursive(n - 1) + fibRecursive(n - 2);
}

// Non-recursive: prints the first n terms using a loop
void fibIterative(int n) {
    int a = 0, b = 1;
    for (int i = 0; i < n; i++) {
        cout << a << " ";
        int next = a + b;
        a = b;
        b = next;
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter number of terms: ";
    cin >> n;

    cout << "Fibonacci series (recursion): ";
    for (int i = 0; i < n; i++)
        cout << fibRecursive(i) << " ";
    cout << endl;

    cout << "Fibonacci series (without recursion): ";
    fibIterative(n);

    return 0;
}