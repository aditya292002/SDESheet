#include<bits/stdc++.h>
using namespace std;

// Best Time to Buy and Sell Stock
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/    <<-- Practice Link 

/*
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<int> maxOnLeftSide(n+1);
    int maxi = 0;
    for(int i = n-1; i >= 0; i--) {
        if(maxi > prices[i]) {
            maxOnLeftSide[i] = maxi; 
        }
        else {
            maxi = prices[i];
        }
    }    
    int ans = 0;
    for(int i = 0; i < n; i++) {
        ans = max(ans, maxOnLeftSide[i] - prices[i]);
    }   
    return ans;
}
*/

//  code in short
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    int maxi = 0;
    int ans = 0;
    for(int i = n-1; i >= 0; i--) {
        if(maxi > prices[i]) { 
            ans = max(ans, maxi - prices[i]);
        }
        else {
            maxi = prices[i];
        }
    }     
    return ans;
}

int main() {
}