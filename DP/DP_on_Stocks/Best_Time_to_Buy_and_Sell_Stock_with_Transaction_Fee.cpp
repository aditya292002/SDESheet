#include<bits/stdc++.h>
using namespace std;


// Best Time to Buy and Sell Stock with Transaction Fee
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/

int maxProfitUtil(vector<int>& prices, int i, int buy, int fee, vector<vector<int>> &dp) {
    if(i == prices.size()) return 0;

    if(dp[i][buy] != -1) return dp[i][buy]; 

    int profit = 0;
    if(buy) {
        // buy 
        int buy = -prices[i] + maxProfitUtil(prices, i + 1, 0, fee, dp);
        int notBuy = maxProfitUtil(prices, i + 1, 1, fee, dp);
        profit = max(buy, notBuy);
    }
    
    // sell
    else {  
        int sell = prices[i] - fee  + maxProfitUtil(prices, i + 1, 1, fee, dp);
        int notSell = maxProfitUtil(prices, i + 1, 0, fee, dp);
        profit = max(sell, notSell);
    }
    return dp[i][buy] = profit;
}


int maxProfit(vector<int>& prices, int fee) {
    int n = prices.size();   
    vector<vector<int>> dp(n, vector<int>(2,-1));
    int ans =  maxProfitUtil(prices, 0, 1, fee, dp);        
    return ans;
}


int maxProfit_Tabulation(vector<int>& prices, int fee) {
    int n = prices.size();   
    vector<vector<int>> dp(n+1, vector<int>(2,0));

    for(int i = n-1; i >= 0; i--) {
        for(int buy = 0; buy <= 1; buy++) {
            if(buy) {
                int buy_ = -prices[i] + dp[i+1][0];
                int notBuy = dp[i+1][1];
                dp[i][buy] = max(buy_, notBuy);
            }
            else {
                int sell = prices[i] - fee + dp[i+1][1];
                int notSell = dp[i+1][0];
                dp[i][buy] = max(sell, notSell);
            }
        }
    }
    return dp[0][1];
}

// Space Optimization using (2-1D arrays)
int maxProfit_Tabulation_SO(vector<int>& prices, int fee) {
    int n = prices.size();   

    vector<int> curr(2,0);
    vector<int> later(2,0);

    for(int i = n-1; i >= 0; i--) {
        for(int buy = 0; buy <= 1; buy++) {
            if(buy) {
                int buy_ = -prices[i] + later[0];
                int notBuy = later[1];
                curr[buy] = max(buy_, notBuy);
            }
            else {
                int sell = prices[i] - fee + later[1];
                int notSell = later[0];
                curr[buy] = max(sell, notSell);
            }
        }
        later = curr;
    }
    return later[1];
}



int main() {
}

