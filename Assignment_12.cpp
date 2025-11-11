CIA 3 -Capstone Project: Develop and implement a solution for the 
given problem using dynamic programming approach. 
The project should be coded on a chosen programming platform and 
all code must be updated and maintained in a GitHub repository for 
version control and collaboration. 
#include <iostream>
#include <vector>
using namespace std;

// Function to solve 0/1 Knapsack Problem using Dynamic Programming
int knapsack(int W, vector<int>& wt, vector<int>& val, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Build table dp[][] bottom-up
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (wt[i - 1] <= w)
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    return dp[n][W];
}

int main() {
    vector<int> val = {60, 100, 120};
    vector<int> wt = {10, 20, 30};
    int W = 50;
    int n = val.size();

    cout << "Maximum value in Knapsack (using DP): " << knapsack(W, wt, val, n) << endl;
    return 0;
}
