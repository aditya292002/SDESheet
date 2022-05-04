
//leetcode submission links

//Memoization solution
// https://leetcode.com/submissions/detail/680825007/

//Tabulation solution
// https://leetcode.com/submissions/detail/680838752/


#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vector<int>>
#define vvvi vector<vector<vector<int>>>
#define vs vector<string>
#define vvs vector<vs>
#define pb push_back
#define ppb pop_back
#define pii pair<int,int>
#define ff first
#define ss second
#define debug(a) cout<<#a<<" ";printt(a);cout<<endl;
#define ll long long
#define FOR(i,s,e) for(int i = s; i < e;i++)
#define ll long long
#define vs vector<string>
#define nline cout<<endl;
#define sort_(arr) sort(arr.begin(),arr.end());

int uniquePaths1(int row, int col, vvi &dp){
    if(row == 0 and col == 0){return 1;}

    if(dp[row][col] != -1){return dp[row][col];}
    else if(dp[col][row] != -1){return dp[col][row];}

    int right = 0 ; 
    int down = 0;
    if(row > 0){
        down = uniquePaths1(row-1,col,dp);
    }
    if(col > 0){
        right = uniquePaths1(row,col-1,dp);
    }
    int ans = right + down;
    dp[row][col] = dp[col][row] = ans;
    return ans;
}

//tabulation
int uniquePaths_T(int row, int col){
    int maxi = max(row+1,col+1);
    vvi dp(maxi,vi(maxi,-1));
    for(int i = 0; i <= row; i++){
        for(int j = 0 ;j <= col; j++){
            if(dp[i][j] == -1){
                if(i == 0 || j == 0){
                    dp[i][j] = 1;
                }
                else{
                    int right = dp[i][j-1];
                    int down = dp[i-1][j];
                    dp[i][j] = dp[j][i] = right+down;
                }
            }
        }
    }
    return dp[row][col];
}


int main(){

}