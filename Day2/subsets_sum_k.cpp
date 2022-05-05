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


//count the number of subsets that sum to k 

        // 1. when zeros is not present in the array
int findWays(vector<int> &num, int tar)
{
    int n = num.size();
    vector<vector<int>> dp(n,vector<int>(tar+1,0));
    //for each row if target = 0
    for(int i = 0; i < n; i++){
        dp[i][0] = 1;
    }

    for(int i = 1 ; i <= tar; i++){
        if(i == num[0]){
            dp[0][i] = 1;
        }
    }

    for(int i = 1; i < n; i++){
        for(int j = 1; j <= tar; j++){

            int pick = 0, not_pick = 0;
            not_pick = dp[i-1][j];
            if(j >= num[i]){
                pick = dp[i-1][j-num[i]];
            }

            dp[i][j] = not_pick + pick;
        }
    }

    return dp[n-1][tar];
}


//  2.   when zeros is present in the array
int count_Subset_K_1(int n,int target, vi &arr, vvi &dp){
    if(target == 0){return 1;}
    if(n == 0){
        if(target == arr[0]){
            return 1;
        }
        return 0;
    }

    if(dp[n][target] != -1){return dp[n][target];}

    int pick = 0, not_pick = 0;
    not_pick = count_Subset_K_1(n-1,target,arr,dp);
    if(target >= arr[n]){
        pick = count_Subset_K_1(n-1,target - arr[n],arr,dp);
    }

    return dp[n][target] = pick + not_pick;
}



int findWays_Table(vector<int> &num, int tar)
{
    int n = num.size();
    vector<vector<int>> dp(n,vector<int>(tar+1,0));

    if(num[0] == 0){
        dp[0][0] = 2;
    }
    else{
        dp[0][0] = 1;
    }

    for(int i = 1 ; i <= tar; i++){
        if(i == num[0]){
            dp[0][i] = 1;
        }
    }

    for(int i = 1; i < n; i++){
        for(int j = 0; j <= tar; j++){

            int pick = 0, not_pick = 0;
            not_pick = dp[i-1][j];
            if(j >= num[i]){
                pick = dp[i-1][j-num[i]];
            }

            dp[i][j] = (not_pick + pick)%mod;
        }
    }

    return dp[n-1][tar];
}



int main(){

}