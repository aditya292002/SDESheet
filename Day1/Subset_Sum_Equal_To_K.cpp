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

//dp on subsequences
// Subset Sum Equal To K
//https://www.codingninjas.com/codestudio/problems/subset-sum-equal-to-k_1550954?leftPanelTab=0

int subset_sumk(int n, int target, vi &arr, vvi &dp){
    if(target == 0){return true;}
    if(n == 0){
        if(target == arr[0]){return true;}
        return false;
    }

    if(dp[n][target] != -1){return dp[n][target];}

    bool not_pick = subset_sumk(n-1,target,arr,dp);
    bool pick = false;
    if(target >= arr[n]){
        pick = subset_sumk(n-1,target-arr[n],arr,dp);
    } 
    return dp[n][target] = pick || not_pick;
}

//tabulation
//can be space optimized as only uses index i-1
bool subset_sumkT(int n, int target, vi arr){
    vector<vector<bool>> dp(n,vector<bool>(target+1,0));
    for(int i = 0; i < n;i++){
        dp[i][0] = true;
    }
    for(int i = 1; i <= target; i++){
        if(i == arr[0])
            dp[0][i] = true;
        
        else 
            dp[0][i] = false;
    }
    for(int i = 1; i < n; i++){
        for(int j = 1; j <= target; j++){
            bool not_pick = dp[i-1][j];
            bool pick = false;

            if(j >= arr[i]){    
                pick = dp[i-1][j-arr[i]];
            }
            dp[i][j] = not_pick || pick;
        }
    }
    // debug(dp)
    return dp[n-1][target];
}


int main(){
	
}