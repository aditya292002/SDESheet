#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/



int mod = 1e9 + 7;

int numRollsToTargetUtil(int n, int dice_no, int k, int target, vector<vector<int>> &dp) {
    if(dice_no == 0) {
        if(target == 0) return 1;
        return 0;
    }

    if(dp[dice_no][target] != -1) return dp[dice_no][target];

    int cnt = 0;

    // for a given dice consider all the value and then go to next dice and take all possible values for it
    for(int i = 1; i <= k; i++) {
        if(target - i >= 0) {
            int t = (numRollsToTargetUtil(n, dice_no - 1, k,  target - i, dp) % mod);
            cnt = (cnt + t)%mod;
        } 
    }
    return dp[dice_no][target] = cnt;
}

int numRollsToTarget(int n, int k, int target) {
    vector<vector<int>> dp(k+1 , vector<int>(target + 1, -1));
    return numRollsToTargetUtil(n, n, k, target, dp);
}    

int main() {
    cout<<numRollsToTarget(1,6,3)<<endl;
}
