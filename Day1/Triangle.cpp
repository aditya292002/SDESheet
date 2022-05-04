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


//leetcode submission link

// https://leetcode.com/submissions/detail/681973392/
// https://leetcode.com/submissions/detail/681517028/

//Memoization Solution
int f(int n, int i, int j, vvi &triangle, vvi &dp){
    if(i == n-1){return triangle[i][j];}

    if(dp[i][j] != -1){return dp[i][j];}

    int d = triangle[i][j] + f(n,i+1,j,triangle,dp);
    int dg = triangle[i][j] + f(n,i+1,j+1,triangle,dp);

    return dp[i][j] = min(d,dg);
}



//Tabulation solution with space optimization
int f_S(int n, vvi &triangle){
    // vvi dp(n,vi(n,-1));
    vi dp(n);
    for(int i = 0; i < n; i++){
        dp[i] = triangle[n-1][i];
    }
    for(int i = n-2; i >= 0; i--){
        vi temp(n);
        for(int j = 0; j <= i; j++){
            int d = triangle[i][j] + dp[j];
            int dg = triangle[i][j] + dp[j+1];

            temp[j] = min(d,dg);
        }
        dp = temp;
    }
    return dp[0];
}


int main(){

}