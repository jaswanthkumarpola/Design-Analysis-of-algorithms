#include <iostream>

using namespace std;

// Function to find the minimum number of scalar multiplications needed
int matrixChainOrder(int p[], int n) {
    // m[i][j] stores minimum number of scalar multiplications
    // needed to compute the matrix A[i]A[i+1]...A[j]
    // The matrix Ai has dimension p[i-1] x p[i]
    int m[100][100]; // using simple 2D array, assuming max 100 matrices

    int i, j, k, L, q;

    // cost is zero when multiplying one matrix
    for (i = 1; i < n; i++) {
        m[i][i] = 0;
    }

    // L is chain length
    for (L = 2; L < n; L++) {
        for (i = 1; i < n - L + 1; i++) {
            j = i + L - 1;
            m[i][j] = 999999999; // Used instead of INT_MAX
            
            for (k = i; k <= j - 1; k++) {
                // q = cost/scalar multiplications
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                }
            }
        }
    }

    // Return the minimum cost to multiply the entire chain from A1 to An-1
    return m[1][n - 1];
}

int main() {
    // Dimensions of the matrices in the chain
    // Example: A1 is 1x2, A2 is 2x3, A3 is 3x4, A4 is 4x3
    int arr[] = {1, 2, 3, 4, 3};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Minimum number of multiplications is: " << matrixChainOrder(arr, size) << endl;

    return 0;
}
