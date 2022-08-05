#include<bits/stdc++.h>
using namespace std;

// Dp on subsequences 

// check if there is a subset whose sum is equal to the target (subset sum problem)
// https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1  <-- Practice Link 


// Memoization
bool isSubsetSum_(vector<int>arr, int sum, int i, vector<vector<int>> &dp) {
    if (i == (arr.size() - 1)) {
        if(sum == 0 || sum == arr[i]) return 1;
        return 0;
    }

    if(dp[i][sum] != -1) return dp[sum][i]; 

    // pick - notpick
    bool notpick = isSubsetSum_(arr, sum , i+1, dp);
    bool pick = 0;
    if(sum >= arr[i]) {
        pick = isSubsetSum_(arr, sum - arr[i], i+1, dp);
    } 
    return dp[i][sum] =  notpick | pick;
}

bool isSubsetSum_memo(vector<int>arr, int sum){
    int n = arr.size();
    vector<vector<int>> dp(sum+1, vector<int>(n+1,-1));    
    return isSubsetSum_(arr, sum, 0, dp);
}

// ----------------------------------------------------------------------------------------------

// tabulation
bool isSubsetSum(vector<int>arr, int sum) {
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(sum+1,0));

    dp[n-1][0] = 1;
    if(arr[n-1] <= sum) {
        dp[n-1][arr[n-1]] = 1;
    }   

    for(int i = n-2; i >= 0; i--) {
        for(int j = 0; j <= sum; j++) {
            bool notpick = dp[i+1][j], pick = 0;
            if(j >= arr[i]) {
                pick = dp[i+1][j-arr[i]];
            }

            dp[i][j] = pick | notpick;
        }
    } 
    return dp[0][sum];
}


int main() {
    vector<int> arr = {3, 34, 4, 12 ,5,2};
    cout<<isSubsetSum(arr,9)<<endl;
}
