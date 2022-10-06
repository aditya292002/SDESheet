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


int dir[2][2] = {{1, 0}, {0, 1}};
const int INF = 1e9;

template<class T>void printt(vector<T> vec){cout<<" : [ ";for(auto i : vec){cout<<i<<" ";}cout<<"] "<<endl;}
template<class T>void printt(T var){cout<<" : "<<var<<endl;}
template<class T>void printt(vector<vector<T>> vec){cout<<endl;cout<<"["<<endl;for(auto ii : vec){cout<<"[ ";for(auto a : ii){cout<<a<<" ";}cout<<"]"<<endl;}cout<<"]"<<endl;}
template<class T>void printt(pair<T,T> myPair){cout<<": { "<<myPair.ff<<" "<<myPair.ss<<" }"<<endl;}
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

 // Minimum Falling Path Sum II
// https://leetcode.com/problems/minimum-falling-path-sum-ii/

int minFallingPathSum1(vector<vector<int>>& grid, int i, int j, int n, vvi &dp) {
    if(i == n){
        return 0;
    }

    if(dp[i][j]  != -1)return dp[i][j];
    int mini = 1e9;
    for(int k = 0; k < n; k++){
        if(k != j){ 
            int sol = minFallingPathSum1(grid,i+1,k,n,dp) + grid[i][j];
            mini = min(mini,sol);
        }
    }
    return dp[i][j] = mini;
}

int minFallingPathSum(vector<vector<int>>& matrix) {
    int n = matrix.size();
    if(n == 1){return matrix[0][0];}
    int ans = 1e9;
    for(int i = 0; i < n; i++){
        vvi dp(n,vi(n,-1));
        int sol = minFallingPathSum1(matrix,0,i,n,dp);
        ans = min(ans,sol);
    }
    return ans;
}

//tabulation
int minFallingPathSum2(vector<vector<int>>& grid) {
    int n = grid.size();
    vvi dp(n+1,vi(n,-1));

    for(int i = 0; i < n; i++){
        dp[n][i] = 0;
    }

    for(int i = n-1; i>=0; i--){
        for(int j = 0; j < n; j++){
            int mini = 1e9;
            for(int k = 0; k < n; k++){
                if(k != j){ 
                    int sol = dp[i+1][k] + grid[i][j];
                    mini = min(mini,sol);
                }
            }
            dp[i][j] = mini;
        }
    }
    int ans = INT_MAX;
    for(int i = 0; i < n; i++){
        ans = min(ans,dp[0][i]);
    }
    return ans;
}


int main(){
    // vvi matrix = {
    //     {1,99,99},
    //     {0,2,1},
    //     {99,99,4}
    // };
    vvi matrix = {{7}
                };
    cout<<minFallingPathSum2(matrix)<<endl;
    // vvi matrix = {{1,2,3},{4,5,6},{7,8,9}};
    // vvi matrix = {{7}};
    // cout<<minFallingPathSum_T(matrix)<<endl;
}



