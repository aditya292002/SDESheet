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
// https://leetcode.com/submissions/detail/681311524/


int mod = (int)(2*1e9);
int f(int n, int m, vector< vector< int> > &mat){
    int dp[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if((i == 0 && j == 0) and (mat[i][j] != 1)){ dp[i][j] = 1;continue;}
            // else{dp[i][j] = 0; continue;}
            
            if(mat[i][j] == 1){dp[i][j] = 0; continue;}
            int left = 0; int up = 0;
            if(i != 0){
                up = dp[i-1][j];
            }
            if(j != 0){
                left = dp[i][j-1]; 
            }
            dp[i][j] = (up+left)%mod;
        }

    }
    return dp[n-1][m-1];
}

int main(void){
	
}