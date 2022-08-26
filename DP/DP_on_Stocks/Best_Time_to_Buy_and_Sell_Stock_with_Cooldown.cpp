#include<bits/stdc++.h>
using namespace std;

// Best Time to Buy and Sell Stock with Cooldown
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/  


// 0 -> sell
// 1 -> buy
// 2 -> coolDown

int maxProfitUtil(vector<int>& prices, int i, int buy, vector<vector<int>> &dp) {
    if(i == prices.size()) return 0;

    if(dp[i][buy] != -1) return dp[i][buy]; 

    int profit = 0;
    if(buy == 1) {
        // buy 
        int buy = -prices[i] + maxProfitUtil(prices, i + 1, 0,dp);
        int notBuy = maxProfitUtil(prices, i + 1, 1, dp);
        profit = max(buy, notBuy);
    }
    
    // sell
    else if(buy == 0) {
        int sell = prices[i] + maxProfitUtil(prices, i + 1, 2, dp);
        int notSell = maxProfitUtil(prices, i + 1, 0, dp);
        profit = max(sell, notSell);
    }
    else {
        profit = maxProfitUtil(prices, i + 1, 1, dp);
    }
    return dp[i][buy] = profit;
}

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(3,-1));
    return maxProfitUtil(prices, 0, 1, dp);    
}


int maxProfit_Tabulation(vector<int>& prices) {
    int n = prices.size();   
    vector<vector<int>> dp(n+1, vector<int>(3,0));

    for(int i = n-1; i >= 0; i--) {
        for(int buy = 0; buy <= 2; buy++) {
            if(buy == 1) {
                int buy_ = -prices[i] + dp[i+1][0];
                int notBuy = dp[i+1][1];
                dp[i][buy] = max(buy_, notBuy);
            }
            else if(buy == 0) {
                int sell = prices[i] + dp[i+1][2];
                int notSell = dp[i+1][0];
                dp[i][buy] = max(sell, notSell);
            }
            else {
                dp[i][buy] = dp[i+1][1];
            }
        }
    }
    return dp[0][1];
}


int main() {

}

