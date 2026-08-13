#include <iostream>
using namespace std;

int factorialIterative(int n) {
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}
    int factorialRecursive(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorialRecursive(n - 1);
}

int main() {
    int n = 5;
    cout << "Factorial of " << n << " (Iterative): " << factorialIterative(n) << "\n";
    cout << "Factorial of " << n << " (Recursive): " << factorialRecursive(n) << "\n";
}