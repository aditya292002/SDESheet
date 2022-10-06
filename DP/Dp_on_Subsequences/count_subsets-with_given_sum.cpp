#include<bits/stdc++.h>
using namespace std;

// Perfect Sum Problem (count the number of subsets with given sum)
// https://practice.geeksforgeeks.org/problems/perfect-sum-problem5633/1

int INF = 1e9 + 7;


// resursion + memoization
int perfectSumUtil(vector<int> arr, int sum, int i, vector<vector<int>> &dp) {
    if(i == 0) {
        if(sum == 0 and arr[i] == 0) return 2;
        if(sum == 0) return 1;
        if(sum == arr[i]) return 1;
        return 0;
    }

    if(dp[i][sum] != -1) return dp[i][sum];

    int notPick = perfectSumUtil(arr, sum , i - 1, dp);
    int pick = 0;
    if(sum >= arr[i]) {
        pick = perfectSumUtil(arr, sum - arr[i], i - 1, dp)%INF;
    }

    return dp[i][sum] = (pick + notPick)%INF;
}

int perfectSum(vector<int> arr, int sum) {
    int n = arr.size();
    vector<vector<int>> dp(n,vector<int>(sum+1,-1));
    return perfectSumUtil(arr,sum,n-1,dp)%INF;
}


// tabulation
int perfectSum_Tabulation(vector<int> arr, int sum) {
    int n = arr.size();
    vector<vector<int>> dp(n,vector<int>(sum+1,0));
    
    
    dp[0][0] = 1;

    if(arr[0] <= sum) {
        if(arr[0] == 0) dp[0][0] = 2;
        else dp[0][arr[0]] = 1;
    }

    for(int i = 1; i < n; i++) {
        for(int j = 0; j <= sum; j++) {
            int notPick = dp[i-1][j];
            int pick = 0;
            if(j >= arr[i]) {
                pick = dp[i-1][j - arr[i]];
            }
            dp[i][j] = (pick + notPick)%INF;
        }
    }

    return dp[n-1][sum];
}

int main() {
    vector<int> arr = {3,1,1,2,5};
    cout<<perfectSum_Tabulation(arr,5)<<endl;
}
