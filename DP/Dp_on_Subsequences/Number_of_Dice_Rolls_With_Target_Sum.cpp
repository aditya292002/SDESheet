#include<bits/stdc++.h>
using namespace std;



int mod = 1e9 + 7;
int numRollsToTargetUtil(int n, int dice_no, int k, int target, vector<vector<int>> &dp) {
    if(dice_no == 0) {
        if(target == 0) return 1;
        return 0;
    }

    if(dp[dice_no][target] != -1) return dp[dice_no][target];

    int cnt = 0;
    for(int i = 1; i <= k; i++) {
        if(target - i >= 0) {
            int t = (numRollsToTargetUtil(n, dice_no - 1, k,  target - i, dp) % mod);
            cnt = (cnt + t)%mod;
        } 
    }
    return dp[dice_no][target] = cnt;
}

int numRollsToTarget(int n, int k, int target) {
    vector<vector<int>> dp(n+1 , vector<int>(target + 1, -1));
    return numRollsToTargetUtil(n, n, k, target, dp);
}    

int numRollsToTargetTable(int n, int k, int target) {
    vector<vector<int>> dp(n+1 , vector<int>(target + 1, 0));
    dp[0][0] = 1;

    for(int dice_no = 1; dice_no <= n; dice_no++) {
        for(int tar = 1; tar <= target; tar++) {

            int cnt = 0;
            for(int i = 1; i <= k; i++) {
                if(tar - i >= 0) {
                    int t = (dp[dice_no - 1][tar - i]) % mod;
                    cnt = (cnt + t)%mod;
                }
            }
            dp[dice_no][tar] = cnt;

            // for(int t=1; t<=k; t++)
            // {
            //     if(tar>=t)
            //     {
            //         dp[dice_no][tar] = dp[dice_no][tar] + dp[dice_no-1][tar-t];
            //         dp[dice_no][tar] = dp[dice_no][tar]%mod;
            //     }
            // }
        }
    }
    return dp[n][target]%mod;
}

int main() {
    // cout<<numRollsToTarget(1,6,3)<<endl;
    cout<<numRollsToTargetTable(2,6,7)<<endl;
}
