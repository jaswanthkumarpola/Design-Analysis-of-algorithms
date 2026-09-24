#include <iostream>
using namespace std;

int main() {
    int values[] = {60, 100, 120};
    int weights[] = {10, 20, 30};
    int W = 50; 
    int n = 3;  

    int dp[4][51]; 

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
        
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } 
            else if (weights[i - 1] <= w) {
                int include_item = values[i - 1] + dp[i - 1][w - weights[i - 1]];
                int exclude_item = dp[i - 1][w];
                
                dp[i][w] = (include_item > exclude_item) ? include_item : exclude_item;
            } 
            else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    cout << "Maximum value in Knapsack = " << dp[n][W] << "\n";

    return 0;
}