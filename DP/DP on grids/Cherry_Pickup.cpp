#include<bits/stdc++.h>
using namespace std;


// Cherry Pickup
// https://leetcode.com/problems/cherry-pickup/

/***   Memoization Solution     ***/
int cherryPickupUtil(vector<vector<int>>& grid, int r1, int c1, int c2, vector<vector<vector<int>>> &dp) {
    int r2 = (r1+c1) - c2;
    int n = grid.size();

    if(r1 == r2 and c1 == c2 and r1 == n-1 and c1 == n-1) return grid[n-1][n-1];

    if(r1 == n || r2 ==n || c1 ==n || c2 ==n || grid[r1][c1] == -1 || grid[r2][c2] == -1) {
        return INT_MIN;
    }

    if(dp[r1][c1][c2] != -1) return dp[r1][c1][c2];

    int maxi = INT_MIN;
    int curCost;
    if(r1 == r2 and c1 == c2) {
        curCost = grid[r1][c1];
    }
    else {
        curCost = grid[r1][c1] + grid[r2][c2];
    }


    maxi = max(maxi,cherryPickupUtil(grid,r1+1,c1,c2+1,dp));
    maxi = max(maxi,cherryPickupUtil(grid,r1+1,c1,c2,dp));
    maxi = max(maxi,cherryPickupUtil(grid,r1,c1+1,c2+1,dp));
    maxi = max(maxi,cherryPickupUtil(grid,r1,c1+1,c2,dp));


    return dp[r1][c1][c2] = maxi + curCost;
}
int cherryPickup(vector<vector<int>>& grid) {
    int n = grid.size();
    vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(n+1,vector<int>(n+1,-1)));
    int ans = cherryPickupUtil(grid, 0,0,0, dp);
    if(ans < 0) return 0;
    return ans;
}



/***   Tabulation Solution     ***/

const int INF = 1e9;
int cherryPickup_(vector<vector<int>>& grid) {
    int n = grid.size();
    vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(n+1,vector<int>(n+1,-INF)));

    for(int r1 = n-1; r1 >= 0; r1--) {
        for(int c1 = n-1; c1 >= 0; c1--) {
            for(int c2 = n-1; c2 >= 0; c2--) {
    
                int r2 = r1 + c1 - c2;
                if(r2 < 0 || r2 >= n) continue;


                if(r1 == r2 and c1 == c2 and r1 == n-1 and c1 == n-1){
                    dp[r1][c1][c2] = grid[n-1][n-1]; continue;
                }
    
                if(grid[r1][c1] == -1 || grid[r2][c2] == -1) {
                    continue;
                }
          
                int ans;
                if(r1 == r2 and c1 == c2){
                    ans = grid[r1][c1]; 
                }
                else ans = grid[r1][c1] + grid[r2][c2];

                int sol = dp[r1][c1+1][c2];
                sol = max(sol, dp[r1][c1+1][c2+1]);
                sol = max(sol, dp[r1+1][c1][c2]);
                sol = max(sol, dp[r1+1][c1][c2+1]);

                dp[r1][c1][c2] = ans + sol;
            
            }
        }
    }
    return max(0,dp[0][0][0]);
}
int main(){
    vvi grid = {{1,1,1,1,0,0,0},{0,0,0,1,0,0,0},{0,0,0,1,0,0,1},{1,0,0,1,0,0,0},{0,0,0,1,0,0,0},{0,0,0,1,0,0,0},{0,0,0,1,1,1,1}};
    cout<<cherryPickup_T(grid)<<endl;
}
