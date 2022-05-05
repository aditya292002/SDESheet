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

//Wildcard Pattern Matching
//https://leetcode.com/problems/wildcard-matching/submissions/
int wildcardMatching_Util(string patt, string s, int i , int j, vvi &dp){
    if(i < 0){
        if(j < 0){return 1;}
        return 0;
    }
    if(j < 0){
        for(int k = 0; k <= i; k++){
            if(patt[k] != '*'){return 0;}
        }
        return 1;
    }

    if(dp[i][j] != -1){return dp[i][j];}

    if(patt[i] == s[j] || patt[i] == '?'){
        return dp[i][j] = wildcardMatching_Util(patt,s,i-1,j-1,dp);
    }
    else if(patt[i] == '*'){
        return dp[i][j] = wildcardMatching_Util(patt,s,i,j-1,dp) || wildcardMatching_Util(patt,s,i-1,j,dp);
    }

    return 0;
}

//shifting of index
int wildcardMatching_Util_1(string patt, string s, int i , int j, vvi &dp){
    if(i == 0){
        if(j == 0){return 1;}
        return 0;
    }
    if(j == 0){
        for(int k = 0; k < i; k++){
            if(patt[k] != '*'){return 0;}
        }
        return 1;
    }

    if(dp[i][j] != -1){return dp[i][j];}

    if(patt[i-1] == s[j-1] || patt[i-1] == '?'){
        return dp[i][j] = wildcardMatching_Util_1(patt,s,i-1,j-1,dp);
    }
    else if(patt[i-1] == '*'){
        return dp[i][j] = wildcardMatching_Util_1(patt,s,i,j-1,dp) || wildcardMatching_Util_1(patt,s,i-1,j,dp);
    }

    return 0;
}

//tabulation
int wildcardMatching_Util_T(string patt, string s){
    int n = patt.size();
    int m = s.size();

    vvi dp(n+1,vi(m+1,0));
    dp[0][0] = 1;

    for(int i = 1; i <= n; i++){
        int flag = 1;
        for(int k = 0; k < i; k++){
            if(patt[k] != '*'){ dp[i][0] = 0;flag = 0; break;}
        }
        if(flag) dp[i][0] = 1;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(patt[i-1] == s[j-1] || patt[i-1] == '?'){
                dp[i][j] = dp[i-1][j-1];
            }
            else if(patt[i-1] == '*'){
                dp[i][j] = dp[i][j-1] | dp[i-1][j];
            }
            else{
                dp[i][j] = 0;
            }
        }
    }
    return dp[n][m];
}

//space optimization
int wildcardMatching_Util_T_1(string patt, string s){
    int n = patt.size();
    int m = s.size();

    // vvi dp(n+1,vi(m+1,0));
    vi prev(m+1,0) , curr(m+1,0);
    prev[0] = 1;

    // for(int i = 1; i <= n; i++){
        int flag = 1;
        for(int k = 0; k < 1; k++){
            if(patt[k] != '*'){ curr[0] = 0;flag = 0; break;}
        }
        if(flag) curr[0] = 1;
    // }

    for(int i = 1; i <= n; i++){

        int flag = 1;
        for(int k = 0; k < i; k++){
            if(patt[k] != '*'){ curr[0] = 0;flag = 0; break;}
        }
        if(flag) curr[0] = 1;

        for(int j = 1; j <= m; j++){
            if(patt[i-1] == s[j-1] || patt[i-1] == '?'){
                curr[j] = prev[j-1];
            }
            else if(patt[i-1] == '*'){
                curr[j] = curr[j-1] | prev[j];
            }
            else{
                curr[j] = 0;
            }
        }
        prev = curr;
    }
    return prev[m];
}


int main(){

}