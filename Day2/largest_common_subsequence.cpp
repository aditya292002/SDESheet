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

int lcsUtil(int i1, int i2, string s1, string s2, vvi &dp){
    if(i1 < 0 or i2 < 0){return 0;}

    if(dp[i1][i2] != -1){return dp[i1][i2];}

    if(s1[i1] == s2[i2]){
        return dp[i1][i2] = 1 + lcsUtil(i1 - 1, i2 - 1, s1, s2, dp);
    }

    return dp[i1][i2] = max(lcsUtil(i1 - 1, i2, s1, s2, dp) , lcsUtil(i1, i2 - 1, s1, s2, dp));
}

//shifting of index
//we cannot represent idx < 0 using a 2d array
//meaning i = i - 1
int lcsUtil_1(int i1, int i2, string s1, string s2, vvi &dp){
    if(i1 == 0 or i2 == 0){return 0;}

    if(dp[i1][i2] != -1){return dp[i1][i2];}

    if(s1[i1-1] == s2[i2-1]){
        return dp[i1][i2] = 1 + lcsUtil_1(i1 - 1, i2 - 1, s1, s2, dp);
    }

    return dp[i1][i2] = max(lcsUtil_1(i1 - 1, i2, s1, s2, dp) , lcsUtil_1(i1, i2 - 1, s1, s2, dp));
}


int lcsUtil_T(string s1, string s2){
    int n = s1.size();
    int m = s2.size();
    vvi dp(n+1,vi(m+1,0));
    for(int i = 0; i <= n;i++){
        dp[i][0] = 0;
    }
    for(int i = 0; i <= m; i++){
        dp[0][i] = 0;
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m ;j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j]  = 1 + dp[i-1][j-1];
            }
            else 
                dp[i][j]  =  0 + max(dp[i-1][j] , dp[i][j-1]);
        }
    }
    return dp[n][m];
}

int main(){

}