#include<bits/stdc++.h>
using namespace std;

//---------------------------------------------------------------------------------------------------------------------
/*
-- Coin Change
-- https://leetcode.com/problems/coin-change/

-- 2 Approaches 
   1) Dynamic Programming
   2) BFS

   // Both Solutions Below
*/

//---------------------------------------------------------------------------------------------------------------------
// recursion + memoization
int coinChangeUtil(vector<int>& coins, int amount, int i, vector<vector<int>> &dp) {
    if(i == 0) {
        if(amount % coins[0] == 0) {
            return amount/coins[i];
        }
        return 1e9;  
    }

    if(dp[i][amount] != -1) return dp[i][amount];

    int notpick = coinChangeUtil(coins, amount, i-1,dp);   // not pick current element, then go ahead to pick next one
    int pick = 1e9;

    if(amount >= coins[i]) {
        pick = 1 + coinChangeUtil(coins, amount - coins[i], i,dp); // if pick current element, then we can pick it again
    } 

    return dp[i][amount] = min(pick, notpick);
}

int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount+1,-1));

    if(amount == 0) return 0;
    int ans = coinChangeUtil(coins, amount, n-1, dp);
    if(ans == 0) return -1;
    return ans;
}


// Tabulation
int coinChange_Tabulation(vector<int>& coins, int amount) {
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount+1,-1));

    if(amount == 0) return 0;
    for(int i = 0; i <= amount; i++) {
        if(i % coins[0] == 0) {
            dp[0][i] = i/coins[0];
        }
        else dp[0][i] = 1e9;
    }

    for(int i = 1; i < n; i++) {
        for(int j = 0; j <= amount; j++) {
            int notpick = dp[i-1][j];
            int pick = 1e9;

            if(j >= coins[i]) {
                pick = 1 + dp[i][j - coins[i]];
            }

            dp[i][j] = min(pick , notpick);
        }
    }
    if(ans == 1e9) return -1;
    return ans;
}

// -------------------------------------------------------------------------------------------------------------------

// bfs solution
int coinChange(vector<int>& coins, int amount) {
    if(amount == 0) return 0;
    vector<int> vis(amount+1,0);
    queue<int> q;
    q.push(amount);
    vis[amount] = 1;

    int level = 0;  
    while(!q.empty()) {

        level++;   // Keeping track of level 
        int queueSize = q.size();    

        for(int i = 0; i < queueSize; i++) {
            int node = q.front();
            q.pop();

            for(int i : coins) {
                if(node - i >= 0 and !vis[node - i]) {
                    if(node - i == 0) return level;
                    vis[node - i] = 1;
                    q.push(node - i);
                }
            }
        }

    }

    return -1;
}


int main() {
    vi coins = {3,5};
    int amount = 20;
    cout<<coinChange_Tabulation(coins, amount)<<endl;
}
