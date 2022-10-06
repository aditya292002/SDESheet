#include<bits/stdc++.h>
using namespace std;

// Best Time to Buy and Sell Stock IV
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

int maxProfitUtil(vector<int>& prices, int i, int buy, int transactionCount, int k, vector<vector<vector<int>>> &dp) {
    if(i == prices.size()) return 0;
    if(transactionCount == k) {
        return 0;
    }

    if(dp[i][buy][transactionCount] != -1) return dp[i][buy][transactionCount];

    int profit;
    if(buy) {
        int buy_ = -prices[i] + maxProfitUtil(prices, i+1, 0, transactionCount, k, dp);
        int notBuy = maxProfitUtil(prices, i+1, 1, transactionCount, k, dp);
        profit = max(buy_, notBuy);
    }  
    else {
        int sell = prices[i] + maxProfitUtil(prices, i+1, 1, transactionCount+1, k, dp);
        int notSell = maxProfitUtil(prices, i+1, 0, transactionCount, k, dp);
        profit = max(sell, notSell);
    }
    return dp[i][buy][transactionCount] = profit;
}

int maxProfit(int k, vector<int>& prices) {
    int n = prices.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k+1,-1)));
    return maxProfitUtil(prices, 0, 1, 0, k, dp);
}


// tabulation
int maxProfit_Tabulation(int k, vector<int>& prices) {
    int n = prices.size();
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1,0)));

    for(int i = n-1; i >= 0; i--) {
        for(int buy = 1; buy >=0; buy--) {
            for(int tc = 0; tc <= k-1; tc++) { // tc -> transaction count
                int profit;
                if(buy) {
                    int buy_ = -prices[i] + dp[i+1][0][tc];
                    int notBuy = dp[i+1][1][tc];
                    profit = max(buy_, notBuy);
                }
                else {
                    int sell = prices[i] + dp[i+1][1][tc+1];
                    int notSell = dp[i+1][0][tc];
                    profit = max(sell, notSell);
                }
                dp[i][buy][tc] = profit;
            }
        }
    }
    return dp[0][1][0]; //maxProfitUtil(prices, 0, 1, 0,dp)  

    // tabulation is bottom up - opposite of recursion
}



//  space optimization
int maxProfit_Tabulation_SO(int k, vector<int>& prices) {
    int n = prices.size();

    vector<vector<int>> later(2, vector<int>(k+1,0));
    vector<vector<int>> curr(2, vector<int>(k+1,0));

    for(int i = n-1; i >= 0; i--) {
        
        for(int buy = 1; buy >=0; buy--) {
        
            for(int tc = 0; tc <= k-1; tc++) { // tc -> transaction count
        
                int profit;
        
                if(buy) {
                    
                    int buy_ = -prices[i] + later[0][tc];

                    int notBuy = later[1][tc];
                    
                    profit = max(buy_, notBuy);
                }
                else {
                    
                    int sell = prices[i] + later[1][tc+1];
                    
                    int notSell = later[0][tc];
                    
                    profit = max(sell, notSell);
                }
                curr[buy][tc] = profit;
            }
        }
        later = curr;
    }

    return later[1][0]; 
}



int main() {

}