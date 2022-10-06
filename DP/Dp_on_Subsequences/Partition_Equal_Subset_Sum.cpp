#include<bits/stdc++.h>
using namespace std;


// Partition Equal Subset Sum
// https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1

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

int equalPartition(int N, int arr[])
{
    // code here
    vector<int> arr1;
    int tot = 0;
    for(int i = 0; i < N; i++) {
        arr1.push_back(arr[i]);
        tot += arr[i];
    }
    
    if(tot%2  == 0) {
        bool ans = isSubsetSum(arr1,tot/2);
        if(ans) return 1;
    }
    return 0;
}

int main() {

}
