#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vector<int>>
#define vs vector<string>
#define vvs vector<vs>
#define pb push_back
#define ppb pop_back
#define debug(a) cout<<#a<<" ";printt(a);cout<<endl;
#define ll long long
#define FOR(i,s,e) for(int i = s; i < e;i++)
#define ll long long
#define vs vector<string>
#define nline cout<<endl;
#define sort_(arr) sort(arr.begin(),arr.end());

// minimum cost path
int minCostUtil(int i, int j, vvi &mat,vvi &dp){
    if(i == 0 and j == 0){
        return mat[0][0];
    }
    if(i < 0 || j < 0){return 1e9;}

    if(dp[i][j] != -1){return dp[i][j];}

    int up = mat[i][j] + minCostUtil(i-1,j,mat,dp);
    int left = mat[i][j] + minCostUtil(i,j-1,mat,dp);
    int dg = mat[i][j] + minCostUtil(i-1,j-1,mat,dp);

    return dp[i][j] = min(up,min(left,dg));
}

int minCostUtil_T(vvi &mat, int x, int y){
    int dp[x][y];
    dp[0][0] = mat[0][0];

    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            if(i == 0 and j == 0){
                dp[i][j] = mat[0][0];
            }
            else{

                int up = INT_MAX , left = INT_MAX, dg = INT_MAX;
                if(i-1 >= 0){
                    up = mat[i][j] + dp[i-1][j];
                }
                if(j-1 >= 0){
                    left = mat[i][j] + dp[i][j-1];
                }
                if(i-1 >= 0 and j-1 >= 0){
                    dg = mat[i][j] + dp[i-1][j-1];
                }

                dp[i][j] = min(up,min(left,dg));
            }
        }
    }
    return dp[x-1][y-1];
}

int main(){
    
}