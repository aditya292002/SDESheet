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
// https://leetcode.com/submissions/detail/681410592/
// https://leetcode.com/submissions/detail/575874453/



int minPathSum(vector<vector<int>>& cost) {
            // debug(cost)
    int N = cost.size();
    int M = cost[0].size();
    vvi dp(N,vector<int>(M,0));
    // debug(dp)
    dp[0][0] = cost[0][0];
    for(int i = 1; i < M; i++){dp[0][i] = cost[0][i] + dp[0][i-1];}
    for(int i = 1; i < N; i++){dp[i][0] = cost[i][0] + dp[i-1][0];}
    // debug(dp)

    for(int i = 1; i < N; i++){
        for(int j = 1; j < M;j++){
            dp[i][j] = cost[i][j] + min(dp[i-1][j],dp[i][j-1]);
        }
   	}
    return dp[N-1][M-1];
}

int main(void){
	
}