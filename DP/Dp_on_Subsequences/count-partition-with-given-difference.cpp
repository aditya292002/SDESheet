#include<bits/stdc++.h>
using namespace std;


// Target Sum ( count partition with given diff )
// https://leetcode.com/problems/target-sum/

/*
    
    sum1 + sum2 = total   (sum1 = total sum of subset1, sum2 = total sum of subset2)


     sum1 - sum2 = target

or,  sum1 - (total - sum1) = target

or,  2*sum1 - total = target

or,  sum1 = (target + total)/2


*/

int findTargetSumWays(vector<int>& arr, int target) {
    int n = arr.size();
    int total = accumulate(arr.begin(),arr.end(),0);

    // edge cases
    target = abs(target);
    if(target > total) return 0;


    vector<vector<int>> dp(n,vector<int>(total+1,0));

    // base case
    dp[0][0] = 1;

    if(arr[0] <= total) {
        if(arr[0] == 0) dp[0][0] = 2;
        else dp[0][arr[0]] = 1;
    }
    //

    for(int i = 1; i < n; i++) {
        for(int j = 0; j <= total; j++) {
            int notPick = dp[i-1][j];
            int pick = 0;
            if(j >= arr[i]) {
                pick = dp[i-1][j - arr[i]];
            }
            dp[i][j] = (pick + notPick) ;
        }
    }


    if((target + total)%2 != 0) return 0;
    int sum1 = (total + target)/2;
    return dp[n-1][sum1];
}



int main() {
    vector<int>  nums = {100};
    int target = -200;
    cout<<findTargetSumWays(nums, 1)<<endl;
}
