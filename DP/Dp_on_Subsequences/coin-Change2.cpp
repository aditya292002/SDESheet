#include<bits/stdc++.h>
using namespace std;

// Coin Change 2
// https://leetcode.com/problems/coin-change-2/submissions/


// recursion + memoization
int changeUtil(int amount, vector<int>& coins, int i, vector<vector<int>> &dp) {
    if(i == 0) {
        if(amount%coins[0] == 0) return 1;
        return 0;
    }

    if(dp[i][amount] != -1) return dp[i][amount];

    int notpick = changeUtil(amount, coins, i-1, dp);
    int pick = 0;
    if(amount >= coins[i]) {
        pick = changeUtil(amount - coins[i], coins, i, dp);
    }

    return dp[i][amount] = pick + notpick;
}

int change(int amount, vector<int>& coins) {
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount+1,-1));
    return changeUtil(amount, coins, n-1,dp);
}


// tabulation
int change_Tabulation(int amount, vector<int>& coins) {
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount+1,0));
    for(int i = 0; i <= amount; i++) {
        if(i%coins[0] == 0) dp[0][i] = 1;
    }

    for(int i = 1; i < n; i++) {
        for(int j = 0; j <= amount; j++) {
            int notpick = dp[i-1][j];
            int pick = 0;
            if(j >= coins[i]) {
                pick = dp[i][j - coins[i]];
            }

            dp[i][j] = pick + notpick;
        }
    }

    return dp[n-1][amount];
}

// space optimization
int change_Tabulation1(int amount, vector<int>& coins) {
    int n = coins.size();

    vector<int> prev(amount+1,0);
    vector<int> curr(amount+1,0);


    for(int i = 0; i <= amount; i++) {
        if(i%coins[0] == 0) prev[i] = 1;
    }

    for(int i = 1; i < n; i++) {
        for(int j = 0; j <= amount; j++) {
            int notpick = prev[j];
            int pick = 0;
            if(j >= coins[i]) {
                pick = curr[j - coins[i]];
            }

            curr[j] = pick + notpick;
        }
        prev = curr;
    }

    return curr[amount];
}


int main() {
    int amount = 5;
    vector<int> coins = {1,2,5};
    cout<<change_Tabulation1(amount, coins)<<endl;
}
