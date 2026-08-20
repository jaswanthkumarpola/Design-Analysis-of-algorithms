#include<iostream>
using namespace std;

int getMax(int a, int b) {
    return (a > b) ? a : b;
}
int knapSack(int weight[], int value[], int capacity, int n, int** dp) {
    if (n == 0 || capacity == 0) {
        return 0;
    }

    if (dp[n][capacity] != -1) {
        return dp[n][capacity];
    }

    if (weight[n - 1] > capacity) {
        dp[n][capacity] = knapSack(weight, value, capacity, n - 1, dp);
        return dp[n][capacity];
    }

    int include = value[n - 1] + knapSack(weight, value, capacity - weight[n - 1], n - 1, dp);
    int exclude = knapSack(weight, value, capacity, n - 1, dp);
    

    dp[n][capacity] = getMax(include, exclude);
    return dp[n][capacity];
}

int main() {
    int weight[] = {18, 15, 10};
    int value[] = {25, 24, 15};
    int capacity = 20;
    
    int n = sizeof(weight) / sizeof(weight[0]);

    int** dp = new int*[n + 1];
    for (int i = 0; i <= n; i++) {
        dp[i] = new int[capacity + 1];
        for (int j = 0; j <= capacity; j++) {
            dp[i][j] = -1; 
        }
    }
    cout << knapSack(weight, value, capacity, n, dp) << "\n";
    for (int i = 0; i <= n; i++) {
        delete[] dp[i];
    }
    delete[] dp;

    return 0;
}