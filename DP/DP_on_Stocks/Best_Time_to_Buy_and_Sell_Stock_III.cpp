#include<bits/stdc++.h>
using namespace std;


// recursion + memoization

int maxProfitUtil(vector<int>& prices, int i, int buy, int transactionCount, vector<vector<vector<int>>> &dp) {
    if(i == prices.size()) return 0;
    if(transactionCount == 2) {
        return 0;
    }

    if(dp[i][buy][transactionCount] != -1) return dp[i][buy][transactionCount];

    int profit;
    if(buy) {
        int buy_ = -prices[i] + maxProfitUtil(prices, i+1, 0, transactionCount, dp);
        int notBuy = maxProfitUtil(prices, i+1, 1, transactionCount, dp);
        profit = max(buy_, notBuy);
    }  
    else {
        int sell = prices[i] + maxProfitUtil(prices, i+1, 1, transactionCount+1, dp);
        int notSell = maxProfitUtil(prices, i+1, 0, transactionCount, dp);
        profit = max(sell, notSell);
    }
    return dp[i][buy][transactionCount] = profit;
}

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3,-1)));
    return maxProfitUtil(prices, 0, 1, 0,dp);
}


// tabulation
int maxProfit_Tabulation(vector<int>& prices) {
    int n = prices.size();
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3,0)));

    for(int i = n-1; i >= 0; i--) {
        for(int buy = 1; buy >=0; buy--) {
            for(int tc = 0; tc <= 1; tc++) { // tc -> transaction count
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
int maxProfit_Tabulation_SO(vector<int>& prices) {
    int n = prices.size();
    // vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3,0)));
    vector<vector<int>> later(2, vector<int>(3,0));
    vector<vector<int>> curr(2, vector<int>(3,0));

    for(int i = n-1; i >= 0; i--) {
        
        for(int buy = 1; buy >=0; buy--) {
        
            for(int tc = 0; tc <= 1; tc++) { // tc -> transaction count
        
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


//---------------------------------------------------------------------------------------------------------------------------

// 2nd Approach

// Other solution using using (N X 4) dp
/*      
        4 denotes   
        

        B  S  B  S

        0  1  2  3

        i.e even - buy
            odd  - sell


*/
int maxProfit_Util(vector<int>& prices, int i, int transaction, vector<vector<int>> &dp) {
    if(i == prices.size()) return 0;
    if(transaction == 4) return 0;

    if(dp[i][transaction] != -1) return dp[i][transaction];

    int profit;
    if(transaction % 2 == 0) {
        // buy
        int buy_ = -prices[i] + maxProfit_Util(prices, i + 1, transaction + 1, dp);
        int notBuy = maxProfit_Util(prices, i + 1, transaction, dp);

        profit = max(buy_, notBuy);
    }

    else {
        // sell
        int sell = prices[i] +  maxProfit_Util(prices, i + 1, transaction + 1, dp);
        int notSell = maxProfit_Util(prices, i + 1, transaction, dp);

        profit = max(sell, notSell);
    }

    return dp[i][transaction] = profit;
}
int maxProfit_(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(4,-1));
    return maxProfit_Util(prices,0,0,dp);
}

int maxProfit__Tabulation(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n+1, vector<int>(5,0));

    for(int i = n-1; i >= 0; i--) {
        for(int transaction = 0; transaction <= 3; transaction++) {   
            int profit;
            if(transaction % 2 == 0) {
                // buy 
                int buy_ = -prices[i] + dp[i + 1][transaction + 1];
                int notBuy = dp[i + 1][transaction];

                profit = max(buy_, notBuy);
            }

            else {
                int sell = prices[i] + dp[i + 1][transaction + 1];
                int notSell = dp[i + 1][transaction];

                profit = max(sell, notSell);
            }

            dp[i][transaction]  = profit;
        }
    }
    return dp[0][0];
}


int maxProfit__Tabulation_SO(vector<int>& prices) {
    int n = prices.size();
    // vector<vector<int>> dp(n+1, vector<int>(5,0));
    vector<int> later(5,0);
    vector<int> curr(5,0);

    for(int i = n-1; i >= 0; i--) {
        for(int transaction = 0; transaction <= 3; transaction++) {   
            int profit;
            if(transaction % 2 == 0) {
                // buy 
                int buy_ = -prices[i] + later[transaction + 1];
                int notBuy = later[transaction];

                profit = max(buy_, notBuy);
            }

            else {
                // sell
                int sell = prices[i] + later[transaction + 1];
                int notSell = later[transaction];

                profit = max(sell, notSell);
            }

            curr[transaction]  = profit;
        }
        later = curr;
    }
    return curr[0];
}


int main() {
    vector<int> prices = {3,3,5,0,0,3,1,4};
    cout<<maxProfit__Tabulation_SO(prices)<<endl;
}