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
// #define f(n) for(int i = 0;i<n;i++)
#define nline cout<<endl;
#define sort_(arr) sort(arr.begin(),arr.end());


//count the number of subsets with given difference
//or
//Partitions With Given Difference

int mod = (int)(1e9+7);
int f(int n,int target, vi &arr, vvi &dp){
     if(n == 0){
        if(target==0 && arr[0]==0)
            return 2;
        if(target==0 || target == arr[0])
            return 1;
        return 0;
    }

    if(dp[n][target] != -1){return dp[n][target];}

    int pick = 0, not_pick = 0;
    not_pick = f(n-1,target,arr,dp);
    if(target >= arr[n]){
        pick = f(n-1,target - arr[n],arr,dp);
    }   

    return dp[n][target] = (pick + not_pick)%mod;
}

int fT(int n, int target, vi &arr){
    int dp[n][target+1];

    dp[0][0] = 1;
    if(target == 0 && arr[0] == 0){
        dp[0][0] = 2;
    }
    else if(target >= arr[0]){
        dp[0][target] = 1;
    }


    for(int i = 1; i < n; i++){
        for(int j = 0; j <= target; j++){    

            int pick = 0, not_pick = 0;
            not_pick = dp[i-1][j];
            if(j >= arr[i]){
                pick = dp[i-1][j-arr[i]];
            }

            dp[i][j] = (pick + not_pick)%mod;

        }
    }


    return dp[n-1][target];
}


int countPartitions(int n, int d, vector<int>& arr){
//     int n = arr.size();
    int totSum = 0;
    for(int i=0; i<arr.size();i++){
        totSum += arr[i];
    }
    
    //Checking for edge cases
    if(totSum-d<0) return 0; //ckecking if difference is greater than total value
    if((totSum-d)%2==1) return 0;   //checking if total sum is even -- only then the set can be divided in two subsets
    
    int s2 = (totSum-d)/2;
    
    vector<vector<int>> dp(n,vector<int>(s2+1,-1));
//     return countPartitionsUtil(n-1,s2,arr,dp);
    return f(n-1,s2,arr,dp);
}


int main(){
	
}