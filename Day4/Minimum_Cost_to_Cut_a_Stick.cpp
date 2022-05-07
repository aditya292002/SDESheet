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

template<class T>void printt(vector<T> vec){cout<<" : [ ";for(auto i : vec){cout<<i<<" ";}cout<<"] "<<endl;}
template<class T>void printt(T var){cout<<" : "<<var<<endl;}
template<class T>void printt(vector<vector<T>> vec){cout<<endl;cout<<"["<<endl;for(auto ii : vec){cout<<"[ ";for(auto a : ii){cout<<a<<" ";}cout<<"]"<<endl;}cout<<"]"<<endl;}
void printArray(int arr[], int n){for(int i = 0; i < n; i++){cout<<arr[i]<<" ";}cout<<endl;}
int convert_string_int(string s){
    int ans = 0;
    int n = s.size();
    for(int i = 0; i < n;i++){if(s[i] == '0'){s.substr(1);}else{break;}}
        int tenth = 1;
    for(int i = n-1; i>=0; i--){ans = ans + (tenth*(s[i] - '0'));tenth*=10;}
        return ans;
}

int mod =(int)1e9+7;

/*      
{
    TC = O(n)
    SC = O(n)
}
*/
//----------------------------------------------------------------------------------------------------------------------------------------
//https://leetcode.com/problems/minimum-cost-to-cut-a-stick/

int minCostUtil(vi cuts, int i,int j){
    if(i < j) return 0;
    int mini = INT_MAX;
    for(int idx = i; idx <= j; idx++){
        int sol = cuts[j+1] - cuts[i-1] + minCostUtil(cuts,i,idx-1) + minCostUtil(cuts,idx+1,j);
        mini = min(mini,sol);
    }
    return mini;
}

int minCostUtil(vi cuts, int i,int j, vvi &dp){
    if(i > j) return 0;
    if(dp[i][j] != -1){return dp[i][j];}
    int mini = INT_MAX;
    for(int idx = i; idx <= j; idx++){
        int cost = (cuts[j+1] - cuts[i-1]) + minCostUtil(cuts,i,idx-1,dp) + minCostUtil(cuts,idx+1,j,dp);
        mini = min(mini,cost);
    }
    return dp[i][j] = mini;
}
    
    
//mincost  tabulatiom
int minCost(int n, vi &cuts){
    int c = cuts.size();
    cuts.push_back(n);
    cuts.insert(cuts.begin(),0);
    sort(cuts.begin(),cuts.end());
    vector<vector<int>> dp(c+2,vector<int>(c+2,0));
    for(int i = c; i >= 1; i--){
        for(int j = 1; j <= c; j++){
            if(i > j) continue;
            int mini = INT_MAX;
            for(int ind = i ; ind <= j; ind++){
                int cost = cuts[j+1] - cuts[i-1] + dp[i][ind-1] + dp[ind+1][j];
                mini = min(mini,cost);
            }
            dp[i][j] = mini;
        }
    }
    return dp[1][c];
    
}

int main(){
    
}