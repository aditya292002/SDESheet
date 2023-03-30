#include <bits/stdc++.h>
using namespace std;


// recursion

int knapsackRecursion(int W, int wt[], int val[], int n) {
    if (n == 0 || W == 0)
        return 0;
    if (wt[n - 1] > W)
        return knapsackRecursion(W, wt, val, n - 1);
    else
        return max(val[n - 1] + knapsackRecursion(W - wt[n - 1], wt, val, n - 1), knapsackRecursion(W, wt, val, n - 1));
}



// memoization

int knapsackMemoization(int W, int wt[], int val[], int n, int** dp) {
    if (n == 0 || W == 0)
        return 0;
    if (dp[n][W] != -1)
        return dp[n][W];
    if (wt[n - 1] > W)
        return dp[n][W] = knapsackMemoization(W, wt, val, n - 1, dp);
    else
        return dp[n][W] = max(val[n - 1] + knapsackMemoization(W - wt[n - 1], wt, val, n - 1, dp), knapsackMemoization(W, wt, val, n - 1, dp));
}

int knapsackMemoizationDriver(int W, int wt[], int val[], int n) {
    int** dp = new int*[n + 1];
    for (int i = 0; i <= n; i++) {
        dp[i] = new int[W + 1];
        for (int j = 0; j <= W; j++)
            dp[i][j] = -1;
    }
    return knapsackMemoization(W, wt, val, n, dp);
}


// tabulation
int knapsackTabulation(int W, int wt[], int val[], int n) {
    int dp[n + 1][W + 1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (wt[i - 1] > j)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
        }
    }
    return dp[n][W];
}

int main() {
    int W = 50;
    int wt[] = {10, 20, 30};
    int val[] = {60, 100, 120};
    int n = sizeof(wt) / sizeof(wt[0]);

    // Testing knapsackRecursion
    cout << "Using knapsackRecursion: " << knapsackRecursion(W, wt, val, n) << endl;

    // Testing knapsackMemoization
    cout << "Using knapsackMemoization: " << knapsackMemoizationDriver(W, wt, val, n) << endl;

    // Testing knapsackTabulation
    cout << "Using knapsackTabulation: " << knapsackTabulation(W, wt, val, n) << endl;

    return 0;
}